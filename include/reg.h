/*********************************************************************************
 *
 * Module: registers
 *
 * File Name: reg.h
 *
 * Description: Header file for the STM32F103(blue pill) ARM CORTEXT M3/M4 Registers
 *
 * Author: Walid Khamees 
 *
 *********************************************************************************/

#ifndef REG_H
#define REG_H
#include "std_types.h"



// ==================== Timers ====================


#define TIM2_BASE (0x40000000)

#define TIM2_CR1   ((u32 *)(TIM2_BASE + 0x00))
#define TIM2_CR1_CEN  (0)
#define TIM2_CR1_UDIS (1)
#define TIM2_CR1_URS  (2)
#define TIM2_CR1_OPM  (3)
#define TIM2_CR1_DIR  (4)
#define TIM2_CR1_ARPE (7)


#define TIM2_CR2   ((u32 *)(TIM2_BASE + 0x04))
#define TIM2_SMCR  ((u32 *)(TIM2_BASE + 0x08))
#define TIM2_DIER  ((u32 *)(TIM2_BASE + 0x0C))
#define TIM2_SR    ((u32 *)(TIM2_BASE + 0x10))
#define TIM2_EGR   ((u32 *)(TIM2_BASE + 0x14))
#define TIM2_CCMR1 ((u32 *)(TIM2_BASE + 0x18))
#define TIM2_CCMR2 ((u32 *)(TIM2_BASE + 0x1C))
#define TIM2_CCER  ((u32 *)(TIM2_BASE + 0x20))
#define TIM2_CNT   ((u32 *)(TIM2_BASE + 0x24))
#define TIM2_PSC   ((u32 *)(TIM2_BASE + 0x28))
#define TIM2_ARR   ((u32 *)(TIM2_BASE + 0x2C))
#define TIM2_CCR1  ((u32 *)(TIM2_BASE + 0x34))
#define TIM2_CCR2  ((u32 *)(TIM2_BASE + 0x38))
#define TIM2_CCR3  ((u32 *)(TIM2_BASE + 0x3C))
#define TIM2_CCR4  ((u32 *)(TIM2_BASE + 0x40))
#define TIM2_DCR   ((u32 *)(TIM2_BASE + 0x48))
#define TIM2_DMAR  ((u32 *)(TIM2_BASE + 0x4C))



// ==================== NVIC ====================

#define NVIC_BASE (0xE000E100)

#define NVIC_ISER0 ((u32 *)(NVIC_BASE + 0x00))
#define NVIC_ISER1 ((u32 *)(NVIC_BASE + 0x04))
#define NVIC_ISER2 ((u32 *)(NVIC_BASE + 0x08))
#define NVIC_ISER3 ((u32 *)(NVIC_BASE + 0x0C))
#define NVIC_ISER4 ((u32 *)(NVIC_BASE + 0x10))
#define NVIC_ISER5 ((u32 *)(NVIC_BASE + 0x14))
#define NVIC_ISER6 ((u32 *)(NVIC_BASE + 0x18))
#define NVIC_ISER7 ((u32 *)(NVIC_BASE + 0x1C))

#define NVIC_ICER0 ((u32 *)(NVIC_BASE + 0x80))
#define NVIC_ICER1 ((u32 *)(NVIC_BASE + 0x84))
#define NVIC_ICER2 ((u32 *)(NVIC_BASE + 0x88))
#define NVIC_ICER3 ((u32 *)(NVIC_BASE + 0x8C))
#define NVIC_ICER4 ((u32 *)(NVIC_BASE + 0x90))
#define NVIC_ICER5 ((u32 *)(NVIC_BASE + 0x94))
#define NVIC_ICER6 ((u32 *)(NVIC_BASE + 0x98))
#define NVIC_ICER7 ((u32 *)(NVIC_BASE + 0x9C))

#define NVIC_ISPR0 ((u32 *)(NVIC_BASE + 0x100))
#define NVIC_ISPR1 ((u32 *)(NVIC_BASE + 0x104))
#define NVIC_ISPR2 ((u32 *)(NVIC_BASE + 0x108))
#define NVIC_ISPR3 ((u32 *)(NVIC_BASE + 0x10C))
#define NVIC_ISPR4 ((u32 *)(NVIC_BASE + 0x110))
#define NVIC_ISPR5 ((u32 *)(NVIC_BASE + 0x114))
#define NVIC_ISPR6 ((u32 *)(NVIC_BASE + 0x118))
#define NVIC_ISPR7 ((u32 *)(NVIC_BASE + 0x11C))

#define NVIC_ICPR0 ((u32 *)(NVIC_BASE + 0x180))
#define NVIC_ICPR1 ((u32 *)(NVIC_BASE + 0x184))
#define NVIC_ICPR2 ((u32 *)(NVIC_BASE + 0x188))
#define NVIC_ICPR3 ((u32 *)(NVIC_BASE + 0x18C))
#define NVIC_ICPR4 ((u32 *)(NVIC_BASE + 0x190))
#define NVIC_ICPR5 ((u32 *)(NVIC_BASE + 0x194))
#define NVIC_ICPR6 ((u32 *)(NVIC_BASE + 0x198))
#define NVIC_ICPR7 ((u32 *)(NVIC_BASE + 0x19C))

