#include <stdio.h>
#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador)
{
    tJogador jogador;

    if (idJogador == ID_JOGADOR_1)
        jogador.id = ID_JOGADOR_1;
    else
        jogador.id = ID_JOGADOR_2;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{

    int peca;

    if (jogador.id == ID_JOGADOR_1)
        peca = PECA_1;
    else
        peca = PECA_2;
    printf("Jodador %d\n", ID_JOGADOR_1);
    tJogada jogada = LeJogada();

    while (EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 0 || EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y) == 0)
    {

        if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 0)
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d])!\n", jogada.x, jogada.y);

        if (EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y) == 0)
            printf("Posicao invalida (OCUPADA - [%d,%d])\n", jogada.x, jogada.y);

        jogada = LeJogada();
    }
    printf("Jogada [%d, %d]\n", jogada.x, jogada.y);

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, jogada.x, jogada.y);

    if (VenceuJogador(jogador, tabuleiro) == 1)
        printf("Jogador %d Venceu!", jogador.id);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    char peca;

    if (jogador.id == ID_JOGADOR_1)
        peca = 'X';
    else
        peca = '0';

    if ((tabuleiro.posicoes[0][0] && tabuleiro.posicoes[1][1] && tabuleiro.posicoes[2][2]) == peca) // verifica na diagonal principal
        return 1;

    else if ((tabuleiro.posicoes[0][2] && tabuleiro.posicoes[1][1] && tabuleiro.posicoes[2][0]) == peca) // verifica na diagonal secundária
        return 1;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        int j = 0;

        if ((tabuleiro.posicoes[i][j] && tabuleiro.posicoes[i][j + 1] && tabuleiro.posicoes[i][j + 2]) == peca) // verifica linhas
            return 1;
    }

    for (int j = 0; j < TAM_TABULEIRO; j++)
    {

        int i = 0;

        if ((tabuleiro.posicoes[i][j] && tabuleiro.posicoes[i + 1][j] && tabuleiro.posicoes[i + 2][j]) == peca) // verifica colunas
            return 1;
    }

    return 0;
}