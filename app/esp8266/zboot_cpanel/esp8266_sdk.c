#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "lwip/sockets.h"
#include "wifi_settings.h"
#include "zboot_cpanel.h"

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)

/* FreeRTOS event group to signal when we are connected & ready to make a request */
static EventGroupHandle_t wifi_event_group;

/* The event group allows multiple bits for each event,
   but we only care about one event - are we connected
   to the AP with an IP? */
#define CONNECTED_BIT (1>>0)

static const char *TAG = "zboot_cpanel";

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        /* This is a workaround as ESP32 WiFi libs don't currently
           auto-reassociate. */
        esp_wifi_connect();
        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
        break;
    default:
        break;
    }
    return ESP_OK;
}

static void initialise_wifi(void)
{
    tcpip_adapter_init();
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    wifi_config_t wifi_config;
    strcpy((char *) wifi_config.sta.ssid, STR(AP_SSID));
    strcpy((char *) wifi_config.sta.password, STR(AP_PASSWORD));
    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
}

static void test_task(void *pvParameters)
{
   unsigned long iteration = 0;

   for(;;) 
   {
      xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, false, true, portMAX_DELAY);
      ESP_LOGI(TAG, "Iteration: %lu", iteration);
      vTaskDelay(10000 / portTICK_PERIOD_MS);
      ++iteration;
    }
}

static void zboot_cpanel_task(void *pvParameters)
{
    zboot_cpanel_init();
    for(;;)
       zboot_cpanel_loop();
}

void app_main()
{
    initialise_wifi();
    xTaskCreate(&test_task, "test", 4096, NULL, 5, NULL);
    xTaskCreate(&zboot_cpanel_task, "zboot_cpanel", 4096, NULL, 5, NULL);
}
