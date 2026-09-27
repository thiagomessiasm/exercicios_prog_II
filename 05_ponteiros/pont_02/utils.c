#include<stdio.h>
#include "utils.h"


void LeIntervalo(int * m, int * n){
    getchar();
    scanf("%d %d", m, n);

}

int EhPrimo(int n){

    if(n < 2) // Qualquer número menor do que 2 não é primo
        return 0;
    
    else if(n == 2) // menor primo
        return 1;

    for(int i = 2; i < n; i++){

        if((n%i == 0)) // se um número inteiro for divisível por qualquer outro número que não seja 1 ou ele mesmo, não é primo

            return 0;
    }

    return 1; // se  passou pelo laço, então o número é primo

}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){

    if((m == n) && EhPrimo(m)){

        *menor = m;
        *maior = *menor;
    }

    else{

        for(int i = m; i < n; i++){ //avalia os números de m até n
            if(EhPrimo(i) == 1){
                *menor = i;
                break;
            }
        }

        for (int i = n; i > m; i--){ //avalia os números de n até m
            if(EhPrimo(i) == 1){
                *maior = i;
                break;
            }
        }
    }

}