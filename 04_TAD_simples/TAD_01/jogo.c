#include <stdio.h>
#include "jogo.h"


tJogo CriaJogo(){

    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}


void ComecaJogo(tJogo jogo){

    tJogador jogador = jogo.jogador1;

    while(AcabouJogo(jogo) == 0){

        jogo.tabuleiro = JogaJogador(jogador, jogo.tabuleiro);

        ImprimeTabuleiro(jogo.tabuleiro);

        if(VenceuJogador(jogador, jogo.tabuleiro) == 1){

            printf("JOGADOR %d Venceu!\n", jogador.id);

            return;
        }

        if(jogador.id == ID_JOGADOR_1)
            jogador = jogo.jogador2;

        else
            jogador = jogo.jogador1;
    }

    printf("Sem vencedor!\n");
}


int AcabouJogo(tJogo jogo){

    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro) == 0)
        return 1;

    return 0;
}


int ContinuaJogo(){

    char continuar;

    printf("Jogar novamente? (s,n)\n");
    scanf(" %c", &continuar);

    if(continuar == 's')
        return 1;

    return 0;
}