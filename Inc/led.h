#ifndef __LED_H_
#define __LED_H_

#include "arm_math.h"

typedef float32_t LEDHandle_t;

#define LEDNUM 8
#define LEDFUNCNUM 6

typedef void (*LEDFuncs_t)(float32_t *out);

void LEDWave1(float32_t *out);
void LEDWave2(float32_t *out);
void LEDWave3(float32_t *out);
void LEDWave4(float32_t *out);
void LEDBlink(float32_t *out);
void LEDBlinkSlow(float32_t *out);

#endif // __LED_H_
