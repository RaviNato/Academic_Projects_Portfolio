/*   25/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static inline float max(float a, float b) {
    return a > b ? a : b;
}

int main(){
    unsigned int RA[100], tamanho_da_classe, i;
    float nota[300], media_de_provas[100], media_com_sub1, media_com_sub2;
    
    int resultado_classe, resultado_RA, resultado_nota;
    
    printf("PROGRAMA PARA CALCULAR MÉDIA DAS NOTAS DOS ALUNOS\n\n");
    while(true){
        printf("Digite a quantidade de alunos na sala: ");
        resultado_classe = scanf("%d",&tamanho_da_classe);
        if (resultado_classe != 1 || tamanho_da_classe <= 0 || tamanho_da_classe > 100){
            printf("TAMANHO DE CLASSE INVÁLIDO\n\n");
            while(getchar() != '\n');
            continue;
        }
        break;
    }
    
    for (i = 0; (i/3) < tamanho_da_classe; i+=3){
        
        while(true){
            printf("\nDigite o RA do %dº aluno: ", ((i/3)+1));
            resultado_RA = scanf("%d",&RA[i/3]);
            if (resultado_RA != 1 || RA[i/3] < 10000000 || RA[i/3] > 99999999){
                printf("RA INVÁLIDO\n");
                while(getchar() != '\n');
                continue;
            }
            break;
        }
        
        while(true){
            printf("Digite a nota da primeira prova (P1)(se a não fez, digite -1): ");
            resultado_nota = scanf("%f",&nota[i]);
            if (resultado_nota != 1 || nota[i] < -1 || nota[i] > 10){
                printf("NOTA INVÁLIDA\n");
                while(getchar() != '\n');
                continue;
            }
            
            printf("Digite a nota da segunda prova (P2)(se a não fez, digite -1): ");
            resultado_nota = scanf("%f",&nota[i+1]);
            if (resultado_nota != 1 || nota[i+1] < -1 || nota[i+1] > 10){
                printf("NOTA INVÁLIDA\n");
                while(getchar() != '\n');
                continue;
            }
            
            printf("Digite a nota da prova substituta (Sub)(se a não fez, digite -1): ");
            resultado_nota = scanf("%f",&nota[i+2]);
            if (resultado_nota != 1 || nota[i+2] < -1 || nota[i+2] > 10){
                printf("NOTA INVÁLIDA\n");
                while(getchar() != '\n');
                continue;
            }
            break;
        }
        
        if (nota[i] == -1 && nota[i+1] == -1 && nota[i+2] == -1){
            media_de_provas[i/3] = 0;
        } else if (nota[i] == -1 || nota[i+1] == -1 || nota[i+2] != -1){
            if (nota[i] == -1) nota[i] = 0;
            if (nota[i+1] == -1) nota[i+1] = 0;
            if (nota[i+2] == -1) nota[i+2] = 0;
            media_com_sub1 = ((nota[i+2] + (2*nota[i+1])) / 3);
            media_com_sub2 = ((nota[i] + (2*nota[i+2])) / 3);
            media_de_provas[i/3] = max(media_com_sub1, media_com_sub2);
        } else {
            media_de_provas[i/3] = ((nota[i] + (2*nota[i+1])) / 3);
        }
    }
    
    for (i = 0; i < tamanho_da_classe; i++){
        printf("\nA média do aluno %d é %.1f.", RA[i], media_de_provas[i]);
    }
    
    return 0;
}