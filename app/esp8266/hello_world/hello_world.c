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
	uart_init(BIT_RATE_115200, BIT_RATE_115200);
	// Set up a timer to send the message
	// os_timer_disarm(ETSTimer *ptimer)
	os_timer_disarm(&hello_timer);
	// os_timer_setfn(ETSTimer *ptimer, ETSTimerFunc *pfunction, void *parg)
	os_timer_setfn(&hello_timer, (os_timer_func_t *)hello_cb, (void *)0);
	// void os_timer_arm(ETSTimer *ptimer,uint32_t milliseconds, bool repeat_flag)
	os_timer_arm(&hello_timer, DELAY, 1);
}