#pragma once

#include "driver/gpio.h"

class SevenSegmentDisplay
{
public:
    SevenSegmentDisplay(gpio_num_t a, gpio_num_t b, gpio_num_t c,
                        gpio_num_t d, gpio_num_t e, gpio_num_t f, gpio_num_t g);
    void setGpioLevels(int a, int b, int c, int d, int e, int f, int g);

private:
    gpio_num_t a, b, c, d, e, f, g;
};