/*
	The hello world demo
*/
#include <stdint.h>
#include <sys/types.h>
#include "esp_timer.h"
#include "esp_log.h"

#define DELAY 1000 /* milliseconds */

os_timer_t hello_timer;
uint32_t counter = 0;
static const char *TAG = "hello_world";

void hello_cb(void *arg)
{
    ESP_LOGI(TAG, "Hello world timer!");
    ++counter;
}

void app_main(void)
{
    // Set up a timer to send the message
    os_timer_disarm(&hello_timer);
    os_timer_setfn(&hello_timer, (os_timer_func_t *)hello_cb, (void *)0);
    os_timer_arm(&hello_timer, DELAY, 1);
}
