#include <stdio.h>
#include "jogo.h"

/*
typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    
} tJogo;

*/

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo(){
    
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo){
    
    int acabou = 0, continuar = 1;

    tJogador jogador = jogo.jogador1;

    while (continuar == 1){

        JogaJogador(jogador,jogo.tabuleiro);

        ImprimeTabuleiro(jogo.tabuleiro);

        if(AcabouJogo(jogo) == 1){
            printf("Jogador %d venceu\n", jogador.id);
            continuar = ContinuaJogo();
            if(continuar == 0)
            acabou = 1;
        }

        if(jogador.id == 1)
            jogador = jogo.jogador2;
        else
            jogador = jogo.jogador1;

    }
    
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo){

    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro) == 1 || 
    VenceuJogador(jogo.jogador2,jogo.tabuleiro) == 1 || TemPosicaoLivreTabuleiro(jogo.tabuleiro) == 0)
        return 1;
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char continuar;

    printf("Jogar novamente? (s,n)\n");
    scanf("%c", &continuar);

    if(continuar == 's')
        return 1;
    return 0;
}