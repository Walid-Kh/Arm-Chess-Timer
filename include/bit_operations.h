#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H


#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit) (reg &= ~(1 << bit))
#define TOGGLE_BIT(reg, bit) (reg ^= (1 << bit))
#define READ_BIT(reg, bit) (reg & (1 << bit))



#endif