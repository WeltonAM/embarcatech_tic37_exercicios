#include <stdio.h>
#include "conversorTemperatura.h"

int main(void)
{
    printf("Bem vindo ao sistema de conversões!\n");
    printf("Escolha o tipo de conversão:\n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("Digite o número do tipo de conversão: ");
    
    int tipo;
    scanf("%d", &tipo);
    
    switch (tipo)
    {
    case 1:
        conversorTemperatura(tipo); 
        break;
    default:
        printf("Opção inválida\n");
        break;
    }

    return 0;
}