/**
 * @file gpio.h
 * @brief Declaration of the Gpio type and asssociated functions.
 * 
 * @author Jack Center
 * @date December 26th, 2025
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/**
 * @struct Gpio
 * @brief Holds resgisters associated with a GPIO pin.
 */
typedef struct {
    volatile uint32_t *MODER;
    volatile uint32_t *ODR;
    volatile uint32_t *BSRR;
    uint8_t pin;
} Gpio;

/**
 * @brief Initializes the `gpio` as an output.
 */
void gpio_init_output(Gpio *gpio);

/**
 * @brief Writes the `value` to the `gpio`.
 */
void gpio_write(Gpio *gpio, int value);

/**
 * @brief Toggles the output of `gpio`.
 */
void gpio_toggle(Gpio *gpio);

#endif  // GPIO_H
