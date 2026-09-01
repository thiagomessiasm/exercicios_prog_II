#include <stdio.h>
#include "jogada.h"

tJogada LeJogada(){

    tJogada jogada;
    jogada.sucesso = 0;

    do {     
        scanf("%d %d", &jogada.x, &jogada.y);

    } while (scanf("%d %d", &jogada.x, &jogada.y) != 2);

    jogada.sucesso = 1;
    
    return jogada;
}


int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.sucesso == 1)
        return 1;
    return 0;
}

