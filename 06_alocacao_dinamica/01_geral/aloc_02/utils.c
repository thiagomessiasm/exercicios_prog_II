#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int **CriaMatriz(int linhas, int colunas){

    int **matriz = (int **)malloc(linhas * sizeof(int *));

    if(matriz == NULL){
        printf("ERRO NA ALOCACAO\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < linhas; i++){

        matriz[i] = (int *)malloc(colunas * sizeof(int));

        if(matriz[i] == NULL){
            printf("ERRO NA ALOCACAO\n");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}


void LiberaMatriz(int **matriz, int linhas){

    if(matriz != NULL){

        for(int i = 0; i < linhas; i ++){
            free(matriz[i]);
        }

        free(matriz);
    }

}

void LeMatriz(int **matriz, int linhas, int colunas){

    for(int i = 0; i < linhas; i++){

        for(int j = 0; j < colunas; j++){

            scanf("%d ", &matriz[i][j]);
        }
    }
}


void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    
    for(int i = 0; i < colunas; i++){

        for(int j = 0; j < linhas; j++){

            printf("%d ", matriz[j][i]);
        }

        printf("\n");
    }
}
