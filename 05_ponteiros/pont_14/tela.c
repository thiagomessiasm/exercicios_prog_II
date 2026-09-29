#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

Tela CriarTela(int altura, int largura){
    Tela t;
    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b){
    if(t->qntBotoes >= MAX_BOTOES){
        printf("Erro: tela cheia\n");
        exit(EXIT_FAILURE);
    }
    t->botoes[t->qntBotoes] = b;
    t->qntBotoes++;
}

void DesenhaTela(Tela t){
    printf("##################\n");
    for(int i = 0; i < t.qntBotoes; i++){
        DesenhaBotao(t.botoes[i], i);
    }
    printf("##################\n");
}

void OuvidorEventosTela(Tela t){

    int opcao = -1;

    printf("- Escolha sua acao: ");
    scanf("%d", &opcao);

    if(opcao < 0 || opcao > 2)
        exit(EXIT_FAILURE);
    ExecutaBotao(t.botoes[opcao]);
}