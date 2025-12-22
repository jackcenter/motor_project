#include "gpio.h"

void gpio_init_output(Gpio *gpio)
{
    *(gpio->MODER) &= ~(3U << (gpio->pin * 2));
    *(gpio->MODER) |=  (1U << (gpio->pin * 2));
}

void gpio_write(Gpio *gpio, int value)
{
    if (value)
        *(gpio->BSRR) = (1U << gpio->pin);
    else
        *(gpio->BSRR) = (1U << (gpio->pin + 16));
}

void gpio_toggle(Gpio *gpio)
{
    *(gpio->ODR) ^= (1U << gpio->pin);
}
