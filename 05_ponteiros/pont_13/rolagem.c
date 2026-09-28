#include <stdio.h>
#include <string.h>
#include "rolagem.h"


void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){

    int numMensagens = 0;
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG] = {0};

    FuncMsg(msg, &numMensagens);


    char frase[NUM_MAX_MSGS * TAM_MAX_MSG] = {0};

    int pos = 0; // posição da frase

    for (int i = 0; i < numMensagens; i++){
        for(int j = 0; msg[i][j] != '\0' && j < TAM_MAX_MSG; j++){
            frase[pos++] = msg[i][j]; //faz com que frase na posicaço pos receba o caracater de msg[j][k]
                                      // em seguida encrmenta 1 em pos
        }
    }

    int tamFrase = strlen(frase);
    int aux = 0, qtdDeslocamentoPainel = 0;

    while (qtdDeslocamentoPainel < tempoFim){

        if(qtdDeslocamentoPainel > 0)
            printf("\033[H\033[J"); //Limpa o terminal

        for(int i = 0; i < tamanhoDisplay; i++){

            printf("%c", frase[(i + aux) % tamFrase]); // (i + aux) % tamFrase garante que frase nunca vai acessar
                                                       // uma posição maior ou igual o tamanho da frase
        }
        printf("\n");
      
        aux = (aux + 1)%tamFrase; // garante que aux vá de 0 a tamFrase - 1

        qtdDeslocamentoPainel++;     
    }

    printf("\033[H\033[J");
    
}
