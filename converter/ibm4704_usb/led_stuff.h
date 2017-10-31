#ifndef LED_STUFF_H
#define LED_STUFF_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t pattern;
    uint8_t remain;
    uint8_t length;
    bool repeat;
} led_pattern_t;

void led_timer_tick(void);
void led_set_pattern(led_pattern_t pattern);

#ifdef __cplusplus
}
#endif

#endif