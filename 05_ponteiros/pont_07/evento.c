#include <stdio.h>
#include "evento.h"


void cadastrarEvento(Evento* eventos, int* numEventos){

    if((*numEventos) < MAX_EVENTOS){
        Evento e;
        scanf("%[^\n]\n", e.nome);
        scanf("%d %d %d\n", &e.dia, &e.mes, &e.ano);

        eventos[*numEventos] = e;
        printf("Evento cadastrado com sucesso!\n");
        (*numEventos)++;
    }

    else
        printf("Limite de eventos atingido!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    
    if((*numEventos) == 0)
        printf("Nenhum evento cadastrado.\n");
    
    else{

        printf("Eventos cadastrados:\n");
        
        for(int i = 1; i < (*numEventos); i++){
            printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].ano);
        }
    }

}


void trocarDataEvento(Evento* eventos, int* numEventos){
    
    int i;

    scanf("%d", &i);
    
    if(i < (*numEventos)){
    
        int dia, mes, ano;
        scanf("%d %d %d", &dia, &mes, &ano);

        eventos[i].dia = dia;
        eventos[i].mes = mes;
        eventos[i].ano = ano;

        printf("Data modificada com sucesso!\n");

    }

}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){

    if((*indiceA) >= (*numEventos) || (*indiceB) >= (*numEventos))
        printf("Indices invalidos!");
    
    else{

        Evento temp = eventos[*indiceB];

        eventos[*indiceB] = eventos[*indiceA];

        eventos[*indiceA] = temp;

        printf("Eventos trocados com sucesso!");

    }

}


