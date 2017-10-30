
#include "led_stuff.h"
#include "timer.h"

uint16_t led_timer = 0;
bool is_led_on = false;

const uint16_t led_timer_unit = 250;

led_pattern_t _pattern = { .pattern = 0b00000000, .remain = 0, .length = 0, .repeat = 0 };

static inline void led_on(void)
{
    DDRD    |=  (1 << PORTD4);
    PORTD   |=  (1 << PORTD4); 
    is_led_on =true;
}

static inline void led_off(void)
{
    DDRD    |=  (1 << PORTD4);    
    PORTD   &= ~(1 << PORTD4);     
    is_led_on = false;
}

void led_process_pattern(void) 
{
    led_timer = timer_read();
    if (_pattern.length == 0) 
        return; 
    if (_pattern.remain == 0) {
        if (_pattern.repeat == false) {
            return;
        } else {
            _pattern.remain = _pattern.length;
        }
    } else {
        _pattern.remain--;
        bool turn_on = 0x1 & (_pattern.pattern >> _pattern.remain);
        if (is_led_on == true && turn_on == false) {
            led_off();
        } else if (is_led_on == false && turn_on == true) {
            led_on();
        }
    }
}

void led_set_pattern(led_pattern_t pattern) {
    _pattern.length = 0;
    _pattern = pattern;
    led_process_pattern();
}

void led_timer_tick(void) 
{
    if (timer_elapsed(led_timer) > led_timer_unit) {
        led_process_pattern();
    }
}
