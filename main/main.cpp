#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "display.h"
#include "button.h"


static const char *TAG = "example";

int buttonPushCounter = 0;
int lastButtonState = 1;
bool isZero = true;

Button button(GPIO_NUM_19);

SevenSegmentDisplay display(GPIO_NUM_17, GPIO_NUM_16, GPIO_NUM_4,
                            GPIO_NUM_5, GPIO_NUM_23, GPIO_NUM_21, GPIO_NUM_22);

void setGpioAndCounter(int state)
{
    const int gpioLevels[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0}, 
        {1, 1, 0, 1, 1, 0, 1}, 
        {1, 1, 1, 1, 0, 0, 1}, 
        {0, 1, 1, 0, 0, 1, 1}, 
        {1, 0, 1, 1, 0, 1, 1}, 
        {1, 0, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 0, 0, 1, 1}  
    };
    if (state >= 0 && state <= 9) {
        display.setGpioLevels(
            gpioLevels[state][0],
            gpioLevels[state][1],
            gpioLevels[state][2],
            gpioLevels[state][3],
            gpioLevels[state][4],
            gpioLevels[state][5],
            gpioLevels[state][6]
        );
}
}
extern "C"
{
    void app_main(void)
    {
        while (1)
        {
            vTaskDelay(50 / portTICK_PERIOD_MS);

            if (button.isNotPressed() && isZero)
            {
                setGpioAndCounter(0);
                isZero = false;
            }
            if (button.isPressed() && lastButtonState == 0)
            {
                buttonPushCounter = (buttonPushCounter + 1) % 10;
                setGpioAndCounter(buttonPushCounter);
                lastButtonState = 1;
            }
            if (button.isNotPressed())
            {
                lastButtonState = 0;
            }
            if (button.isPressed() && lastButtonState == 0 && buttonPushCounter == 9)
            {
                setGpioAndCounter(0);
                isZero = true;
            }
        }
    }
}
