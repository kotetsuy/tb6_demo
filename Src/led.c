#include "main.h"
#include "arm_math.h"
#include "led.h"

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

void LEDWave1(float32_t *out, LEDHandle_t *in)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_cos_f32(in[i].now);
        in[i].now = LEDInc(in[i].now);
    }
}

void LEDWave2(float32_t *out, LEDHandle_t *in)
{
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        out[i] = arm_cos_f32(in[i].now);
        in[i].now = LEDDec(in[i].now);
    }
}

void LEDBlink(float32_t *out, LEDHandle_t *in)
{
    static int32_t cnt = 0;
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        if (cnt <= 20) {
            out[i] = 1.0F;
        } else if (cnt < 40) {
            out[i] = 0.0F;
        } else {
            cnt = 0;
            out[i] = 0.0F;
        }
        cnt++;
    }
}

void LEDBlinkSlow(float32_t *out, LEDHandle_t *in)
{
    static int32_t cnt = 0;
    int32_t i;
    for (i = 0; i < LEDNUM; i++) {
        if (cnt <= 50) {
            out[i] = 1.0F;
        } else if (cnt < 100) {
            out[i] = 0.0F;
        } else {
            cnt = 0;
            out[i] = 0.0F;
        }
        cnt++;
    }
}
