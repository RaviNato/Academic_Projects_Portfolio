/*   12/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



int perimetro_retangulo(){
    float lado1, lado2, lado3, lado4, perimetro;
    int resultado_lado1, resultado_lado2, resultado_lado3, resultado_lado4;
    printf("PROGRAMA PARA CALCULAR PERIMETRO DE RETANGULO \n \n");
    while (true){
        printf("Digite, em cm, a base: ");
        resultado_lado1 = scanf("%f",&lado1);
        if (resultado_lado1 != 1 || lado1 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, a altura: ");
        resultado_lado2 = scanf("%f", &lado2);
        if (resultado_lado2 != 1 || lado2 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    perimetro = 2*(lado1+lado2);
    printf("\nO perimetro dum retangulo com base %.1fcm e altura %.1fcm vale %.1fcm  ", lado1, lado2, perimetro);
    while (getchar() != '\n');
    getchar();

    return 0;
}


int perimetro_triangulo(){
    float lado1, lado2, lado3, lado4, perimetro;
    int resultado_lado1, resultado_lado2, resultado_lado3, resultado_lado4;
    printf("PROGRAMA PARA CALCULAR PERIMETRO DE TRIANGULO \n \n");
    while (true){
        printf("Digite, em cm, o primeiro lado: ");
        resultado_lado1 = scanf("%f",&lado1);
        if (resultado_lado1 != 1 || lado1 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, o segundo lado: ");
        resultado_lado2 = scanf("%f",&lado2);
        if (resultado_lado2 != 1 || lado2 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, o terceiro lado: ");
        resultado_lado3 = scanf("%f",&lado3);
        if (resultado_lado3 != 1 || lado3 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    perimetro = lado1+lado2+lado3;
    printf("\nO perimetro dum triangulo com lados %.1fcm, %.1fcm e %.1fcm. Vale %.1fcm.  ", lado1, lado2, lado3, perimetro);
    while (getchar() != '\n');
    getchar();

    return 0;
}


int perimetro_trapezio(){
    float lado1, lado2, lado3, lado4, perimetro;
    int resultado_lado1, resultado_lado2, resultado_lado3, resultado_lado4;
    printf("PROGRAMA PARA CALCULAR PERIMETRO DE TRAPÉZIO \n \n");
    while (true){
        printf("Digite, em cm, o primeiro lado: ");
        resultado_lado1 = scanf("%f",&lado1);
        if (resultado_lado1 != 1 || lado1 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, o segundo lado: ");
        resultado_lado2 = scanf("%f",&lado2);
        if (resultado_lado2 != 1 || lado2 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, o terceiro lado: ");
        resultado_lado3 = scanf("%f",&lado3);
        if (resultado_lado3 != 1 || lado3 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite, em cm, o quarto lado: ");
        resultado_lado4 = scanf("%f",&lado4);
        if (resultado_lado4 != 1 || lado4 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    perimetro = lado1+lado2+lado3+lado4;
    printf("\nO perimetro dum trapézio com lados %.1fcm, %.1fcm, %.1fcm e %.1fcm. Vale %.1fcm.  ", lado1, lado2, lado3, lado4, perimetro);
    while (getchar() != '\n');
    getchar();

    return 0;
}


int perimetro_circulo(){
    float lado1, lado2, lado3, lado4, perimetro;
    int resultado_lado1, resultado_lado2, resultado_lado3, resultado_lado4;
    printf("PROGRAMA PARA CALCULAR PERIMETRO DE CÍRCULO \n \n");
    while (true){
        printf("Digite, em cm, o raio do círculo: ");
        resultado_lado1 = scanf("%f",&lado1);
        if (resultado_lado1 != 1 || lado1 <= 0) {
            printf("Sua resposta deve ser um número real positivo! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    perimetro = 2*acos(-1.0)*lado1;
    printf("\nO perimetro dum círculo com raio %.1fcm. Vale %.1fcm.  ", lado1, perimetro);
    while (getchar() != '\n');
    getchar();

    return 0;
}


int main(){
    int c;
    printf("PROGRAMA PARA CALCULAR PERIMETROS\n\n");
    int escolha;
    while (true){
        printf("Escolha qual forma a calcular:\n\n[1] Calcular perimetro de retângulo;\n[2] Calcular perimetro de triângulo;\n[3] Calcular perimetro de trapézio;\n[4] Calcular perimetro de círculo;\n[5] Encerrar programa.\n\n");
        c = scanf("%d", &escolha);
        if (c != 1 || escolha < 1 || escolha > 5){
            printf("Escolha fora da faixa prevista, tente novamente!\n\n");
            while (getchar() != '\n');
            continue;
        }
        else if (escolha == 1) {
        perimetro_retangulo();
        } else if (escolha == 2) {
        perimetro_triangulo();
        } else if (escolha == 3) {
        perimetro_trapezio();
        } else if (escolha == 4) {
        perimetro_circulo();
        } else {
        printf("\nPROGRAMA ENCERRADO");
        break;
        }
    }
    return 0;
}