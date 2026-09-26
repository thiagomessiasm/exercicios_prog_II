#include <stdio.h>
#include "calculadora.h"

float adicao(float num1, float num2);

float subtracao(float num1, float num2);

float multiplicacao(float num1, float num2);

float divisao(float num1, float num2);

int main(){

    char op;
    float resultado;
    float num1, num2;

    scanf("%c", &op);
    

    while (op != 'f'){

        scanf(" %f %f", &num1, &num2);
        

        if (op == 'a'){
            resultado = Calcular(num1 , num2, adicao);
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
        }
        
        else if (op == 's'){
            resultado = Calcular(num1 , num2, subtracao);
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
        }
        
        else if (op == 'm'){
            resultado = Calcular(num1 , num2, multiplicacao);
            printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);
        }
        
        else if (op == 'd'){
            resultado = Calcular(num1 , num2, divisao);
            printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
        }

        scanf(" %c", &op);
        
    }

    return 0;
    
}

float adicao(float num1, float num2){
    return num1 + num2;
}

float subtracao(float num1, float num2){
    return num1 - num2;
}

float multiplicacao(float num1, float num2){
    return num1 * num2;
}

float divisao(float num1, float num2){
    if(num2 != 0)
        return num1/num2;
}