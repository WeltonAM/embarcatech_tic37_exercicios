#include <stdio.h>
#include "conversorTemperatura.h"

void conversorTemperatura(int tipo)
{
    float temperatura, resultado;

    if (tipo == 1)
    {
        printf("Digite a temperatura em Celsius: ");
        scanf("%f", &temperatura);
        resultado = (temperatura * 9) / 5 + 32;
        printf("A temperatura em Fahrenheit é: %.2f\n", resultado);
    }
    else if (tipo == 2)
    {
        printf("Digite a temperatura em Fahrenheit: ");
        scanf("%f", &temperatura);
        resultado = (temperatura - 32) * 5 / 9;
        printf("A temperatura em Celsius é: %.2f\n", resultado);
    }
}
