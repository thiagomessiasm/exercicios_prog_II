#include <stdio.h>
#include "vetor.h"

int soma(int num1, int num2);

int produto(int num1, int num2);

int main(){

    Vetor vet;
    LeVetor(&vet);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vet, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vet, produto));

    return 0;
}

int soma(int num1, int num2){
    return num1 + num2;
}

int produto(int num1, int num2){
    return num1 * num2;
}