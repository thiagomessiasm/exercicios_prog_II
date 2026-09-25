#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa(){

    tPessoa p;
    p.nome[0] = '\0';
    p.mae = NULL;
    p.pai = NULL;
    p.irmao = NULL;

    return p;
}

void LePessoa(tPessoa *pessoa){

    getchar();
    scanf("%[^\n]", pessoa->nome);
    
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){

    if(pessoa->mae != NULL || pessoa->pai != NULL)
        return 1;
    else
        return 0;
}

void ImprimePessoa(tPessoa *pessoa){

    if(VerificaSeTemPaisPessoa(pessoa) == 1){

        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai != NULL)
            printf("PAI: %s\n", pessoa->pai);
        else
            printf("PAI: NAO INFORMADO\n");

        if(pessoa->mae != NULL)
            printf("MAE: %s\n", pessoa->mae);
        else
            printf("MAE: NAO INFORMADO\n");

        if(pessoa->irmao != NULL)
            printf("IRMAO: %s\n", pessoa->irmao);
        else
            printf("IRMAO: NAO INFORMADO");

        printf("\n");
    }
    


}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai)
        return 1;
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){

    int qtdAssociacoes = 0;

    scanf("%d", &qtdAssociacoes);
    getchar();

    int mae = 0, pai = 0, filho = 0;

    for(int i = 0; i < qtdAssociacoes; i++){

        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        getchar();

        if(mae == -1)
            pessoas[filho].mae = NULL;
        else
            pessoas[filho].mae = &pessoas[mae];
        
        if(pai == -1)
            pessoas[filho].pai = NULL;
        else
           pessoas[filho].pai = &pessoas[pai];

    }

    for(int i = 0; i < numPessoas; i++){

        for(int j = i+1; j < (numPessoas -1); j++){

            if( VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) == 1){

                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }

        }
    
    }


}