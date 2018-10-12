/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file arduino.cpp
 *  \brief zboot control panel, mongoose web server implementation 
 */
#include "mongoose.h"
#include "zboot_cpanel.h"
#include "platform.h"

#define MAX_ARGS 20

static struct mg_mgr mgr;
static struct mg_connection *conn;

static void mg_ev_handler(struct mg_connection *nc, int ev, void *ev_data);
static void mg_HandleCGI(struct mg_connection *nc, int ev, void *ev_data);

static char *memdupstr(const char *mem, ssize_t len)
{
   char *dup = (char *) malloc(len + 1);
   if(NULL != dup)
   {
      memcpy(dup, mem, len);
      dup[len] = '\0';
   }
   return dup;
}

/* ----------------------------------------------------------------------------------------
 * Exported Functions
 */ 

void platform_http_send(uint16_t code, const char *content_type, const char *content, void *cookie)
{
   struct mg_connection *ng = (struct mg_connection *) cookie;
   int content_length = strlen(content) + 1;
   char *header = (char *) malloc(strlen(content_type) + 20);

   sprintf(header, "Content-Type: %s", content_type);
   mg_send_head(ng, code, content_length, header);
   mg_send(ng, content, content_length); 

   free(header);
}

void zboot_cpanel_init(void)
{
   char port[10];

   mg_mgr_init(&mgr, NULL);
   snprintf(port, sizeof(port), "%u",  ZBOOT_CPANEL_TCP_PORT);
   conn = mg_bind(&mgr, port, mg_ev_handler);
   mg_set_protocol_http_websocket(conn);
}

void zboot_cpanel_loop(void)
{
   mg_mgr_poll(&mgr, 1000);
}

/* ----------------------------------------------------------------------------------------
 * Private Functions 
 */ 

static void mg_ev_handler(struct mg_connection *nc, int ev, void *ev_data)
{
   struct mbuf *io = &nc->recv_mbuf;

   DebugMessage("%s: event %d", __func__, ev);
   switch(ev)
   {  
      case MG_EV_HTTP_REQUEST:
      {
         struct http_message *hm = (struct http_message *) ev_data;
         char *uri = (char *) malloc(hm->uri.len + 1);
         if(NULL != uri)
         {
            memcpy(uri, hm->uri.p, hm->uri.len);
            uri[hm->uri.len] = '\0';
            DebugMessage("%s: URI %s", __func__, uri);
            if(strcmp(uri, "/op.html") == 0)
               mg_HandleCGI(nc, ev, ev_data);
            else
               HandleLinkedFile(uri, nc);
            free(uri);
         }
         mbuf_remove(io, io->len);      // Discard data from recv buffer
         break;
      }

      case MG_EV_HTTP_PART_BEGIN:
      {
         struct mg_http_multipart_part *mp = (struct mg_http_multipart_part *) ev_data;
         DebugMessage("%s: Begin upload %s", __func__, mp->file_name);
         HandleImageUploadStart(mp->file_name);
         break;
      }

      case MG_EV_HTTP_PART_DATA:
      {
         struct mg_http_multipart_part *mp = (struct mg_http_multipart_part *) ev_data;
         DebugMessage("%s: Upload data %s, length %u", __func__, mp->file_name, mp->data.len);
         HandleImageUploadWrite(mp->file_name, (const uint8_t *) mp->data.p, mp->data.len);
         break;
      }

      case MG_EV_HTTP_PART_END:
      {
         struct mg_http_multipart_part *mp = (struct mg_http_multipart_part *) ev_data;
         DebugMessage("%s: End upload %s", __func__, mp->file_name);
         HandleImageUploadEnd(mp->file_name);
         mg_send_head(nc, 303, 0, "Location: /");
         break;
      }

      default:
         break;
   }
}

static void mg_HandleCGI(struct mg_connection *nc, int ev, void *ev_data)
{
   struct http_message *hm = (struct http_message *) ev_data;
   const char *arg_names[MAX_ARGS];
   const char *arg_values[MAX_ARGS];
   char *uri, *query, *str, *end;
   uint32_t i, arg_count = 0; 
   bool done = false;

   uri = memdupstr(hm->uri.p, hm->uri.len);
   query = memdupstr(hm->query_string.p, hm->query_string.len);

   DebugMessage("%s: uri %s, query %s\n", __func__, uri, query);

   str = query;
   while(!done)
   {
      end = strchr(str, '=');
      if(NULL == end)
      {
         arg_names[arg_count] = strdup(str);
         arg_values[arg_count] = strdup("");
         done = true;
      }
      else
      {
         arg_names[arg_count] = memdupstr(str, end - str);

         str = end + 1;
         end = strchr(str, '&');
         if(NULL == end)
         {
            arg_values[arg_count] = strdup(str);
            done = true;
         }
         else
         {
            arg_values[arg_count] = memdupstr(str, end - str);
            str = end + 1;
         }
      }

      DebugMessage("%s: %u name=%s, value=%s\n", __func__, arg_count, arg_names[arg_count],
         arg_values[arg_count]);
      ++arg_count;
   }

   HandleCGI(uri, arg_count, arg_names, arg_values, nc);
   for(i = 0; i < arg_count; ++i)
   {
      free((void*)arg_names[i]);
      free((void*)arg_values[i]);
   }

   free(query);
   free(uri);
}

/* ----------------------------------------------------------------------------------------
 * ESP Functons 
 */ 
#include "esp_log.h"

#if defined(DEBUG)
void DebugMessage(const char *format, ...)
{
   char message[150];
   va_list arglist;
   va_start(arglist, format);
   vsnprintf(message, sizeof(message), format, arglist);
   va_end(arglist);
   ESP_LOGI("zboot_cpanel", message);
}
#endif

void platform_system_restart(void)
{
   esp_restart();
}
