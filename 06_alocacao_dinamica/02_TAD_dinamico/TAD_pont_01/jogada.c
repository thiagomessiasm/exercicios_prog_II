#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada* CriaJogada(){

    tJogada *j = (tJogada *)malloc(sizeof(tJogada));

    if(j == NULL){

        printf("ERRO DE ALOCACAO");
        exit(1);
    }

    j->sucesso = 0;

    return j;
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d", &jogada->x, &jogada->y) == 2)
    jogada->sucesso = 1;
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    if(jogada->sucesso == 1)
        return 1;
    return 0;
}