#include <stdio.h>
#include "conversorTemperatura.h"

int main(void)
{
    int tipoConversao;
    
    printf("Bem-vindo ao sistema de conversões!\n");
    printf("Escolha o tipo de conversão:\n");
    printf("1. Conversor de temperatura\n");
    printf("2. Outro conversor (a ser implementado)\n");
    printf("Digite o número do tipo de conversão: ");
    
    scanf("%d", &tipoConversao);
    
    switch (tipoConversao)
    {
    case 1:
        conversorTemperatura();
        break;
    case 2:
        printf("Outro conversor será implementado em breve!\n");
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }

    return 0;
}
