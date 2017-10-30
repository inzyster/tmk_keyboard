#ifndef LED_STUFF_H
#define LED_STUFF_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t pattern : 8;
    uint8_t remain  : 3;
    uint8_t length  : 3;
    bool repeat     : 1;
    bool reserved   : 1;
} led_pattern_t;

void led_timer_tick(void);
void led_set_pattern(led_pattern_t pattern);

#ifdef __cplusplus
}
#endif

#endif