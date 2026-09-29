#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botao.h"

void SetarTexto(Botao *b, char *novoTexto){

    strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte){

    b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novaCor){
    strcpy(b->corHex, novaCor);
}

void SetarTipo(Botao *b, int novoTipo){

    b->tipo = novoTipo;
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)){
    Botao b;
    strcpy(b.texto, texto);
    b.tamFonte = tamFonte;
    strcpy(b.corHex, cor);
    b.tipo = tipo;
    b.executa = executa;
    return b;
}

void ExecutaBotao(Botao b){

    if(b.tipo < CLICK || b.tipo > HOVER)
        exit(EXIT_FAILURE);

    else if(b.tipo == CLICK){
        printf("- Executando o botao com evento de click\n");
        
    }
    else if(b.tipo == LONGO_CLICK){
        printf("- Executando o botao com evento de longo click\n");
        
    }
    else if(b.tipo == HOVER){
        printf("- Executando o botao com evento de hover\n");
        
    }

    b.executa();

}

void DesenhaBotao(Botao b, int idx){
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}