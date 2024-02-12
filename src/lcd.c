#include "lcd.h"
#include "bit_operations.h"


typedef enum
{
    LCD_CLEAR_SCREEN_CMD = 0x01,
    LCD_CMD_8BIT_2LINE_5X8 = 0x38,
    LCD_CMD_DISPLAY_ON_CURSOR_ON = 0x0E,
    LCD_CMD_ENTRY_MODE_SET = 0x06,
    LCD_CMD_HOME = 0x02,
    LCD_CMD_MOVE_CURSOR_LEFT = 0x10,
    LCD_CMD_MOVE_CURSOR_RIGHT = 0x14,
    LCD_CMD_MOVE_SCREEN_LEFT = 0x18,
} LCD_Command;

void LCD_sendCommand(LCD_Command command);

void LCD_sendCommand(LCD_Command command)
{
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN0, READ_BIT(command, 0));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN1, READ_BIT(command, 1));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN2, READ_BIT(command, 2));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN3, READ_BIT(command, 3));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN4, READ_BIT(command, 4));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN5, READ_BIT(command, 5));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN6, READ_BIT(command, 6));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN7, READ_BIT(command, 7));

    GPIO_write_pin(LCD_CONTROL_PORT, LCD_RS, 0);
    GPIO_write_pin(LCD_CONTROL_PORT, LCD_RW, 0);
    GPIO_write_pin(LCD_CONTROL_PORT, LCD_EN, 1);
    _delay_ms(1);
    GPIO_write_pin(LCD_CONTROL_PORT, LCD_EN, 0);
    _delay_ms(1);
}



void LCD_init(void)
{
    GPIO_init_port(LCD_DATA_PORT);
    GPIO_init_port(LCD_CONTROL_PORT);



    //  Sets the mode of LCD DATA pins to be output
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN0, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN1, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN2, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN3, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN4, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN5, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN6, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_DATA_PORT, LCD_DATA_PIN7, GPIO_PIN_OUTPUT);

    // Sets the mode of LCD control pins to be output
    GPIO_set_pin_mode(LCD_CONTROL_PORT, LCD_RS, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_CONTROL_PORT, LCD_RW, GPIO_PIN_OUTPUT);
    GPIO_set_pin_mode(LCD_CONTROL_PORT, LCD_EN, GPIO_PIN_OUTPUT);

    // 8bit mode,  2 lines, 5x8 matrix
    LCD_sendCommand(LCD_CMD_8BIT_2LINE_5X8);
    // Display on, cursor on
    LCD_sendCommand(LCD_CMD_DISPLAY_ON_CURSOR_ON); 
    // Clear screen
    LCD_sendCommand(LCD_CLEAR_SCREEN_CMD);
    // GO to home
    LCD_sendCommand(LCD_CMD_HOME);

}




void LCD_displayCharacter(u8 data)
{
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN0, READ_BIT(data, 0));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN1, READ_BIT(data, 1));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN2, READ_BIT(data, 2));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN3, READ_BIT(data, 3));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN4, READ_BIT(data, 4));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN5, READ_BIT(data, 5));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN6, READ_BIT(data, 6));
    GPIO_write_pin(LCD_DATA_PORT, LCD_DATA_PIN7, READ_BIT(data, 7));

    GPIO_write_pin(LCD_CONTROL_PORT, LCD_RS, 1);
    GPIO_write_pin(LCD_CONTROL_PORT, LCD_RW, 0);
    GPIO_write_pin(LCD_CONTROL_PORT, LCD_EN, 1);
    
    _delay_ms(1);

    GPIO_write_pin(LCD_CONTROL_PORT, LCD_EN, 0);

    _delay_ms(1);
}

void LCD_clear() {
    LCD_sendCommand(LCD_CLEAR_SCREEN_CMD);
    LCD_sendCommand(LCD_CMD_HOME);
}
void LCD_displayString(const u8 *str)
{
    // Set the entry mode to increment the cursor
    LCD_sendCommand(LCD_CMD_ENTRY_MODE_SET);
    u8 i = 0;
    while(str[i] != '\0')
    {
        LCD_displayCharacter(str[i]);
        i++;
        if (i > 15){
            LCD_sendCommand(LCD_CMD_MOVE_SCREEN_LEFT);
        }
    }
}

void LCD_goToRowColumn(u8 row, u8 col)
{
    LCD_sendCommand(LCD_CMD_HOME);
    if (row == 0)
    {
        LCD_sendCommand(0x80);
    }
    else if (row == 1)
    {
        LCD_sendCommand(0xC0);
    }

    for (u8 i = 0; i < col; i++)
    {
        LCD_sendCommand(LCD_CMD_MOVE_CURSOR_RIGHT);
    }
}

// void LCD_goToRowColumn(u8 row, u8 col)
// {
//     if (row == 0)
//     {
//         LCD_sendCommand()
//     }

//     for (u8 i = 0; i < row; i++)
//     {
//         LCD_sendCommand(0xC0);
//     }
// }







