#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"

// arquivo .pio
#include "pio_matrix.pio.h"

// Pinos do teclado matricial
#define ROW1 28
#define ROW2 27
#define ROW3 26
#define ROW4 22
#define COL1 21
#define COL2 20
#define COL3 19
#define COL4 18

// Definições das teclas
#define TECLA_A 'A'
#define TECLA_B 'B'
#define TECLA_C 'C'
#define TECLA_D 'D'
#define TECLA_HASH '#'
#define TECLA_ESTRELA '*'

// Função de inicialização do teclado matricial
void teclado_init()
{
  gpio_init(ROW1);
  gpio_set_dir(ROW1, GPIO_IN);
  gpio_init(ROW2);
  gpio_set_dir(ROW2, GPIO_IN);
  gpio_init(ROW3);
  gpio_set_dir(ROW3, GPIO_IN);
  gpio_init(ROW4);
  gpio_set_dir(ROW4, GPIO_IN);
  gpio_init(COL1);
  gpio_set_dir(COL1, GPIO_OUT);
  gpio_init(COL2);
  gpio_set_dir(COL2, GPIO_OUT);
  gpio_init(COL3);
  gpio_set_dir(COL3, GPIO_OUT);
  gpio_init(COL4);
  gpio_set_dir(COL4, GPIO_OUT);
}

// Função para ler o teclado matricial correspondente com o que pede a tarefa
char ler_tecla()
{
  const char matriz[4][4] = {
      {'1', '2', '3', TECLA_A},
      {'4', '5', '6', TECLA_B},
      {'7', '8', '9', TECLA_C},
      {TECLA_ESTRELA, '0', TECLA_HASH, TECLA_D}};

  for (int c = 0; c < 4; c++)
  {
    gpio_put(COL1, c == 0);
    gpio_put(COL2, c == 1);
    gpio_put(COL3, c == 2);
    gpio_put(COL4, c == 3);

    if (gpio_get(ROW1))
    {
      sleep_ms(200);
      return matriz[0][c];
    }
    if (gpio_get(ROW2))
    {
      sleep_ms(200);
      return matriz[1][c];
    }
    if (gpio_get(ROW3))
    {
      sleep_ms(200);
      return matriz[2][c];
    }
    if (gpio_get(ROW4))
    {
      sleep_ms(200);
      return matriz[3][c];
    }
  }

  return 0;
}

// número de LEDs
#define NUM_PIXELS 25

// pino de saída
#define OUT_PIN 7

// botão de interupção
const uint button_0 = 5;
const uint button_1 = 6;

// vetor para criar imagem na matriz de led - 1
double desenho[25] = {0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0};

// vetor para criar imagem na matriz de led - 2
double desenho2[25] = {1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0};

// imprimir valor binário
void imprimir_binario(int num)
{
  int i;
  for (i = 31; i >= 0; i--)
  {
    (num & (1 << i)) ? printf("1") : printf("0");
  }
}

// rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events)
{
  printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
  printf("HABILITANDO O MODO GRAVAÇÃO");
  reset_usb_boot(0, 0); // habilita o modo de gravação do microcontrolador
}

// rotina para definição da intensidade de cores do led
uint32_t matrix_rgb(double b, double r, double g)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

// rotina para acionar a matrix de leds - ws2812b
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)
{

  for (int16_t i = 0; i < NUM_PIXELS; i++)
  {
    valor_led = matrix_rgb(desenho[24 - i], r = 0.0, g = 0.0);
    pio_sm_put_blocking(pio, sm, valor_led);
  }
  imprimir_binario(valor_led);
}

// função principal
int main()
{
  PIO pio = pio0;
  bool ok;
  uint16_t i;
  uint32_t valor_led;
  double r = 0.0, b = 0.0, g = 0.0;

  // coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
  ok = set_sys_clock_khz(128000, false);

  // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
  stdio_init_all();

  printf("iniciando a transmissão PIO");
  if (ok)
    printf("clock set to %ld\n", clock_get_hz(clk_sys));

  // configurações da PIO
  uint offset = pio_add_program(pio, &pio_matrix_program);
  uint sm = pio_claim_unused_sm(pio, true);
  pio_matrix_program_init(pio, sm, offset, OUT_PIN);

  // inicializar o botão de interrupção - GPIO5
  gpio_init(button_0);
  gpio_set_dir(button_0, GPIO_IN);
  gpio_pull_up(button_0);

  // inicializar o botão de interrupção - GPIO5
  gpio_init(button_1);
  gpio_set_dir(button_1, GPIO_IN);
  gpio_pull_up(button_1);

  teclado_init();

  // interrupção da gpio habilitada
  gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);

  while (true)
  {

    char tecla = ler_tecla();

    if (tecla == TECLA_A)
    {
      // rotina para escrever na matriz de leds com o emprego de PIO - desenho 2
      desenho_pio(desenho, valor_led, pio, sm, r, g, b);
    }
    else if (tecla == TECLA_B)
    {
      // rotina para escrever na matriz de leds com o emprego de PIO - desenho 1
      desenho_pio(desenho2, valor_led, pio, sm, r, g, b);
    }

    sleep_ms(500);
    printf("\nfrequeência de clock %ld\r\n", clock_get_hz(clk_sys));
  }
}