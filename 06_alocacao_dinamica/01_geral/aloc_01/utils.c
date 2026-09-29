#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *CriaVetor(int tamanho){

    int *vet = (int *) malloc (tamanho * sizeof(int));
     
    if(vet == NULL){
        printf("Erro na alocacao\n");
        exit(EXIT_FAILURE);
    }


    return vet;
}

void LeVetor(int *vetor, int tamanho){

    for(int i = 0; i < tamanho; i++){

        scanf("%d ", &vetor[i]);
        ;
    }
}

float CalculaMedia(int *vetor, int tamanho){

    int soma = 0;
    float media = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }

    media = (float)soma/tamanho;

    return media;
}

void LiberaVetor(int *vetor){
    free(vetor);
}