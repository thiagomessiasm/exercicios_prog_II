#include <stdio.h>
#include <string.h>
#include "rolagem.h"

#define TAM_DISPLAY 30

void DefineMsg(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs) {
    
    scanf("%d", numMsgs);
    getchar(); 

    for (int i = 0; i < *numMsgs; i++) {
        scanf("%[^\n]\n", msg[i]);
    }
}

int main(void) {
    int tempoFim;
    scanf("%d", &tempoFim);
    RolaMsg(DefineMsg, TAM_DISPLAY, tempoFim);
    return 0;
}