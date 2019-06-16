// Copyright 2018-2019 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>

#include "sdkconfig.h"
#include "zboot-api.h"
#include "nvs_flash.h"
#include "esp_image_format.h"
#include "esp_newlib.h"
#include "esp_heap_caps_init.h"
#include "esp_partition.h"

#include "FreeRTOS.h"
#include "task.h"

extern void user_init_entry(void *param);

extern int _bss_start, _bss_end;

static void partition_init(void)
{
   char buffer[0x100];
   esp_partition_info_t* it = (esp_partition_info_t *) buffer;

   if(spi_flash_read(ESP_PARTITION_TABLE_ADDR, buffer, sizeof(buffer)) != ESP_OK)
   {
   }
   else if(it->magic == ESP_PARTITION_MAGIC)
   {
   }
   else
   {
      ets_printf("Initializing partitions\r\n");
 
      it->magic = ESP_PARTITION_MAGIC;
      it->pos.offset = 0x9000;
      it->pos.size = 0x6000;
      it->type = PART_TYPE_DATA;
      it->flags = 0;
      it->subtype = PART_SUBTYPE_DATA_WIFI;
      strncpy((char *) it->label, "nvs", sizeof(it->label));
      ++it;

      it->magic = ESP_PARTITION_MAGIC;
      it->pos.offset = 0xf000;
      it->pos.size = 0x1000;
      it->type = PART_TYPE_DATA;
      it->flags = 0;
      it->subtype = PART_SUBTYPE_DATA_RF;
      strncpy((char *) it->label, "phy_init", sizeof(it->label));
      ++it;

      it->magic = ESP_PARTITION_MAGIC;
      it->type = PART_TYPE_END;
      it->subtype = PART_SUBTYPE_END;

      spi_flash_erase_sector(ESP_PARTITION_TABLE_ADDR / SPI_FLASH_SEC_SIZE);
      spi_flash_write(ESP_PARTITION_TABLE_ADDR, buffer, sizeof(buffer));
   }
}

extern void call_user_start(void);

void call_user_start_zboot(void)
{
    int *p;

    partition_init();
    zboot_api_init();

    /* clear bss data */
    for (p = &_bss_start; p < &_bss_end; p++)
        *p = 0;

    __asm__ __volatile__(
        "rsil       a2, 2\n"
        "movi       a1, _chip_interrupt_tmp\n"
        : : :"memory");

    heap_caps_init();

    esp_newlib_init();
    assert(xTaskCreate(user_init_entry, "uiT", CONFIG_MAIN_TASK_STACK_SIZE, NULL, configMAX_PRIORITIES, NULL) == pdPASS);

    vTaskStartScheduler();
}

extern void lwip_fcntl(int s, int cmd, int val);

void fcntl(int s, int cmd, int val)
{
   lwip_fcntl(s, cmd, val);
}
