#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10


/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */

tEleicao* InicializaEleicao(){
    tEleicao *eleicao = (tEleicao *)malloc(sizeof(tEleicao));
    if(eleicao == NULL){
        printf("erro na alocacao\n");
        exit(1);
    }

    eleicao->presidentes = NULL;
    eleicao->governadores = NULL;
    eleicao->eleitores = NULL;

    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosPresidente = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosGovernador = 0;

    eleicao->totalEleitores = 0;
    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;

    int qtdCandidatos = 0;
    scanf("%d", &qtdCandidatos);

    for(int i = 0; i < qtdCandidatos; i++){

        tCandidato *c = CriaCandidato();
        LeCandidato(c);

        if(ObtemCargo(c) == 'P'){
            eleicao->totalPresidentes++;
            eleicao->presidentes = (tCandidato **)realloc(eleicao->presidentes,eleicao->totalPresidentes * sizeof(tCandidato *));
            eleicao->presidentes[eleicao->totalPresidentes - 1] = c;
        }
        else if(ObtemCargo(c) == 'G'){
            eleicao->totalGovernadores++;
            eleicao->governadores = (tCandidato **)realloc(
                eleicao->governadores,
                eleicao->totalGovernadores * sizeof(tCandidato *)
            );
            eleicao->governadores[eleicao->totalGovernadores - 1] = c;
        }
        else {
            ApagaCandidato(c); // cargo inválido, descarta
        }
    }

    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao){

    for(int i = 0; i < eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);

    for(int i = 0; i < eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);

    for(int i = 0; i < eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);

    free(eleicao);
}


/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao){

    scanf("%d", &eleicao->totalEleitores);
    getchar();



    eleicao->eleitores = (tEleitor **)malloc(eleicao->totalEleitores * sizeof(tEleitor *));

    for(int i = 0; i < eleicao->totalEleitores; i++){

        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);

        int votoP = ObtemVotoPresidente(eleicao->eleitores[i]);
        int votoG = ObtemVotoGovernador(eleicao->eleitores[i]);

        //PRESIDENTE
        if(votoP == 0){
            eleicao->votosBrancosPresidente++;
        } else {
            int achou = 0;
            for(int p = 0; p < eleicao->totalPresidentes; p++){
                if(VerificaIdCandidato(eleicao->presidentes[p], votoP)){
                    IncrementaVotoCandidato(eleicao->presidentes[p]);
                    achou = 1;
                    break;
                }
            }
            if(!achou)
                eleicao->votosNulosPresidente++;
        }

        //GOVERNADOR
        if(votoG == 0){
            eleicao->votosBrancosGovernador++;
        } else {
            int achou = 0;
            for(int g = 0; g < eleicao->totalGovernadores; g++){
                if(VerificaIdCandidato(eleicao->governadores[g], votoG)){
                    IncrementaVotoCandidato(eleicao->governadores[g]);
                    achou = 1;
                    break;
                }
            }
            if(!achou)
                eleicao->votosNulosGovernador++;
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao){



    // Eleitor duplicado
    for(int i = 0; i < eleicao->totalEleitores; i++){
        for(int j = i + 1; j < eleicao->totalEleitores; j++){
            if(EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])){
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    //Presidente
    tCandidato *PresidenteEleito = NULL;

    if(eleicao->totalPresidentes > 0){
        
        PresidenteEleito = eleicao->presidentes[0];
        int totalVotosValidosP = ObtemVotos(eleicao->presidentes[0]);

        for(int i = 1; i < eleicao->totalPresidentes; i++){
            if(ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(PresidenteEleito))
                PresidenteEleito = eleicao->presidentes[i];

            totalVotosValidosP += ObtemVotos(eleicao->presidentes[i]);
        }

        int votosVencP = ObtemVotos(PresidenteEleito);

        // Verifica empate
        int empateP = 0;
        for(int i = 0; i < eleicao->totalPresidentes; i++){
            if(eleicao->presidentes[i] != PresidenteEleito && ObtemVotos(eleicao->presidentes[i]) == votosVencP){
                empateP = 1;
                break;
            }
        }

        if(empateP)
            printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");

        else {
            
            int invalidosP = eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente;
            
            if(votosVencP < invalidosP){
                printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
            }

            else{

                int totalVotosP = totalVotosValidosP + invalidosP;
                printf("- PRESIDENTE ELEITO: ");
                ImprimeCandidato(PresidenteEleito, CalculaPercentualVotos(PresidenteEleito, totalVotosP));
            }
        }
    }

    //Governador
    tCandidato *GovernadorEleito = NULL;

    if(eleicao->totalGovernadores > 0){

        int totalVotosValidosG = ObtemVotos(eleicao->governadores[0]);
        GovernadorEleito = eleicao->governadores[0];
        
        for(int i = 1; i < eleicao->totalGovernadores; i++){
            
            if(ObtemVotos(eleicao->governadores[i]) > ObtemVotos(GovernadorEleito))
                GovernadorEleito = eleicao->governadores[i];

            totalVotosValidosG += ObtemVotos(eleicao->governadores[i]);
        }

        int votosVencG = ObtemVotos(GovernadorEleito);

        int empateG = 0;

        for(int i = 0; i < eleicao->totalGovernadores; i++){
            if(eleicao->governadores[i] != GovernadorEleito && ObtemVotos(eleicao->governadores[i]) == votosVencG){
                empateG = 1;
                break;
            }
        }

        if(empateG)
            printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        
        else{

            int invalidosG = eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador;
            
            if(votosVencG < invalidosG)
                printf("- GOVERNADOR ELEITO: SEM DECISAO\n");

            else{

                int totalVotosG = totalVotosValidosG + invalidosG;
                printf("- GOVERNADOR ELEITO: ");
                ImprimeCandidato(GovernadorEleito, CalculaPercentualVotos(GovernadorEleito, totalVotosG));
            }
        }
    }

    // Nulos e brancos
    int totalNulos   = eleicao->votosNulosPresidente + eleicao->votosNulosGovernador;
    int totalBrancos = eleicao->votosBrancosPresidente + eleicao->votosBrancosGovernador;

    printf("- NULOS E BRANCOS: %d, %d\n", totalNulos, totalBrancos);
}