#include "led.h"

Led::Led(gpio_num_t pin): pin(pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void Led::ledOn()
{
    gpio_set_level(pin, 1);
}

void Led::ledOff()
{
    gpio_set_level(pin, 0);
}