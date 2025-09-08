/*   07/08   */

#include <stdio.h>
#include <math.h>
#include <string.h>



int main()
{
    int perimetro_retangulo()
    {
        float base, altura, perimetro;
        printf("PROGRAMA PARA CALCULAR PERIMETRO DE RETANGULO \n \n");
        printf("Digite, em cm, a base: ");
        scanf("%f",&base);
        printf("Digite, em cm, a altura: ");
        scanf("%f",&altura);
        perimetro = 2*(base+altura);
        printf("\nO perimetro dum retangulo com base %.1fcm e altura %.1fcm vale %.1fcm \n \n", base, altura, perimetro);
        printf("PROGRAMA ENCERRADO\n");
    
        return 0;
    }
    perimetro_retangulo();
    
    
    
    
    int perimetro_triangulo()
    {
        float lado1, lado2, lado3, perimetro;
        printf("PROGRAMA PARA CALCULAR PERIMETRO DE TRIANGULO \n \n");
        printf("Digite, em cm, o primeiro lado: ");
        scanf("%f",&lado1);
        printf("Digite, em cm, o segundo lado: ");
        scanf("%f",&lado2);
        printf("Digite, em cm, o terceiro lado: ");
        scanf("%f",&lado3);
        perimetro = lado1+lado2+lado3;
        printf("\nO perimetro dum triangulo com lados %.1fcm, %.1fcm e %.1fcm. Vale %.1fcm. \n \n", lado1, lado2, lado3, perimetro);
        printf("PROGRAMA ENCERRADO\n");
    
        return 0;
    }
    perimetro_triangulo();
    
    
    
    
    int area_retangulo()
    {
        float base, altura, area;
        printf("PROGRAMA PARA CALCULAR AREA DE UM RETANGULO \n \n");
        printf("Digite, em cm, a base: ");
        scanf("%f",&base);
        printf("Digite, em cm, a altura: ");
        scanf("%f",&altura);
        area = base*altura;
        printf("\nA área de um retangulo com base %.1fcm e altura %.1fcm. Vale %.1fcm². \n \n", base, altura, area);
        printf("PROGRAMA ENCERRADO\n");
    
        return 0;
    }
    area_retangulo();
    
    
    
    int area_triangulo()
    {
        float base, altura, area;
        printf("PROGRAMA PARA CALCULAR AREA DE UM TRIANGULO \n \n");
        printf("Digite, em cm, a base: ");
        scanf("%f",&base);
        printf("Digite, em cm, a altura: ");
        scanf("%f",&altura);
        area = (base*altura)/2;
        printf("\nA área de um triangulo com base %.1fcm e altura %.1fcm. Vale %.1fcm². \n \n", base, altura, area);
        printf("PROGRAMA ENCERRADO\n");
    
        return 0;
    }
    area_triangulo();
}