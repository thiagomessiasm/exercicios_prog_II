#include <stdio.h>
#include "tabuleiro.h"


/*

typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

*/


/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro(){
    
    tTabuleiro tabuleiro;

    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    
    if(peca = PECA_1)
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    else
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;

    return tabuleiro; 
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    
    for(int i = 0; i < TAM_TABULEIRO; i++){
        
        for(int j = 0; j < TAM_TABULEIRO; j++){
            
            if(tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio)
                return 1;
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){

    if(peca == PECA_1){
        if(tabuleiro.posicoes[y][x] == tabuleiro.peca1)
            return 1;
    }

    else if(peca == PECA_2){
        if(tabuleiro.posicoes[y][x] == tabuleiro.peca2)
            return 1;       
    }

    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio)
        return 1;
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if((x || y) < 0 || (x || y) > TAM_TABULEIRO -1)
        return 0;
    return 1;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){

    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }

}