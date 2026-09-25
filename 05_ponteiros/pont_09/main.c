#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main(){
    
    int qtdPessoas;
    scanf("%d", &qtdPessoas);

    tPessoa pessoas[qtdPessoas];

    for(int i = 0; i < qtdPessoas; i++){

        tPessoa p;
        p = CriaPessoa();
        LePessoa(&p);

        pessoas[i] = p;

    }

    AssociaFamiliasGruposPessoas(pessoas);


    for(int i = 0; i < qtdPessoas; i++){

        ImprimePessoa(&pessoas[i]);
    }


}