/*   08/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int grau(){
        float A, B, resultado;
        printf("PROGRAMA PARA ACHAR A RAIZ 1° GRAU: Ax + B = 0\n\n");
        printf("Digite o coeficiente A: ");
        scanf("%f",&A);
        printf("Digite o coeficiente B: ");
        scanf("%f",&B);
        resultado = (B*-1)/A;
        printf("\nA raiz desta função, onde a reta intercepta o eixo X, é %.1f. \n\n", resultado);
        return 0;
    }
    grau();
    



    int primo(){
        int num;
        printf("PROGRAMA PARA IDENTIFICAR NÚMERO PRIMO\n\n");
        do{
            printf("Digite o número natural a identificar: ");
            scanf("%d",&num);
            if (num < 1){
                printf("\nSEU NÚMERO NÃO É NATURAL, TENTE NOVAMENTE!\n\n");
            }
        } while (num < 1);
        
        if (num == 1){
            printf("\nSeu número não é primo!");
            return 0;
        }
        
        for (int i = 2; i<=(num/2); i++){
            if (num%i == 0){
                printf("\nSeu número não é primo!");
                return 0;
            }
        }
        printf("\nSeu número é primo!");
        return 0;
    }
    primo();



    return 0;
}