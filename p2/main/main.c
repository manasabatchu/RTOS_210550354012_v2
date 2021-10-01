#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TaskHandle_t loc_handle;
TimerHandle_t pV_handle;
void *const pVTimerID;

void pV_timer_handler(TimerHandle_t xTimer)
{
    printf("Timer");
}

void TASK_1(void *data)
{
    while(1)
    {
    printf("first task\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
void TASK_2(void *data)
{
    while(1)
    {
    printf("second task\n");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

}
void TASK_3(void *data)
{
    
    while(1)
    {
    printf("third task\n");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
pV_handle = xTimerCreate( "Timer_PT",pdMS_TO_TICKS(10000),pdFALSE,pVTimerID,pV_timer_handler);
    xTimerStart(pV_handle,0);
}



void app_main(void)
{
    xTaskCreate(TASK_1,"task_1",2048,NULL,1,pV_handle);
    xTaskCreate(TASK_2,"task_2",2048,NULL,2,NULL);
    xTaskCreate(TASK_3,"task_3",2048,NULL,3,NULL);
}

