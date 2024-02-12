/*********************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the STM32F103(blue pill) ARM CORTEXT M3/M4 GPIO driver
 *
 * Author: Walid Khamees 
 *
 *********************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include "std_types.h"


#define GPIO_PORTA_MIN_PIN 0
#define GPIO_PORTA_MAX_PIN 15

#define GPIO_PORTB_MIN_PIN 0
#define GPIO_PORTB_MAX_PIN 15

#define GPIO_PORTC_MIN_PIN 13
#define GPIO_PORTC_MAX_PIN 15

/**
 * @brief This enum is used to select the port to which the pin belongs.
*/
typedef enum {
    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C,
} gpio_port;


/**
 * @brief This enum is used to set the mode of a pin to be either input or output.
*/
typedef enum {
    /// @brief The pin is set to input mode.
    GPIO_PIN_INPUT = 0,
    /// @brief The pin is set to output mode.
    GPIO_PIN_OUTPUT,
} gpio_pin_mode;

/**
 * @brief This enum is used to set the mode of a port to be either input or output.
*/
typedef enum {
    /// @brief The port is set to input mode.
    GPIO_PORT_INPUT, 
    /// @brief The port is set to output mode.
    GPIO_PORT_OUTPUT,
} gpio_port_mode;



void GPIO_init_port(gpio_port port);
/**
 * @brief This function is used to set the mode of a pin in a specific port
 * to be either input or output.
 * the default configuration for the pin is:
 * - the input mode selected is input pull down
 * - the output mode selected is push pull
 * 
 * @param port The port to which the pin belongs.
 * @param pin The pin number.
 * @param mode The mode to set (input or output).
 */
void GPIO_set_pin_mode(gpio_port port, u8 pin, gpio_pin_mode mode);

/**
 * @brief This function is used to set the mode of a port to be either input or output.
 * the default configuration for the port is:
 * - the input mode selected is input pull down
 * - the output mode selected is push pull
 * 
 * @param port The port to which the pin belongs.
 * @param port_mode The mode to set (input or output).
 */
void GPIO_set_port_mode(gpio_port port, gpio_port_mode port_mode);


/**
 * @brief This function is used to write a value to a specific pin in a specific port.
 * 
 * @param port The port to which the pin belongs.
 * @param pin The pin number.
 * @param state The value to write to the pin (0 or 1).
*/
void GPIO_write_pin(gpio_port port, u8 pin, u8 state);

/**
 * @brief This function is used to write a value to a specific port.
 * 
 * @param port The port to which the pin belongs.
 * @param value The value to write to the port.
*/
void GPIO_write_port(gpio_port port, u16 value);

/**
 * @brief This function is used to toggle the value of a specific pin in a specific port.
 * 
 * @param port The port to which the pin belongs.
 * @param pin The pin number.
*/
void GPIO_toggle_pin(gpio_port port, u8 pin);

/**
 * @brief This function is used to read the value of a specific pin in a specific port.
 * 
 * @param port The port to which the pin belongs.
 * @param pin The pin number.
 * @return The value of the pin (0 or 1).
*/
u8 GPIO_read_pin(gpio_port port, u8 pin);





#endif // GPIO_H