#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

tTabuleiro* CriaTabuleiro(){

    tTabuleiro *tab = (tTabuleiro *)malloc(sizeof(tTabuleiro));

    if(tab == NULL){
        printf("ERRO DE ALOCACAO");
        exit(1);
    }

    tab->pecaVazio = '-';
    tab->peca1 = 'X';
    tab->peca2 = '0';

    tab->posicoes = (char **)malloc(TAM_TABULEIRO * sizeof(char *));

    if(tab->posicoes == NULL){

        DestroiTabuleiro(tab);
        printf("ERRO DE ALOCACAO");
        exit(1);
    }
    

    for(int i = 0; i < TAM_TABULEIRO; i++){

        tab->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));

        if(tab->posicoes[i] == NULL){

            DestroiTabuleiro(tab);
            printf("ERRO DE ALOCACAO");
            exit(1);

        }

        for(int j = 0; j < TAM_TABULEIRO; j++){

            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }

    return tab;
}


void DestroiTabuleiro(tTabuleiro* tabuleiro){

    for(int i = 0; i < TAM_TABULEIRO; i ++){
        free(tabuleiro->posicoes[i]);
    }

    free(tabuleiro->posicoes);

    free(tabuleiro);
}


void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){

    if(peca == PECA_1){
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
        
    }

    else if(peca == PECA_2){
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
        
    }
}


int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){

    for(int i = 0; i < TAM_TABULEIRO; i++){

        for(int j = 0; j < TAM_TABULEIRO; j ++){
            
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio)
                return 1;
        }
    }

    return 0;
}



int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){

    char caracter;
    if(peca == PECA_1)
        caracter = tabuleiro->peca1;
    else if(peca == PECA_2)
        caracter = tabuleiro->peca2;

    if(tabuleiro->posicoes[y][x] == caracter)
        return 1;
    return 0;
}



int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio)
        return 1;
    return 0;
}



int EhPosicaoValidaTabuleiro(int x, int y){
    if((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2))
        return 1;
    return 0;
}


void ImprimeTabuleiro(tTabuleiro* tabuleiro){

    for(int i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");

    }
}


