#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"

struct Jogador{
    int id;
};

tJogador* CriaJogador(int idJogador){
    tJogador* jogador = (tJogador *)malloc(sizeof(tJogador));
    
    if(jogador == NULL)
        exit(1);
    
    jogador->id = idJogador;

    return jogador;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador){
    free(jogador);
}

/**
 * Verifica se a jogada foi lida corretamente, se a posição informada
 * é válida e se está livre no tabuleiro.
 *
 * @param jogada a jogada a ser verificada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se a jogada for válida, 0 caso contrário.
 */
int EhJogadaValida(tJogada* jogada, tTabuleiro* tabuleiro){

    if(!FoiJogadaBemSucedida(jogada)){
        printf("Jogada invalida!\n");
        return 0;
    }

    int x = ObtemJogadaX(jogada), y = ObtemJogadaY(jogada);

    if(!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        return 0;
    }

    else if(!EhPosicaoValidaTabuleiro(x, y)){
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        return 0;
    }

    return 1;
    
        
}

/**
 * Solicita e realiza uma jogada do jogador, repetindo a leitura
 * até que seja informada uma posição válida e livre no tabuleiro.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){

    tJogada *jogada = CriaJogada();
    printf("Jogador %d\n", jogador->id);
    LeJogada(jogada);

    while (!EhJogadaValida(jogada, tabuleiro)){
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
    }
    int x = ObtemJogadaX(jogada), y = ObtemJogadaY(jogada);
    printf("Jogada [%d,%d]!\n", x, y);
    MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
    DestroiJogada(jogada);
    
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    
    for(int i = 0; i < TAM_TABULEIRO; i++){
        
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, i, jogador->id) ==
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, i, jogador->id) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, i, jogador->id))

            return 1;

        else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 0, jogador->id) && 
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 1, jogador->id) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 2, jogador->id))

            return 1;
    }
    

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador->id) && 
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && 
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador->id))

        return 1;

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador->id) && 
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador->id) && 
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador->id))

        return 1;
    
    return 0;
}
