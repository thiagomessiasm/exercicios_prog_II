#include <stdio.h>
#include <string.h>
#include "jogador.h"
#include "jogada.h"


/*
typedef struct{
    int id;
} tJogador;
*/

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;

}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    
    char peca;

    if(jogador.id == ID_JOGADOR_1)
        peca = tabuleiro.peca1;

    else if(jogador.id = ID_JOGADOR_2)
        peca = tabuleiro.peca2;

    printf("Jogador %d\n", jogador.id);

    tJogada jogada = LeJogada();

    
    while(EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y) == 0 || EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 0){
        
        if(EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 0)
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",jogada.x, jogada.y);

        else if(EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y) == 0 )
        
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);

        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();

    }





    printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);

    tabuleiro.posicoes[jogada.y][jogada.x] = peca;
        

    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca;
    
    if(jogador.id == ID_JOGADOR_1)
        peca = tabuleiro.peca1;
    
    else if (jogador.id == ID_JOGADOR_2)
        peca = tabuleiro.peca2;

    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca 
        && tabuleiro.posicoes[2][2] == peca)
        return 1;

    else if (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca 
            && tabuleiro.posicoes[2][0] == peca)
        return 1;    

    for(int i = 0; i < TAM_TABULEIRO; i++){

        if(tabuleiro.posicoes[i][0] == peca && tabuleiro.posicoes[i][1] == peca 
            && tabuleiro.posicoes == peca)
            return 1;

        else if (tabuleiro.posicoes[0][i] == peca && tabuleiro.posicoes[1][i] == peca 
                  && tabuleiro.posicoes[2][i] == peca)

            return 1;
        
    }
    
    return 0;
}