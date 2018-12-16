#include "string.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

static QueueHandle_t xQueue = NULL;
static void prvTask(void *pvParameters);

int main(void)
{
   xQueue = xQueueCreate(1, sizeof(unsigned long));

   if(xQueue != NULL)
   {
      xTaskCreate(prvTask, "Task", 512, 0, tskIDLE_PRIORITY+1, NULL); 
      vTaskStartScheduler();
   }

   for( ;; );
   return 0;
}

static void prvTask(void *pvParameters)
{
}

void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    for( ;; );
}

void vApplicationIdleHook(void)
{
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void) pcTaskName;
    (void) pxTask;
    for(;;);
}

void vApplicationTickHook(void)
{
}

