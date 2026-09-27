#include <stdio.h>
#include "data.h"


void InicializaDataParam( int dia, int mes, int ano, tData *data){

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}


void LeData( tData *data ){

    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
    getchar();

    if(data->mes > 12)
        data->mes = 12;
    if(data->dia > InformaQtdDiasNoMes(data))
        data->dia = InformaQtdDiasNoMes(data);
}


void ImprimeData( tData *data ){
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}


int EhBissexto( tData *data ){
    if(data->ano % 4 == 0)
        return 1;
    return 0;
}


int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 1)
        return 31;

    else if(data->mes == 2 && EhBissexto(data))
        return 29;

    else if(data->mes == 2)
        return 28;

    else if(data->mes >= 3 && data->mes < 8){
        if((data->mes % 2) == 0)
            return 30;
        return 31;
    }

    else if(data->mes >= 8 && data->mes <= 12){
        if((data->mes % 2) == 0)
            return 31;
        return 30; 
    }
}


void AvancaParaDiaSeguinte( tData *data ){

    if(data->dia < InformaQtdDiasNoMes(data) && data->mes <= 12)
        data->dia++; // avança um dia no mês

    else if(data->dia == InformaQtdDiasNoMes(data) && data->mes < 12){
        data->dia = 1;
        data->mes++;
    } // avança um mês no ano

    else if(data->dia == InformaQtdDiasNoMes(data) && data->mes == 12){
        data->dia = 1;
        data->mes = 1;
        data->ano++; 
    } // avança um ano
}

int EhIgual( tData *data1, tData *data2 ){
    if(data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano)
        return 1;
    return 0;
}