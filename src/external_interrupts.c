#include "external_interrupts.h"
#include "reg.h"
#include "bit_operations.h"

void external_interrupt_init()
{
    // Enable AFIO clock
    SET_BIT(*RCC_ABP2ENR, RCC_AFIOEN);
}

void external_interrupt_enable(external_interrupt interrupt, external_interrupt_trigger trigger, gpio_port port, u8 pin)
{
    u32 *AFIO_CTRL;
    u32 *NVIC ;
    u16 NVIC_bit = 0;
    u8 res_pin = 0;

    if (pin <= 3)
    {
        AFIO_CTRL = AFIO_EXTICR1;
        res_pin = pin;
    }
    else if (pin <= 7)
    {
        AFIO_CTRL = AFIO_EXTICR2;
        res_pin = pin - 4;
    }
    else if (pin <= 11)
    {
        AFIO_CTRL = AFIO_EXTICR3;
        res_pin = pin - 8;
    }
    else if (pin <= 15)
    {
        AFIO_CTRL = AFIO_EXTICR4;
        res_pin = pin - 12;
    }



    switch (port)
    {
        case GPIO_PORT_A:
            *AFIO_CTRL &= ~(0b1111 << (res_pin * 4));
            break;
        case GPIO_PORT_B:
            *AFIO_CTRL &= ~(0b1111 << (res_pin * 4));
            *AFIO_CTRL |= (0b0001 << (res_pin * 4));
            break;
        case GPIO_PORT_C:
            *AFIO_CTRL &= ~(0b1111 << (res_pin * 4));
            *AFIO_CTRL |= (0b0010 << (res_pin * 4));
            break;
    }

    switch (interrupt)
    {
        case EXTERNAL_INTERRUPT0:
            NVIC = NVIC_ISER0;
            NVIC_bit = 6;
            break;
        case EXTERNAL_INTERRUPT1:
            NVIC = NVIC_ISER0;
            NVIC_bit = 7;
            break;
        case EXTERNAL_INTERRUPT2:
            NVIC = NVIC_ISER0;
            NVIC_bit = 8;
            break;
        case EXTERNAL_INTERRUPT3:
            NVIC = NVIC_ISER0;
            NVIC_bit = 9;
            break;
        case EXTERNAL_INTERRUPT4:
            NVIC = NVIC_ISER0;
            NVIC_bit = 10;
            break;
        case EXTERNAL_INTERRUPT5:
        case EXTERNAL_INTERRUPT6:
        case EXTERNAL_INTERRUPT7:
        case EXTERNAL_INTERRUPT8:
        case EXTERNAL_INTERRUPT9:
            NVIC = NVIC_ISER0;
            NVIC_bit = 23;
            break;
        case EXTERNAL_INTERRUPT10_15:
            NVIC = NVIC_ISER1;
            NVIC_bit = 8; 
            break;
    }
    SET_BIT(*NVIC, NVIC_bit);

    // Set the trigger
    switch (trigger)
    {
    case FALLING_EDGE:
        SET_BIT(*EXTI_FTSR, interrupt);
        break;
    case RISING_EDGE:
        SET_BIT(*EXTI_RTSR, interrupt);
        break;
    }

    // Enable event mask
    SET_BIT(*EXTI_EMR, interrupt);

    // Enable the interrupt
    SET_BIT(*EXTI_IMR, interrupt);
}

void external_interrupt_disable(external_interrupt interrupt)
{
    // Disable the interrupt
    CLEAR_BIT(*EXTI_IMR, interrupt);
    // Disable event mask
    CLEAR_BIT(*EXTI_EMR, interrupt);
}

void external_interrupt_attach_callback(external_interrupt interrupt, void (*callback)(void))
{
    switch (interrupt)
    {
    case EXTERNAL_INTERRUPT0:
        external_interrupt0_callback = callback;
        break;
    case EXTERNAL_INTERRUPT1:
        external_interrupt1_callback = callback;
        break;
    case EXTERNAL_INTERRUPT2:
        external_interrupt2_callback = callback;
        break;
    case EXTERNAL_INTERRUPT3:
        external_interrupt3_callback = callback;
        break;
    case EXTERNAL_INTERRUPT4:
        external_interrupt4_callback = callback;
        break;
    case EXTERNAL_INTERRUPT5:
        external_interrupt5_callback = callback;
        break;
    case EXTERNAL_INTERRUPT6:
        external_interrupt6_callback = callback;
        break;
    case EXTERNAL_INTERRUPT7:
        external_interrupt7_callback = callback;
        break;
    case EXTERNAL_INTERRUPT8:
        external_interrupt8_callback = callback;
        break;
    case EXTERNAL_INTERRUPT9:
        external_interrupt9_callback = callback;
        break;
    case EXTERNAL_INTERRUPT10_15:
        external_interrupt10_15_callback = callback;
        break;
    }
}


