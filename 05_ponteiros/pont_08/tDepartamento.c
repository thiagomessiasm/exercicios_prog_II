#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"



tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ){

    tDepartamento d;
    strcpy(d.curso1, curso1);
    strcpy(d.curso2, curso2);
    strcpy(d.curso3, curso3);
    strcpy(d.nome, nome);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    strcpy(d.diretor, diretor);

    return d;

}



void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\n");
    printf("Departamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);

    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);

    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);

    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);

    float mediaCursos = (depto.m1 + depto.m2 + depto.m3) / 3.0;
    printf("\tMedia dos cursos: %.2f\n", mediaCursos);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_depto, int num_deptos){
    for(int i = 0; i < num_deptos - 1; i++){
        for(int j = 0; j < num_deptos - 1 - i; j++){
            float media1 = (vetor_depto[j].m1 + vetor_depto[j].m2 + vetor_depto[j].m3) / 3.0;
            float media2 = (vetor_depto[j+1].m1 + vetor_depto[j+1].m2 + vetor_depto[j+1].m3) / 3.0;

            if(media1 < media2){  
                tDepartamento dTemp = vetor_depto[j];
                vetor_depto[j] = vetor_depto[j+1];
                vetor_depto[j+1] = dTemp;
            }
        }
    }
}