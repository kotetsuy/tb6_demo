#include "main.h"
#include "arm_math.h"
#include "led.h"

#define LEDSTART 0.0F
#define LEDEND (2.0F*PI)
#define LEDINC (PI/32.0F)

LEDHandle_t LEDs1[LEDNUM] = {
  PI, 3.0F/4.0F*PI, PI/2.0F,PI/4.0F,
  0.0F, PI/4.0F, PI/2.0F, 3.0F/4.0F*PI,
};

LEDHandle_t LEDs2[LEDNUM] = {
  PI, 3.0F/4.0F*PI, PI/2.0F,PI/4.0F,
  0.0F, PI/4.0F, PI/2.0F, 3.0F/4.0F*PI,
};

LEDHandle_t LEDs3[LEDNUM] = {
  0.0F, PI/16.0F, PI*2.0F/16.0F, PI*3.0F/16.0F,
  PI*4.0F/16.0F, PI*5.0F/16.0F, PI*6.0F/16.0F, PI*7.0F/16.0F,
};

LEDHandle_t LEDsBlinkSlow[LEDNUM] = {
  0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F,
};

float32_t LEDInc(float32_t in)
{
    in += LEDINC;
    in = (in >= LEDEND) ? in - LEDEND: in;
    return in;
}

float32_t LEDDec(float32_t in)
{
    in -= LEDINC;
    in = (in <= LEDSTART) ? LEDEND + in: in;
    return in;
}

void LEDWave1(float32_t *out)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_cos_f32(LEDs1[i]);
        LEDs1[i] = LEDInc(LEDs1[i]);
    }
}

void LEDWave2(float32_t *out)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_cos_f32(LEDs2[i]);
        LEDs2[i] = LEDDec(LEDs2[i]);
    }
}

void LEDWave3(float32_t *out)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_sin_f32(LEDs3[i]);
        LEDs3[i] = LEDDec(LEDs3[i]);
    }
}

void LEDWave4(float32_t *out)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_sin_f32(LEDs3[i]);
        LEDs3[i] = LEDInc(LEDs3[i]);
    }
}

void LEDBlink(float32_t *out)
{
    static int32_t cnt = 0;
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        if (cnt < 100) {
            out[i] = 1.0F;
        } else if (cnt < 199) {
            out[i] = -1.0F;
        } else {
            cnt = 0;
            out[i] = 1.0F;
        }
        cnt++;
    }
}

void LEDBlinkSlow(float32_t *out)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_sin_f32(LEDsBlinkSlow[i]);
        LEDsBlinkSlow[i] = LEDInc(LEDsBlinkSlow[i]);
    }
}
