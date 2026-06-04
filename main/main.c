#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

typedef enum 
{
    STATE_INIT,
    STATE_AUTH,
    STATE_SUCCESS,
    STATE_ERROR
} system_state_t;

void system_machine(void *pvParameters)
{
    system_state_t current_state = STATE_INIT;

    while (1) 
    {
        switch (current_state) 
        {
            case STATE_INIT:
                // Initialize system components
                // If initialization is successful, transition to AUTH state
                current_state = STATE_AUTH;
                ESP_LOGI("STATE", "Current state: INIT");
                break;

            case STATE_AUTH:
                // Perform authentication
                // If authentication is successful, transition to SUCCESS state
                // If authentication fails, transition to ERROR state
                current_state = STATE_SUCCESS;
                ESP_LOGI("STATE", "Current state: INIT");
                break;

            case STATE_SUCCESS:
                // Handle successful authentication
                // Transition back to INIT state or perform other tasks
                current_state = STATE_INIT;
                ESP_LOGI("STATE", "Current state: INIT");
                break;

            case STATE_ERROR:
                // Handle authentication error
                // Transition back to INIT state or perform other tasks
                current_state = STATE_INIT;
                ESP_LOGI("STATE", "Current state: INIT");
                break;

            default:
                // Handle unexpected states
                current_state = STATE_INIT;
                break;
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Delay for a short period before next iteration
    }
}


void main (void)
{
    xTaskCreate(system_machine, "SystemMachine", 2048, NULL, 5, NULL);
    vTaskStartScheduler();
}