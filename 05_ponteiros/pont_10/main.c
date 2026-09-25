#include <stdio.h>
#include "pessoa.h"

int main(){

    int qtdPessoas = 0;

    scanf("%d", &qtdPessoas);

    tPessoa pessoas[qtdPessoas];

    for(int i = 0; i < qtdPessoas; i++){
        
        tPessoa p = CriaPessoa();
        LePessoa(&p);

        pessoas[i] = p;

    }

    AssociaFamiliasGruposPessoas(pessoas, qtdPessoas);

    for(int i = 0; i < qtdPessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }
}