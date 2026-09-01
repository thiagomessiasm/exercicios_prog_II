#include <stdio.h>
#include "jogada.h"
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

int main(){
    
    tJogo jogo;
    int continuar = 1;
    
    while (continuar == 1){
        jogo = CriaJogo();
        ComecaJogo(jogo);
        continuar = ContinuaJogo();
    }
        
}