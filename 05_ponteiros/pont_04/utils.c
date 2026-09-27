#include <stdio.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho){
    
    for(int i = 0; i < tamanho; i++){
        getchar();
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int soma = 0;
    *menor = array[0];
    *maior = array[0];

    for(int i = 0; i < tamanho; i++){

        if(*menor > array[i])
            *menor = array[i];
        else if(*maior < array[i])
            *maior = array[i];
        
        soma += array[i];
    }

    *media = (float)soma/tamanho;

}