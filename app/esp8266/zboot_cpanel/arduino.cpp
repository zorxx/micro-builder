/* Copyright 2018 Zorxx Software. All rights reserved. */
#include <ESP8266WiFi.h>
#include "zboot_cpanel.h"
#include "wifi_settings.h"

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)

#define SERIAL_BAUD_RATE (115200)
#define SerialDebug(x) Serial.println(x)

static bool ip_displayed = false;

void setup()
{
   String local_mac_string = "";
   uint8_t mac_address[WL_MAC_ADDR_LENGTH];
   String message;

   Serial.begin(SERIAL_BAUD_RATE);
   SerialDebug("Start\r\n");

   WiFi.macAddress(mac_address);
   for(uint32_t idx = 0; idx < WL_MAC_ADDR_LENGTH; ++idx)
   {
      if(idx > 0)
         local_mac_string += ":";
      local_mac_string += String(mac_address[idx], HEX);
   }
   message = "Local MAC Address: ";
   message += local_mac_string;
   message += "\r\n";
   SerialDebug(message);
  
   WiFi.mode(WIFI_STA);
   WiFi.begin(STR(AP_SSID), STR(AP_PASSWORD));
   if(WiFi.status() != WL_CONNECTED)
   {
      delay(500);
      SerialDebug(".");
   }
   SerialDebug("Waiting for connection...\r\n");

   zboot_cpanel_init();
}

void loop()
{
   if(!ip_displayed)
   {
      uint32_t ip = WiFi.localIP();
      if(ip != 0)
      {
         ip_displayed = true;
         String message = "\r\nConnected to ";
         message += STR(AP_SSID);
         message += "\r\nIP address: ";
         message += ((uint8_t *) &ip)[0];
         message += ".";
         message += ((uint8_t *) &ip)[1];
         message += ".";
         message += ((uint8_t *) &ip)[2];
         message += ".";
         message += ((uint8_t *) &ip)[3];
         message += "\r\n";
         SerialDebug(message);
      }
   }

   zboot_cpanel_loop();
}
