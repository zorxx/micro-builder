/*
	The hello world demo
*/
#include <stdint.h>
#include <sys/types.h>
#include "esp_common.h"
#include "uart.h"

#define DELAY 1000 /* milliseconds */

LOCAL os_timer_t hello_timer;
LOCAL uint32_t counter = 0;

LOCAL void ICACHE_FLASH_ATTR hello_cb(void *arg)
{
    ets_uart_printf("Hello World %lu!\r\n", counter);
    ++counter;
}

void user_init(void)
{
    // Configure the UART
    uart_div_modify(0, UART_CLK_FREQ / 115200);

    // Set up a timer to send the message
    os_timer_disarm(&hello_timer);
    os_timer_setfn(&hello_timer, (os_timer_func_t *)hello_cb, (void *)0);
    os_timer_arm(&hello_timer, DELAY, 1);
}
