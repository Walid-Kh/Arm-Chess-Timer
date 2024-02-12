#ifndef LCD_H
#define LCD_H

#include "gpio.h"
#include "std_types.h"



#define LCD_DATA_PORT GPIO_PORT_B
#define LCD_DATA_PIN0 0
#define LCD_DATA_PIN1 1
#define LCD_DATA_PIN2 5
#define LCD_DATA_PIN3 6
#define LCD_DATA_PIN4 7
#define LCD_DATA_PIN5 8
#define LCD_DATA_PIN6 9
#define LCD_DATA_PIN7 10

#define LCD_CONTROL_PORT GPIO_PORT_B
#define LCD_EN 12
#define LCD_RW 13
#define LCD_RS 14





void LCD_init(void);

void LCD_displayCharacter(u8 data);
void LCD_displayString(const u8 *str);
void LCD_goToRowColumn(u8 row, u8 col);
void LCD_clear(void);











#endif // LCD_H