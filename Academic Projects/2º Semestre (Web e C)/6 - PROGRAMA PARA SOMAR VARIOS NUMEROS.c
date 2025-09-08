/*   22/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int main(){
    int v [1000], qtd, posicao, menor, resultado_qtd, resultado_nuns;
    
    printf("PROGRAMA PARA SOMAR VARIOS NUMEROS\n\n");
    
    printf("Deseja ter quantos numeros (de 2 ate 1000): ");
    resultado_qtd = scanf("%d", &qtd);
    printf("\n");
    
    if (qtd <= 1 || qtd > 1000 || resultado_qtd != 1){
        printf("QUANTIDADE INVALIDA");
        while(getchar() != '\n');
    } else {
        for(posicao = 0; posicao<qtd; posicao++){
            printf("Digite o %dº numero: ", posicao+1);
            resultado_nuns = scanf("%d", &v[posicao]);
            if (resultado_nuns != 1){
                printf("SOMENTE NUMEROS!\n");
                posicao -= 1;
                while(getchar() != '\n');
                continue;
            }
        }
    
    
        menor = v[0];
        for (posicao = 1; posicao<qtd; posicao++){
            menor += v[posicao];
        }
        printf("\nA soma dos valores equivale a %d\n\n", menor);
    }
    printf("PROGRAMA ENCERRADO!");
    return 0;
}