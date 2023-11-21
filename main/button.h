#pragma once

#include "driver/gpio.h"

class Button
{
public:
    Button(gpio_num_t pin) : pin(pin)
    {
        gpio_reset_pin(pin);
        gpio_set_direction(pin, GPIO_MODE_INPUT);
        gpio_set_pull_mode(pin, GPIO_PULLUP_ONLY);
    }

    bool isPressed()
    {
        return gpio_get_level(pin) == 0;
    }
    bool isNotPressed(){
        return gpio_get_level(pin) == 1;
    }

private:
    gpio_num_t pin;
};