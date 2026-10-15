#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"

char *leString(){
    
    int tamanho = 0;
    char caracter;
    char *vetor = NULL;

    while (scanf("%c", &caracter) == 1 && caracter != ','){

        vetor = (char *)realloc(vetor, (tamanho + 1) * sizeof(char)); //aloca a quantidade de caracteres sem considerar o \0
        vetor[tamanho] = caracter;
        tamanho++;

    }

    vetor = (char *)realloc(vetor, (tamanho + 1) * sizeof(char)); // adicona uma unidade para guardar o \0
    vetor[tamanho] = '\0';

    return vetor;
    
}



tCandidato* CriaCandidato(){

    tCandidato *candidato = (tCandidato *)malloc(sizeof(tCandidato));
    candidato->nome = NULL;
    candidato->partido = NULL;
    candidato->id = -1;
    candidato->votos = 0;

    return candidato;

}

/**
 * @brief Apaga toda a memória alocada dinamicamente para guardar as informações de um candidato
 * @param candidato Ponteiro para o candidato que terá a memória desalocada
 * @return Candidato criado.
 */
void ApagaCandidato(tCandidato* candidato){

        free(candidato->nome);
        free(candidato->partido);
        free(candidato); 
}


void LeCandidato(tCandidato *candidato){
    getchar();
    candidato->nome = leString();
    getchar();
    candidato->partido = leString();
    getchar();
    scanf("%c,", &candidato->cargo);
    scanf(" %d", &candidato->id);
    

}


int VerificaIdCandidato(tCandidato *candidato, int id){
    if(candidato->id == id)
        return 1;
    return 0;
}


int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2){
    if(candidato1->id ==  candidato2->id)
        return 1;
    return 0;
}


char ObtemCargo(tCandidato* candidato){
    return candidato->cargo;
}


void IncrementaVotoCandidato(tCandidato* candidato){
    candidato->votos++;
}


int ObtemVotos(tCandidato* candidato){
    return candidato->votos;
}


float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){

    float percentual = ((float)candidato->votos/totalVotos) * 100;
    return percentual;
}


void ImprimeCandidato (tCandidato* candidato, float percentualVotos){

    printf("%s (%s), %d voto(s), %.2f%%\n", candidato->nome, candidato->partido, candidato->votos, percentualVotos);

}