#define NVIC_IABR0 ((u32 *)(NVIC_BASE + 0x200))
#define NVIC_IABR1 ((u32 *)(NVIC_BASE + 0x204))
#define NVIC_IABR2 ((u32 *)(NVIC_BASE + 0x208))
#define NVIC_IABR3 ((u32 *)(NVIC_BASE + 0x20C))
#define NVIC_IABR4 ((u32 *)(NVIC_BASE + 0x210))
#define NVIC_IABR5 ((u32 *)(NVIC_BASE + 0x214))
#define NVIC_IABR6 ((u32 *)(NVIC_BASE + 0x218))
#define NVIC_IABR7 ((u32 *)(NVIC_BASE + 0x21C))

#define NVIC_IPR0  ((u32 *)(NVIC_BASE + 0x300))
#define NVIC_IPR1  ((u32 *)(NVIC_BASE + 0x304))
#define NVIC_IPR2  ((u32 *)(NVIC_BASE + 0x308))
#define NVIC_IPR3  ((u32 *)(NVIC_BASE + 0x30C))
#define NVIC_IPR4  ((u32 *)(NVIC_BASE + 0x310))
#define NVIC_IPR5  ((u32 *)(NVIC_BASE + 0x314))
#define NVIC_IPR6  ((u32 *)(NVIC_BASE + 0x318))
#define NVIC_IPR7  ((u32 *)(NVIC_BASE + 0x31C))

#define NVIC_STIR  ((u32 *)(NVIC_BASE + 0xE00))

// ==================== EXTI ===================

#define EXTI_BASE (0x40010400)

// Interrupt mask register
#define EXTI_IMR   ((u32 *)(EXTI_BASE + 0x00))
// Event mask register
#define EXTI_EMR   ((u32 *)(EXTI_BASE + 0x04))
// Rising Trigger selection register
#define EXTI_RTSR  ((u32 *)(EXTI_BASE + 0x08))
// Falling Trigger selection register
#define EXTI_FTSR  ((u32 *)(EXTI_BASE + 0x0C))
// Software interrupt event register
#define EXTI_SWIER ((u32 *)(EXTI_BASE + 0x10))
// Pending register
#define EXTI_PR    ((u32 *)(EXTI_BASE + 0x14))


// ==================== RCC ====================

#define RCC_BASE (0x40021000)

#define RCC_ABP1ENR ((u32 *)(RCC_BASE + 0x1C))
#define RCC_TIM2EN  (0)

#define RCC_ABP2ENR ((u32 *)(RCC_BASE + 0x18))
#define RCC_AFIOEN   (0)
#define RCC_IOPAEN   (2)
#define RCC_IOPBEN   (3)
#define RCC_IOPCEN   (4)
#define RCC_ADC1EN   (9)
#define RCC_ADC2EN   (10)
#define RCC_TIM1EN   (11)
#define RCC_SPI1EN   (12)
#define RCC_USART1EN (14)

// ==================== GPIO ====================

#define GPIOA_BASE (0x40010800)
#define GPIOB_BASE (0x40010C00)
#define GPIOC_BASE (0x40011000)

#define GPIOA_CRL   ((u32 *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH   ((u32 *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR   ((u32 *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR   ((u32 *)(GPIOA_BASE + 0x0C))
#define GPIOA_BSRR  ((u32 *)(GPIOA_BASE + 0x10))
#define GPIOA_BRR   ((u32 *)(GPIOA_BASE + 0x14))

#define GPIOB_CRL   ((u32 *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH   ((u32 *)(GPIOB_BASE + 0x04))
#define GPIOB_IDR   ((u32 *)(GPIOB_BASE + 0x08))
#define GPIOB_ODR   ((u32 *)(GPIOB_BASE + 0x0C))
#define GPIOB_BSRR  ((u32 *)(GPIOB_BASE + 0x10))
#define GPIOB_BRR   ((u32 *)(GPIOB_BASE + 0x14))

#define GPIOC_CRL   ((u32 *)(GPIOC_BASE + 0x00))
#define GPIOC_CRH   ((u32 *)(GPIOC_BASE + 0x04))
#define GPIOC_IDR   ((u32 *)(GPIOC_BASE + 0x08))
#define GPIOC_ODR   ((u32 *)(GPIOC_BASE + 0x0C))
#define GPIOC_BSRR  ((u32 *)(GPIOC_BASE + 0x10))
#define GPIOC_BRR   ((u32 *)(GPIOC_BASE + 0x14))


// ==================== AFIO ====================

#define AFIO_BASE (0x40010000)
#define AFIO_EXTICR1 ((u32 *)(AFIO_BASE + 0x08))
#define AFIO_EXTICR2 ((u32 *)(AFIO_BASE + 0x0C))
#define AFIO_EXTICR3 ((u32 *)(AFIO_BASE + 0x10))
#define AFIO_EXTICR4 ((u32 *)(AFIO_BASE + 0x14))





#endif // REG_H