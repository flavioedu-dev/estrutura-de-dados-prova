#include <stdio.h>
#include <stdlib.h>
#include "toBin.h"

int main(){
    int opcao = 0;

    while(opcao != 2){
        printf("--- Conversor de Decimal para Binario ---\n");
        printf("1 - Converter\n");
        printf("2 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        printf("\n");

        if(opcao == 1){
            Fila *l = iniciar();

            int num;
            printf("Digite o numero que deseja converter: ");
            scanf("%d", &num);
            printf("Binario: %d\n", decBin(l, num));
            printf("\n");
        }else if(opcao == 2){
            printf("--- Ate logo! ---");
            break;
        }else{
            printf("-- Escolha um das opcoes apresentadas! --\n");
            printf("\n");
        }
    }

    return 0;
}