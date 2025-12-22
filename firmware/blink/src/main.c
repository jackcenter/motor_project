#include "gpio.h"

#define GPIOA_BASE      0x48000000UL
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define GPIOA_BSRR      (*(volatile uint32_t *)(GPIOA_BASE + 0x18))
#define RCC_BASE        0x40021000UL
#define RCC_AHBENR      (*(volatile uint32_t *)(RCC_BASE + 0x14))

static void dumb_delay(volatile uint32_t count)
{
    while (count--) __asm volatile("nop");
}

int main(void)
{
    // Enable GPIOA clock
    RCC_AHBENR |= (1 << 17);

    Gpio led = {
        .MODER = &GPIOA_MODER,
        .ODR   = &GPIOA_ODR,
        .BSRR  = &GPIOA_BSRR,
        .pin   = 5
    };

    gpio_init_output(&led);

    while (1) {
        gpio_toggle(&led);
        dumb_delay(800000);
    }
}
