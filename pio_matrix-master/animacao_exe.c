#include "animacao_exe.h"
#include "pico/stdlib.h"

#define NUM_PIXELS 25

void animacao_exe(double *desenho, uint32_t valor_led, PIO pio, uint sm)
{
    double desenho_1[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_2[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_3[25] = {
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0};

    double desenho_4[25] = {
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0};

    desenho_pio(desenho_1, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(1200);
    desenho_pio(desenho_2, valor_led, pio, sm, 0.0, 1.0, 0.0);
    sleep_ms(1200);
    desenho_pio(desenho_3, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(1200);
    desenho_pio(desenho_4, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(1200);
    desenho_pio(desenho, valor_led, pio, sm, 0.0, 0.0, 0.0);
    sleep_ms(1200);
    desenho_pio(desenho_4, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(1000);
    desenho_pio(desenho, valor_led, pio, sm, 0.0, 0.0, 0.0);
}
