#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

tJogo* CriaJogo(){

    tJogo *jogo = (tJogo *)malloc(sizeof(tJogo));

    if (jogo == NULL) {
        printf("ERRO DE ALOCACAO\n");
        exit(1);
    }

    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(PECA_1);
    jogo->jogador2 = CriaJogador(PECA_2);

    return jogo;
}

void ComecaJogo(tJogo* jogo){

    tJogador* jogadorAtual = jogo->jogador1;

    while (1) {

        JogaJogador(jogadorAtual, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if (VenceuJogador(jogadorAtual, jogo->tabuleiro)){

            printf("JOGADOR %d Venceu!\n", jogadorAtual->id);
            break;
        }

        if (AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }

        if (jogadorAtual == jogo->jogador1)

            jogadorAtual = jogo->jogador2;
        
        else 
            jogadorAtual = jogo->jogador1;
        
    }
}



int AcabouJogo(tJogo* jogo){
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro))
        return 1;
    return 0;
}



int ContinuaJogo(){

    char opcao;

    printf("Jogar novamente? (s,n)\n");
   
    scanf(" %c", &opcao);
    while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
       scanf(" %c", &opcao); 
    }

    if(opcao == 's' || opcao == 'S')
        return 1;
    else
        return 0;
    
}


void DestroiJogo(tJogo* jogo){

    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}