#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"




tJogador* CriaJogador(int idJogador){

    tJogador *jog = (tJogador *)malloc(sizeof(tJogador));

    if(jog == NULL){
        printf("ERRO DE ALOCACAO\n");
        exit(1);
    }

    jog->id = idJogador;
    return jog;

}


void DestroiJogador(tJogador* jogador){
    free(jogador);
}


void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){

    tJogada *jogada = CriaJogada();

    int x, y;

    while (1){

        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
        
        if(!FoiJogadaBemSucedida(jogada)){

            printf("Formato invalido!\n");
            continue;
        }

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        

        if(!EhPosicaoValidaTabuleiro(x, y)){
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }

        if(!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x,y);
            continue;
        }

        printf("Jogada [%d,%d]!\n", x, y);
        MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);

        break;

    }

    DestroiJogada(jogada);
}



int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){

    char pecaJogador;

    if (jogador->id == ID_JOGADOR_1) {
        pecaJogador = tabuleiro->peca1;
    } else {
        pecaJogador = tabuleiro->peca2;
    }

    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        
        if (tabuleiro->posicoes[i][0] == pecaJogador && 
            tabuleiro->posicoes[i][1] == pecaJogador && 
            tabuleiro->posicoes[i][2] == pecaJogador) {
            return 1;
        }
        
        if (tabuleiro->posicoes[0][i] == pecaJogador && 
            tabuleiro->posicoes[1][i] == pecaJogador && 
            tabuleiro->posicoes[2][i] == pecaJogador) {
            return 1;
        }
    }

    
    if (tabuleiro->posicoes[0][0] == pecaJogador && 
        tabuleiro->posicoes[1][1] == pecaJogador && 
        tabuleiro->posicoes[2][2] == pecaJogador) {
        return 1;
    }
    
    if (tabuleiro->posicoes[0][2] == pecaJogador && 
        tabuleiro->posicoes[1][1] == pecaJogador && 
        tabuleiro->posicoes[2][0] == pecaJogador) {
        return 1;
    }

    return 0;
}