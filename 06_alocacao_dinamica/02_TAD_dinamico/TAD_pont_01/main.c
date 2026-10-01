#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"



int main() {
    tJogo* jogo = CriaJogo();
    
    do {

        ComecaJogo(jogo);
        
        if (ContinuaJogo() == 1) {
            DestroiTabuleiro(jogo->tabuleiro);
            jogo->tabuleiro = CriaTabuleiro();
        } 
        else 
            break;
        
    } while (1);

    DestroiJogo(jogo);
    return 0;
}
