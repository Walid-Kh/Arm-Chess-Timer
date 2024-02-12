#include "gpio.h"
#include "bit_operations.h"
#include "reg.h"

void GPIO_init_port(gpio_port port)
{
    switch (port)
    {
    case GPIO_PORT_A:
        SET_BIT(*RCC_ABP2ENR, RCC_IOPAEN);
        break;
    case GPIO_PORT_B:
        SET_BIT(*RCC_ABP2ENR, RCC_IOPBEN);
        break;
    case GPIO_PORT_C:
        SET_BIT(*RCC_ABP2ENR, RCC_IOPCEN);
        break;
    default:
        return;
    }
}

void GPIO_set_pin_mode(gpio_port port, u8 pin, gpio_pin_mode mode)
{
    u32 *GPIO_CTRL;
    u32 *GPIO_ODR;
    u8 res_pin = 0;

    switch (port)
    {
    case GPIO_PORT_A:
        if (pin > GPIO_PORTA_MAX_PIN || pin < GPIO_PORTA_MIN_PIN)
            return;
        else
        {
            GPIO_ODR = GPIOA_ODR;
            if (pin <= 7)
            {
                // clear the 4 bits of the pin
                res_pin = pin;
                *GPIOA_CRL &= ~(0b1111 << (res_pin * 4));
                GPIO_CTRL = GPIOA_CRL;
            }
            else
            {
                // clear the 4 bits of the pin
                res_pin = pin - 8;
                *GPIOA_CRH &= ~(0b1111 << (res_pin * 4));
                GPIO_CTRL = GPIOA_CRH;
            }
        }
        break;
    case GPIO_PORT_B:
        if (pin > GPIO_PORTB_MAX_PIN || pin < GPIO_PORTB_MIN_PIN)
            return;
        else
        {
            GPIO_ODR = GPIOB_ODR;
            if (pin <= 7)
            {
                // clear the 4 bits of the pin
                res_pin = pin;
                *GPIOB_CRL &= ~(0b1111 << (pin * 4));
                GPIO_CTRL = GPIOB_CRL;
            }
            else
            {
                // clear the 4 bits of the pin
                res_pin = pin - 8;
                *GPIOB_CRH &= ~(0b1111 << ((pin - 8) * 4));
                GPIO_CTRL = GPIOB_CRH;
            }
        }
        break;
    case GPIO_PORT_C:
        if (pin > GPIO_PORTC_MAX_PIN || pin < GPIO_PORTC_MIN_PIN)
            return;
        else
        {
            GPIO_ODR = GPIOC_ODR;
            // clear the 4 bits of the pin
            res_pin = pin - 8;
            *GPIOC_CRH &= ~(0b1111 << ((pin - 8) * 4));
            GPIO_CTRL = GPIOC_CRH;
        }
        break;
    default:
        return;
    }

    switch (mode)
    {
    case GPIO_PIN_INPUT:
        *GPIO_CTRL |= 0b1000 << (res_pin * 4);
        CLEAR_BIT(*GPIO_ODR, pin);
        break;

    case GPIO_PIN_OUTPUT:
        *GPIO_CTRL |= 0b0001 << (res_pin * 4);
        break;
    }
}

void GPIO_set_port_mode(gpio_port port, gpio_port_mode port_mode)
{
    u32 *GPIO_CTL;
    u32 *GPIO_CTH;
    u32 *GPIO_ODR;

    switch (port)
    {
    case GPIO_PORT_A:
        GPIO_CTL = GPIOA_CRL;
        GPIO_CTH = GPIOA_CRH;
        GPIO_ODR = GPIOA_ODR;
        break;
    case GPIO_PORT_B:
        GPIO_CTL = GPIOB_CRL;
        GPIO_CTH = GPIOB_CRH;
        GPIO_ODR = GPIOA_ODR;

        break;
    case GPIO_PORT_C:
        GPIO_CTL = GPIOC_CRL;
        GPIO_CTH = GPIOC_CRH;
        GPIO_ODR = GPIOA_ODR;

        break;
    default:
        return;
    }

    switch (port_mode)
    {
    case GPIO_PORT_INPUT:
        *GPIO_CTH = 0x44444444;
        *GPIO_CTL = 0x44444444;
        *GPIO_ODR = 0x00000000;
        break;
    case GPIO_PORT_OUTPUT:
        *GPIO_CTH = 0x11111111;
        *GPIO_CTL = 0x11111111;
        break;
    }
}

void GPIO_write_pin(gpio_port port, u8 pin, u8 state)
{
    switch (port)
    {
    case GPIO_PORT_A:
        if (state)
            SET_BIT(*GPIOA_ODR, pin);
        else
            CLEAR_BIT(*GPIOA_ODR, pin);
        break;
    case GPIO_PORT_B:
        if (state)
            SET_BIT(*GPIOB_ODR, pin);
        else
            CLEAR_BIT(*GPIOB_ODR, pin);
        break;
    case GPIO_PORT_C:
        if (state)
            SET_BIT(*GPIOC_ODR, pin);
        else
            CLEAR_BIT(*GPIOC_ODR, pin);
        break;
    default:
        return;
    }
}

void GPIO_write_port(gpio_port port, u16 value)
{
    switch (port)
    {
    case GPIO_PORT_A:
        *GPIOA_ODR = value;
        break;
    case GPIO_PORT_B:
        *GPIOB_ODR = value;
        break;
    case GPIO_PORT_C:
        *GPIOC_ODR = value;
        break;
    default:
        return;
    }
}

void GPIO_toggle_pin(gpio_port port, u8 pin)
{
    switch (port)
    {
    case GPIO_PORT_A:
        TOGGLE_BIT(*GPIOA_ODR, pin);
        break;
    case GPIO_PORT_B:
        TOGGLE_BIT(*GPIOB_ODR, pin);
        break;
    case GPIO_PORT_C:
        TOGGLE_BIT(*GPIOC_ODR, pin);
        break;
    default:
        return;
    }
}

u8 GPIO_read_pin(gpio_port port, u8 pin)
{
    switch (port)
    {
    case GPIO_PORT_A:
        return READ_BIT(*GPIOA_IDR, pin) > 0;
    case GPIO_PORT_B:
        return READ_BIT(*GPIOB_IDR, pin) > 0;
    case GPIO_PORT_C:
        return READ_BIT(*GPIOC_IDR, pin) > 0;
    default:
        return 0;
    }
}
