#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char.h"

char *CriaVetor(int tamanho){

    char *vetor = (char *)malloc((tamanho + 1) * sizeof(char));

    if(vetor == NULL){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < tamanho; i++){
        vetor[i] = '_';
    }

    vetor[tamanho] = '\0';

    return vetor;
}


void LeVetor(char *vetor, int tamanho){

    for(int i = 0; i < tamanho; i ++){

        scanf("%c", &vetor[i]);

        if(vetor[i] == '\n'){
            vetor[i] = '_';
                       
        }           
    }

}

void ImprimeString(char *vetor, int tamanho){

    printf("%s\n", vetor);

}


void LiberaVetor(char *vetor){

    free(vetor);
    
}

