#include "display.h"

SevenSegmentDisplay::SevenSegmentDisplay(gpio_num_t a, gpio_num_t b, gpio_num_t c,
                                         gpio_num_t d, gpio_num_t e, gpio_num_t f, gpio_num_t g)
    : a(a), b(b), c(c), d(d), e(e), f(f), g(g)
{
    gpio_num_t pins[] = {a, b, c, d, e, f, g};

    for (auto pin : pins){
        gpio_reset_pin(pin);
        gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    }
}

void SevenSegmentDisplay::setGpioLevels(int a, int b, int c, int d, int e, int f, int g)
{
    gpio_set_level(this->a, a);
    gpio_set_level(this->b, b);
    gpio_set_level(this->c, c);
    gpio_set_level(this->d, d);
    gpio_set_level(this->e, e);
    gpio_set_level(this->f, f);
    gpio_set_level(this->g, g);
}