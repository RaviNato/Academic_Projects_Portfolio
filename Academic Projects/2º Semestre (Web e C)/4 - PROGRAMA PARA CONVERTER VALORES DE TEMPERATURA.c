//*   14/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

float processamento(float valor, int medida1, int medida2, char *temp1, char *temp2){
    float saida;
    if (medida2 == 0){
        if (medida1 == 1){
            saida = valor + 273.15;
            strcpy(temp1, "Celsius");
        } else if (medida1 == 2){
            saida = (valor - 32) * 5/9 + 273.15;
            strcpy(temp1, "Fahrenheit");
        } else if (medida1 == 3){
            saida = valor;
            strcpy(temp1, "Kelvin");
        } else {
            saida = valor * 5/9;
            strcpy(temp1, "Rankine");
        }
    } else {
        if (medida2 == 1){
            saida = valor - 273.15;
            strcpy(temp2, "Celsius");
        } else if (medida2 == 2){
            saida = (valor - 273.15) * 9/5 + 32;
            strcpy(temp2, "Fahrenheit");
        } else if (medida2 == 3){
            saida = valor;
            strcpy(temp2, "Kelvin");
        } else {
            saida = valor * 9/5;
            strcpy(temp2, "Rankine");
        }
    }
    return saida;
}


int main(){
    int medida_inicial, medida_final, resultado_medida_inicial, resultado_medida_final, resultado_valor;
    float valor_digitado, kelvin_check, resultado;
    int reiniciar = 1;
    char temperatura1[20], temperatura2[20];
    printf("PROGRAMA PARA CONVERTER VALORES DE TEMPERATURA\n\n");
    
    while (reiniciar){
        printf("Digite o valor ser convertido: ");
        resultado_valor = scanf("%f",&valor_digitado);
        if (resultado_valor != 1){
            printf("O valor deve ser um número!\n\n");
            while (getchar() != '\n');
            continue;
        }

        while (true){ 
            medida_final = 0;
            printf("\n\n[1] Celsius;\n[2] Fahrenheit;\n[3] Kelvin;\n[4] Rankine.\n\nEscolha a medida desse valor: ");
            resultado_medida_inicial = scanf("%d", &medida_inicial);
            if (resultado_medida_inicial != 1 || medida_inicial < 1 || medida_inicial > 4){
                printf("Escolha fora da faixa prevista, tente novamente!\n\n");
                while (getchar() != '\n');
                continue;
            }
            
            kelvin_check = processamento(valor_digitado, medida_inicial, medida_final, temperatura1, temperatura2);
            
            if (kelvin_check < 0){
                printf("Seu valor, em Kelvin, está abaixo do zero absoluto. O que é impossível fisicamente. Tente novamente!\n\n");
                break;
            } else {
                while (true){
                    printf("\n\n[1] Celsius;\n[2] Fahrenheit;\n[3] Kelvin;\n[4] Rankine.\n\nAgora escolha a medida a ser convertida: ");
                    resultado_medida_final = scanf("%d", &medida_final);
                    if (resultado_medida_final != 1 || medida_final < 1 || medida_final > 4){
                        printf("Escolha fora da faixa prevista, tente novamente!\n\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    break;
                }
                if (medida_inicial == medida_final){
                    printf("\nAs medidas escolhidas não podem ser iguais!\n\n");
                    break;
                } else {
                    reiniciar = 0;
                    break;
                }
            }
        }
    }
    resultado = processamento(kelvin_check, medida_inicial, medida_final, temperatura1, temperatura2);
    printf("\n\n%.1fº %s, é precisamente %.1fº em %s!", valor_digitado, temperatura1, resultado, temperatura2);
    printf("\n\nPROGRAMA ENCERRADO");
    return 0;
}