#include <stdio.h>
#include "conversorTemperatura.h"

void conversorTemperatura(void)
{
    int tipoConversao;
    float temperatura, resultado;
    
    printf("Escolha o tipo de conversão de temperatura:\n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("Digite o número do tipo de conversão: ");
    
    scanf("%d", &tipoConversao);

    if (tipoConversao == 1)
    {
        printf("Digite a temperatura em Celsius: ");
        scanf("%f", &temperatura);
        resultado = (temperatura * 9) / 5 + 32;
        printf("A temperatura em Fahrenheit é: %.2f\n", resultado);
    }
    else if (tipoConversao == 2)
    {
        printf("Digite a temperatura em Fahrenheit: ");
        scanf("%f", &temperatura);
        resultado = (temperatura - 32) * 5 / 9;
        printf("A temperatura em Celsius é: %.2f\n", resultado);
    }
    else
    {
        printf("Opção inválida!\n");
    }
}
