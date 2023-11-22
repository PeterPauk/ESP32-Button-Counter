#pragma once

#include "driver/gpio.h"

class Led
{
public:
    Led(gpio_num_t pin);
    void ledOn();
    void ledOff();

private:
    gpio_num_t pin;
};