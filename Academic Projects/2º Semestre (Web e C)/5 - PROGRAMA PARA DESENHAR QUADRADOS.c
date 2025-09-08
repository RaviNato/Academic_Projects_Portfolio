/*   21/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



int quadrado_cheio(){
    int valor, resultado_valor, i, j;
    
    printf("\nPROGRAMA PARA DESENHAR QUADRADO CHEIO\n\n");
    
    while(true){
        printf("Digite o tamanho do seu quadrado, em unidade: ");
        resultado_valor = scanf("%d", &valor);
        if (resultado_valor != 1 || valor <= 0){
            printf("\n\nO TAMANHO DEVE SER UM NÚMERO INTEIRO POSITIVO\n\n");
            while (getchar() != '\n');
            continue;
        } else {
            for (i = 1; i <= valor; i++){
                for (j = 1; j <= valor; j++){
                    printf("O");
                }
                printf("\n");
            }
        }
        printf("\n");
        break;
    }
    return 0;
}




int quadrado_vazado(){
    int valor, resultado_valor, i, j;
    int linha_atual = 1;
    
    printf("\nPROGRAMA PARA DESENHAR QUADRADO VAZADO\n\n");
    
    while(true){
        printf("Digite o tamanho do seu quadrado, em unidade: ");
        resultado_valor = scanf("%d", &valor);
        if (resultado_valor != 1 || valor <= 0){
            printf("\n\nO TAMANHO DEVE SER UM NÚMERO INTEIRO POSITIVO\n\n");
            while (getchar() != '\n');
            continue;
        } else while(linha_atual <= valor){
            if (linha_atual == 1 || linha_atual == valor){
                for (i = 1; i <= valor; i++){
                    printf("O");
                }
                printf("\n");
            } else {
                printf("O");
                for (j = 1; j <= (valor-2); j++)
                    printf(" ");
                printf("O\n");
            }
            linha_atual++;
        }
        printf("\n");
        break;
    }
    
    return 0;
}





int main(){
    int escolha;
    int resultado_escolha = 0;
    while(true){
        printf("PROGRAMA PARA DESENHAR QUADRADOS");
        printf("\n\n[1]Desenhar quadrado cheio;\n[2]Desenhar quadrados fechados;\n[3]Encerrar programa.\n\nEscolha o tipo de quadrado: ");
        resultado_escolha = scanf(" %d", &escolha);
        if (resultado_escolha != 1 || escolha < 1 || escolha > 3){
            printf("ESCOLHA INVÁLIDA! TENTE NOVAMENTE\n\n");
            while(getchar() != '\n');
            continue;
        } else if(escolha == 1){
            quadrado_cheio();
        } else if(escolha == 2){
            quadrado_vazado();
        } else {
            break;
        }
    }
    return 0;   
}