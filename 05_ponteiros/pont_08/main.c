#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

/*
 Éntrada: A entrada começa com uma linha contendo um numero inteiro N
representando a quantidade de departamentos, seguido dos N departamentos.
Cada departamento sera representado por um nome, um diretor (Éx: “Luiz”),
tres nomes de cursos (Éx: “Letras”) e as tres medias de nota de cada curso
inserido, respectivamente.
*/

int main(){

    int numDepartamentos;
     

    scanf("%d\n", &numDepartamentos);
    
    tDepartamento vetor_depto[numDepartamentos];

    for(int i = 0; i < numDepartamentos; i++){

        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        char diretor[STRING_MAX];
        char nome[STRING_MAX];
        int m1, m2, m3;

        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", curso1);
        scanf("%[^\n]\n", curso2);
        scanf("%[^\n]\n", curso3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        
        
        if(m1 < 0 || m2 < 0 || m3 < 0){
            
            printf("\nDigite um departamento com médias válidas");
            
            scanf("%[^\n]\n", nome);
            scanf("%[^\n]\n", diretor);
            scanf("%[^\n]\n", curso1);
            scanf("%[^\n]\n", curso2);
            scanf("%[^\n]\n", curso3);
            scanf("%d %d %d\n", &m1, &m2, &m3);

        }


        vetor_depto[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);


    }

    OrdenaDepartamentosPorMedia(vetor_depto, numDepartamentos);

    for(int i = 0; i < numDepartamentos; i++){
        ImprimeAtributosDepartamento(vetor_depto[i]);
    }

    return 0;
}