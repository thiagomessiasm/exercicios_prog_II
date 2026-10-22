#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

int main(){
    

  
    float raio, CentroX, CentroY, pX, pY;
    scanf("%f %f %f %f %f", &CentroX, &CentroY, &raio, &pX, &pY);

    tPonto p1 = Pto_Cria(pX, pY);
    tCirculo c = Circulo_Cria(CentroX, CentroY, raio);
    printf("%d\n", Circulo_Interior(c, p1));

    Pto_Apaga(p1);
    Circulo_Apaga(c);
    
    return 0;
}