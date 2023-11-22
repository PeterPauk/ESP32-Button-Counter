#pragma once

#include "driver/gpio.h"

class Button
{
    public:
        Button(gpio_num_t pin);
        bool isPressed();

    private:
        gpio_num_t pin;
};