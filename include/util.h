#include "std_types.h"

#ifndef UTIL_H
#define UTIL_H

#define F_CPU 72000000UL


void _delay_ms(u32 n) {
    u64 cycles = n * (F_CPU / 1000) / 3;

    for (u32 i = 0; i < cycles; i++) {
        __asm__("nop");
    }
}

u32 strlen(const u8 *str) {
    u32 len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}



#endif // UTIL_H