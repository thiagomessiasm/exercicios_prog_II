#include <stdlib.h>
#include <stdio.h>
#include "utils_char2.h"
/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao(){

    char *vetor = (char *)malloc((TAM_PADRAO + 1) * sizeof(char));

    if(vetor == NULL){
        printf("ERRO NA ALOCACAO\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){

    int novoTamanho = tamanhoantigo + TAM_PADRAO;

    vetor = (char *)realloc(vetor, (novoTamanho + 1) * sizeof(char));

    if(vetor == NULL){
        free(vetor);
        printf("ERRO NA ALOCACAO\n");
        exit(EXIT_FAILURE);
    }

    for(int i = tamanhoantigo; i < novoTamanho; i++)
        vetor[i] = '_';

    vetor[novoTamanho] = '\0';

    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){

    int i = 0;
    while (1) {

        scanf("%c", &vetor[i]);
        
        if (vetor[i] == '\n'){
                vetor[i] = '_';   
            break;
        }

        if (i >= (*tamanho-1)) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho = *tamanho + TAM_PADRAO;
        }
    
        i++;
    }

    return vetor;
}

void ImprimeString(char *vetor){

    printf("%s\n", vetor);
}


void LiberaVetor(char *vetor){

    free(vetor);
}
