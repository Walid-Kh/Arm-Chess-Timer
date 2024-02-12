#ifndef EXTERNAL_INTERRUPTS_H
#define EXTERNAL_INTERRUPTS_H

#include "std_types.h"
#include "gpio.h"

static void (*external_interrupt0_callback)     (void) = NULL;
static void (*external_interrupt1_callback)     (void) = NULL;
static void (*external_interrupt2_callback)     (void) = NULL;
static void (*external_interrupt3_callback)     (void) = NULL;
static void (*external_interrupt4_callback)     (void) = NULL;
static void (*external_interrupt5_callback)     (void) = NULL;
static void (*external_interrupt6_callback)     (void) = NULL;
static void (*external_interrupt7_callback)     (void) = NULL;
static void (*external_interrupt8_callback)     (void) = NULL;
static void (*external_interrupt9_callback)     (void) = NULL;
static void (*external_interrupt10_15_callback) (void) = NULL;

typedef enum
{
    EXTERNAL_INTERRUPT0 = 0,
    EXTERNAL_INTERRUPT1,
    EXTERNAL_INTERRUPT2,
    EXTERNAL_INTERRUPT3,
    EXTERNAL_INTERRUPT4,
    EXTERNAL_INTERRUPT5, 
    EXTERNAL_INTERRUPT6,
    EXTERNAL_INTERRUPT7,
    EXTERNAL_INTERRUPT8,
    EXTERNAL_INTERRUPT9,
    EXTERNAL_INTERRUPT10_15,
} external_interrupt;

typedef enum
{
    FALLING_EDGE,
    RISING_EDGE,
} external_interrupt_trigger;

void external_interrupt_init();
void external_interrupt_enable(external_interrupt interrupt, external_interrupt_trigger trigger, gpio_port port, u8 pin);
void external_interrupt_disable(external_interrupt interrupt);
void external_interrupt_attach_callback(external_interrupt interrupt, void (*callback)(void));

void exti0_isr(void);
void exti1_isr(void);
void exti2_isr(void);
void exti3_isr(void);
void exti4_isr(void);
void exti9_5_isr(void);
void exti15_10_isr(void);

#endif // EXTERNAL_INTERRUPTS_H