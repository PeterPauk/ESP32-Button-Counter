#pragma once

#include "driver/gpio.h"

class SevenSegmentDisplay
{
public:
    SevenSegmentDisplay(gpio_num_t a, gpio_num_t b, gpio_num_t c,
                        gpio_num_t d, gpio_num_t e, gpio_num_t f, gpio_num_t g)
        : a(a), b(b), c(c), d(d), e(e), f(f), g(g)
    {
        gpio_reset_pin(a);
        gpio_reset_pin(b);
        gpio_reset_pin(c);
        gpio_reset_pin(d);
        gpio_reset_pin(e);
        gpio_reset_pin(f);
        gpio_reset_pin(g);

        gpio_set_direction(a, GPIO_MODE_OUTPUT);
        gpio_set_direction(b, GPIO_MODE_OUTPUT);
        gpio_set_direction(c, GPIO_MODE_OUTPUT);
        gpio_set_direction(d, GPIO_MODE_OUTPUT);
        gpio_set_direction(e, GPIO_MODE_OUTPUT);
        gpio_set_direction(f, GPIO_MODE_OUTPUT);
        gpio_set_direction(g, GPIO_MODE_OUTPUT);
    }

    //Destructor
    ~SevenSegmentDisplay()
    {
        gpio_reset_pin(a);
        gpio_reset_pin(b);
        gpio_reset_pin(c);
        gpio_reset_pin(d);
        gpio_reset_pin(e);
        gpio_reset_pin(f);
        gpio_reset_pin(g);
    }

    void setGpioLevels(int a, int b, int c, int d, int e, int f, int g)
    {
        gpio_set_level(this->a, a);
        gpio_set_level(this->b, b);
        gpio_set_level(this->c, c);
        gpio_set_level(this->d, d);
        gpio_set_level(this->e, e);
        gpio_set_level(this->f, f);
        gpio_set_level(this->g, g);
    }

private:
    gpio_num_t a, b, c, d, e, f, g;
};