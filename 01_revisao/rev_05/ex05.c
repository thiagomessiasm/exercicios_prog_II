#include <stdio.h>

typedef struct posicao{
    int x, y;
}tPosicao;
int ehJogadaValida(int x, int y, int n, int campo[][n]);
tPosicao convertePosicao(int x, int y);
void leCampo(int linhas, int colunas, int campo[linhas][colunas]);
void realizaJogada(tPosicao pos, char comando, int n ,char campo[][n]);

void leCampo(int linhas, int colunas, int campo[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            scanf("%d", &campo[i][j]);
    }
}
int ehJogadaValida (int x, int y,int n, int campo[][n]){
    if(campo[x][y] == 0)
        return 0;
    else
        return 1;
}

tPosicao convertePosicao(int x, int y){
    tPosicao posicao;
    posicao.x= x - 1;
    posicao.y = y -1;
    return posicao;
}

void realizaJogada(tPosicao pos, char comando, int n ,char campo[][n]){
    if(comando == 'B')
        pos.x--;
    else if(comando == 'C')
        pos.x++;
    else if(comando == 'D')
        pos.y++;
    else
        pos.y--;

    campo[pos.x][pos.y];
}




int main(){

    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int campo[linhas][colunas];
    leCampo(linhas, colunas, campo);

    tPosicao posicao_inicial;
    scanf("%d %d", &posicao_inicial.x, &posicao_inicial.y);

    tPosicao posicao_final;
    scanf("%d %d", &posicao_final.x, &posicao_final.y);

    char comandos[5];
    scanf("%s\n", comandos);

    tPosicao posicao_atual;
    posicao_atual.x = posicao_inicial.x;
    posicao_atual.y = posicao_inicial.y;

    int i = 0;

    while ((campo[posicao_atual.x + 1][posicao_atual.y] == 0) || (campo[posicao_atual.x - 1][posicao_atual.y] == 0) || 
           (campo[posicao_atual.x][posicao_atual.y + 1] == 0) || (campo[posicao_atual.x][posicao_atual.y -1] == 0)){

        
        if(ehJogadaValida(posicao_atual.x, posicao_atual.y, colunas, campo)){
            realizaJogada(posicao_atual, comandos[i],colunas, campo);
            i = 0;
        }
        else
            i++;



    }
    

}
