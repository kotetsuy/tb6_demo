#ifndef __LED_H_
#define __LED_H_

#include "arm_math.h"

typedef struct {
    float32_t now;
} LEDHandle_t;

#define LEDSTART 0.0F
#define LEDEND (2.0F*PI)
#define LEDINC (PI/8.0F)
#define LEDNUM 8
#define LEDFUNCNUM 4

typedef void (*LEDFuncs_t)(float32_t *out, LEDHandle_t *in);

void LEDWave1(float32_t *out, LEDHandle_t *in);
void LEDWave2(float32_t *out, LEDHandle_t *in);
void LEDBlink(float32_t *out, LEDHandle_t *in);
void LEDBlinkSlow(float32_t *out, LEDHandle_t *in);

#endif // __LED_H_
