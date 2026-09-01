#include <stdio.h>
#include <jogo.h>

tJogo CriaJogo(){
    
    tJogo jogo;
    
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    
    return jogo;
}

void ComecaJogo(tJogo jogo){

    tJogador jogador = jogo.jogador1;
    jogo.tabuleiro = JogaJogador(jogador, jogo.tabuleiro);
    int fim = 0;
    while (fim == 0){
        
        if(jogador.id == ID_JOGADOR_1)
            jogador = jogo.jogador2;
        else
            jogador = jogo.jogador1;

        jogo.tabuleiro = JogaJogador(jogador, jogo.tabuleiro);

        fim = AcabouJogo(jogo);
    }



}

int AcabouJogo(tJogo jogo){
    
    tJogador jogador = jogo.jogador1;
    
    if(VenceuJogador(jogador, jogo.tabuleiro) == 1){
        printf("Jogador 1 Venceu!");
        return 1;
    }
    
    else{
        jogador = jogo.jogador2;
     
        if(VenceuJogador(jogador, jogo.tabuleiro) == 1)
            printf("Jogador 2 Venceu!");
            return 1;    
    }

    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro) == 0){
        printf("Sem vencedor!");
        return 1;
    }
          
    return 0;

}

int ContinuaJogo(){
    int caracter;
    
    printf("Jogar novamente? (s,n)\n");
    scanf("%c", &caracter);

    if(caracter == 's')
        return 1;
    else
        return 0;
}
