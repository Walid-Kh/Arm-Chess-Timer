#include "timer2.h"
#include "bit_operations.h"
#include "reg.h"

void Timer2_init(const Timer2_ConfigType *Config_Ptr)
{
    SET_BIT(*RCC_ABP1ENR, RCC_TIM2EN);

    // Disable the timer
    CLEAR_BIT(*TIM2_CR1, 0);

    // Set the prescaler
    *TIM2_PSC = Config_Ptr->prescaler * 2;

    // Set the count to value
    *TIM2_ARR = Config_Ptr->countTo;

    *TIM2_CR1 = 0;
    switch (Config_Ptr->mode)
    {
    case TIMER2_COUNT_UP:
        SET_BIT(*TIM2_CR1, 2);
        break;
    }

    switch (Config_Ptr->interruptEnable)
    {
    case 1:
        SET_BIT(*TIM2_DIER, 0);
        SET_BIT(*NVIC_ISER0, 28);
        break;
    case 0:
        CLEAR_BIT(*TIM2_DIER, 0);
        CLEAR_BIT(*NVIC_ISER0, 28);
        break;
    }
    g_callBackPtr = Config_Ptr->callBackPtr;

    // Enable the timer
    SET_BIT(*TIM2_CR1, 0);

}

void tim2_isr (void) {
    if (g_callBackPtr != NULL)
    {
        g_callBackPtr();
    }
    SET_BIT(*TIM2_SR, 0);
}
