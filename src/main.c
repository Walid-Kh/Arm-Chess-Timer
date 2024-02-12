#include "util.h"
#include "gpio.h"
#include "external_interrupts.h"
#include "lcd.h"
#include "timer2.h"

struct game_state
{
    u32 player1_time;
    u32 player2_time;
    u8 player1_turn;
    u8 game_over;
    u8 won;
};

struct game_state initial_state = {
    .player1_time = 100000 * 60 * 10, // 10 minutes
    .player2_time = 100000 * 60 * 10, // 10 minutes
    .player1_turn = 1,
    .game_over = 0,
    .won = 0,
};
struct game_state state = {
    .player1_time = 100000 * 60 * 10, // 10 minutes
    .player2_time = 100000 * 60 * 10, // 10 minutes
    .player1_turn = 1,
    .game_over = 0,
    .won = 0,
};

const u8 *time_to_string(u32 time)
{
    static u8 time_str[6];
    u32 minutes = time / (100000 * 60);
    u32 seconds = (time / 100000) % 60;
    // sprintf is not available
    time_str[0] = '0' + (minutes / 10);
    time_str[1] = '0' + (minutes % 10);
    time_str[2] = ':';
    time_str[3] = '0' + (seconds / 10);
    time_str[4] = '0' + (seconds % 10);
    time_str[5] = '\0';
    return time_str;
}

void update_time(void)
{
    if (state.player1_turn)
    {
        state.player1_time -= 1;

        if (state.player1_time % 100000 == 0)
        {
            LCD_goToRowColumn(0, 0);
            LCD_displayString(time_to_string(state.player1_time));
        }
    }
    else
    {
        state.player2_time -= 1;
        if (state.player2_time % 100000 == 0)
        {
            LCD_goToRowColumn(1, 11);
            LCD_displayString(time_to_string(state.player2_time));
        }
    }
    if (state.player1_time == 0 || state.player2_time == 0)
    {
        state.game_over = 1;
        if (state.player1_time == 0)
        {
            state.won = 2;
            LCD_goToRowColumn(1, 0);
            LCD_displayString("Player 2 won!");
        }
        else
        {
            state.won = 1;
            LCD_goToRowColumn(1, 0);
            LCD_displayString("Player 1 won!");
        }
    }
}
void player1_button(void)
{
    if (state.player1_turn)
    {
        state.player1_turn = 0;
    }
}
void player2_button(void)
{
    if (!state.player1_turn)
    {
        state.player1_turn = 1;
    }
}
void reset_button(void)
{
    state = initial_state;
    LCD_goToRowColumn(0, 0);
    LCD_displayString(time_to_string(state.player1_time));
    LCD_goToRowColumn(1, 11);
    LCD_displayString(time_to_string(state.player2_time));
}

int main()
{
    GPIO_init_port(GPIO_PORT_A);

    GPIO_set_pin_mode(GPIO_PORT_A, 0, GPIO_PIN_INPUT);
    GPIO_set_pin_mode(GPIO_PORT_A, 1, GPIO_PIN_INPUT);
    GPIO_set_pin_mode(GPIO_PORT_A, 2, GPIO_PIN_INPUT);

    GPIO_set_pin_mode(GPIO_PORT_A, 3, GPIO_PIN_OUTPUT);

    external_interrupt_init();
    external_interrupt_enable(EXTERNAL_INTERRUPT0, RISING_EDGE, GPIO_PORT_A, 0);
    external_interrupt_enable(EXTERNAL_INTERRUPT1, RISING_EDGE, GPIO_PORT_A, 1);
    external_interrupt_enable(EXTERNAL_INTERRUPT2, RISING_EDGE, GPIO_PORT_A, 2);

    external_interrupt_attach_callback(EXTERNAL_INTERRUPT0, player1_button);
    external_interrupt_attach_callback(EXTERNAL_INTERRUPT1, player2_button);
    external_interrupt_attach_callback(EXTERNAL_INTERRUPT2, reset_button);

    LCD_init();
    LCD_goToRowColumn(0, 0);
    const u8 *player1_time = time_to_string(state.player1_time);
    LCD_displayString(player1_time);
    LCD_goToRowColumn(1, 11);
    const u8 *player2_time = time_to_string(state.player2_time);
    LCD_displayString(player2_time);

    Timer2_ConfigType timer2 = {
        .countTo = 1,
        .interruptEnable = 1,
        .mode = TIMER2_COUNT_UP,
        .prescaler = 1,
        .callBackPtr = update_time,
    };
    Timer2_init(&timer2);

    while (1)
    {
        // if (GPIO_read_pin(GPIO_PORT_B, 5))
        //     GPIO_toggle_pin(GPIO_PORT_B, 10);
    }
    return 0;
}