// static inline void check_for_debouncing(u8 interrupt){

// }


void exti0_isr(void)
{
    if (external_interrupt0_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 0);

        u32 iser = *NVIC_ISER0;
        // TODO: this for what ever reason is clearing all the interrupts 
        SET_BIT(*NVIC_ICER0, 6);

        // delay for debouncing
        u32 pin = (*AFIO_EXTICR1) & 0b1111;
        u32 pin_val = 0; 
        _delay_ms(1);

        switch (pin)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 0);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 0);
            break;
        case 2: 
            pin_val = GPIO_read_pin(GPIO_PORT_C, 0);
            break;
        }
        if (pin_val == 1)   
            external_interrupt0_callback();

        *NVIC_ISER0 = iser;
    }
}

void exti1_isr(void)
{
    if (external_interrupt1_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 1);
        u32 iser = *NVIC_ISER0;
        SET_BIT(*NVIC_ICER0, 7);

        u32 port = (*AFIO_EXTICR1) & (0b1111 <<  4);
        u32 pin_val = 0; 
        _delay_ms(1);

        switch (port)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 1);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 1);
            break;
        case 2: 
            pin_val = GPIO_read_pin(GPIO_PORT_C, 1);
            break;
        }
        if (pin_val == 1)   
            external_interrupt1_callback();


        *NVIC_ISER0 = iser;
        
    }
}



void exti3_isr(void)
{
    if (external_interrupt3_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 3);
        u32 iser = *NVIC_ISER0;

        SET_BIT(*NVIC_ICER0, 9);

        u32 pin = (*AFIO_EXTICR1) & (0b1111 <<  4*3);
        u32 pin_val = 0; 
        _delay_ms(1);

        switch (pin)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 3);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 3);
            break;
        case 2: 
            pin_val = GPIO_read_pin(GPIO_PORT_C, 3);
            break;
        }
        if (pin_val == 1)   
            external_interrupt3_callback();

        *NVIC_ISER0 = iser; 
    }
}

void exti2_isr(void)
{
    if (external_interrupt2_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 2);
        u32 iser = *NVIC_ISER0;
        SET_BIT(*NVIC_ICER0, 8);


        u32 pin = (*AFIO_EXTICR1) & (0b1111 <<  4*2);
        u32 pin_val = 0;
        _delay_ms(2);

        switch (pin)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 2);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 2);
            break;
        case 2:
            pin_val = GPIO_read_pin(GPIO_PORT_C, 2);
            break;
        }
        if (pin_val == 1)
            external_interrupt2_callback();

        *NVIC_ISER0 = iser;
    }
}

void exti4_isr(void)
{
    if (external_interrupt4_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 2);
        external_interrupt4_callback();
    }
}

void exti9_5_isr(void)
{
    u32 iser = *NVIC_ISER0;
    SET_BIT(*NVIC_ICER0, 23);
    if (external_interrupt5_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 5);
        u32 port = *AFIO_EXTICR2 & 0b1111;
        u32 pin_val = 0;
        _delay_ms(2);
        switch (port)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 5);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 5);
            break;
        case 2:
            pin_val = GPIO_read_pin(GPIO_PORT_C, 5);
            break;
        }
        if (pin_val == 1)
            external_interrupt5_callback();
    }
    else if (external_interrupt6_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 6);
        u32 port = *AFIO_EXTICR2 & (0b1111 << 4);
        port = port >> 4;
        u32 pin_val = 0;
        _delay_ms(2);
        switch (port)
        {
        case 0:
            pin_val = GPIO_read_pin(GPIO_PORT_A, 6);
            break;
        case 1:
            pin_val = GPIO_read_pin(GPIO_PORT_B, 6);
            break;
        case 2:
            pin_val = GPIO_read_pin(GPIO_PORT_C, 6);
            break;
        }
        if (pin_val == 1)
            external_interrupt6_callback();
    }
    else if (external_interrupt7_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 7);
        external_interrupt7_callback();
    }
    else if (external_interrupt8_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 8);
        external_interrupt8_callback();
    }
    else if (external_interrupt9_callback != NULL)
    {
        SET_BIT(*EXTI_PR, 9);
        external_interrupt9_callback();
    }
    *NVIC_ISER0 = iser;


}

void exti15_10_isr(void)
{
    if (external_interrupt10_15_callback != NULL)
    {
        external_interrupt10_15_callback();
    }
}
