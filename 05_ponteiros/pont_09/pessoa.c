#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa p;
    p.nome[0] = '\0';
    p.pai = NULL;
    p.mae = NULL;
    return p;
}

void LePessoa(tPessoa *pessoa){
    getchar();
    scanf("%[^\n]", pessoa->nome);
    
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL || pessoa->mae != NULL)
        return 1;
    else
        return 0;
}

void ImprimePessoa(tPessoa *pessoa){

    if(VerificaSeTemPaisPessoa(pessoa) == 1){
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai != NULL)
            printf("PAI: %s\n", pessoa->pai->nome);
        else
            printf("PAI: NAO INFORMADO\n");

        if(pessoa->mae != NULL)
            printf("MAE: %s\n\n", pessoa->mae->nome);
        else
            printf("MAE: NAO INFORMADO\n\n");
    }

}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){

    int qtdFamilias = 0;
    scanf("%d", &qtdFamilias);

    int mae = 0, pai = 0, filho = 0;

    for(int i = 0; i < qtdFamilias; i++){
        scanf(" mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

        if(mae == -1)
            pessoas[filho].mae = NULL;
        else
            pessoas[filho].mae = &pessoas[mae];

        if(pai == -1)
            pessoas[filho].pai = NULL;
        else
            pessoas[filho].pai = &pessoas[pai];
    }
}
