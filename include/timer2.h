/*
    * timer2.h
    * Author: Walid Khamees
    * Description: This file contains the implementation of the Timer2 peripheral
*/
#ifndef TIMER_2_H
#define TIMER_2_H

#include "std_types.h"


static void (*g_callBackPtr)(void) = NULL;


typedef enum {
    TIMER2_COUNT_UP = 0,
} timer2_mode; // Timer2 mode


// TODO: Separate the config struct to a struct for basic config and union for the mode specific config 

typedef struct {
    timer2_mode mode;
    u32 prescaler;
    u32 countTo;
    u8 interruptEnable;
    void (*callBackPtr)(void);
} Timer2_ConfigType;



void Timer2_init(const Timer2_ConfigType * Config_Ptr);
void Timer2_setCallBack(void(*a_ptr)(void));







#endif // TIMER_2_H