#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){

    int tamanho;
    scanf("%d", &tamanho);
    getchar();

    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    printf("%.2f", CalculaMedia(vetor, tamanho));
    LiberaVetor(vetor);

    return 0;
}