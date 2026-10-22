#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

struct Tabuleiro{
    char peca1, peca2, pecaVazia;
    char** posicoes;
};

tTabuleiro* CriaTabuleiro(){
    tTabuleiro* tabuleiro = (tTabuleiro *)malloc(sizeof(tTabuleiro));
    if(tabuleiro == NULL)
        exit(1);

    tabuleiro->posicoes = (char**)malloc( TAM_TABULEIRO * sizeof(char*));
    
    if(tabuleiro->posicoes == NULL){
        free(tabuleiro);
        exit(1);
    }

    for(int i = 0; i < TAM_TABULEIRO; i++){

        tabuleiro->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));
        
        if(tabuleiro->posicoes[i] == NULL){

            for(int j = 0; j < i; j++){
                free(tabuleiro->posicoes[j]);
            }
            free(tabuleiro->posicoes);
            free(tabuleiro);
    
        }

    }

    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazia = '-';

    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazia;
        }
    }
    return tabuleiro;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro){
    
    for(int i = 0; i < TAM_TABULEIRO; i++){
        free(tabuleiro->posicoes[i]);
    }

    free(tabuleiro->posicoes);
    free(tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    char c;
    if(peca == PECA_1)
        c = tabuleiro->peca1;
    else if(peca == PECA_2)
        c = tabuleiro->peca2;

    tabuleiro->posicoes[y][x] = c;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazia)
                return 1;
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    char c;
    
    if(peca == PECA_1)
        c = tabuleiro->peca1;
    else if(peca == PECA_2)
        c = tabuleiro->peca2;
    
    if(tabuleiro->posicoes[y][x] == c)
        return 1;

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazia)
        return 1;
    return 0;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y){
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO))
        return 1;
    return 0;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}
