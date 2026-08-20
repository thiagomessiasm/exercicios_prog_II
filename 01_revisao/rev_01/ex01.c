#include <stdio.h>
#include <math.h>

float calulaDistancia(float x1, float y1, float x2, float y2);

float calulaDistancia(float x1, float y1, float x2, float y2){

    float quadradoX, quadradoY, soma, distancia;

    quadradoX = (x1-x2)*(x1-x2);
    quadradoY = (y1-y2)*(y1-y2);

    soma = quadradoX + quadradoY;

    distancia = sqrt(soma);

    return distancia;
}

int main(){

    float xDoAlvo, yDoAlvo, raioDoAlvo;
    float xDoDisparo, yDoDisparo, raioDoDisparo;
    float distancia;

    scanf("%f %f %f\n", &xDoAlvo, &yDoAlvo, &raioDoAlvo);
    scanf("%f %f %f",&xDoDisparo, &yDoDisparo, &raioDoDisparo);

    distancia = calulaDistancia(xDoAlvo, yDoAlvo, xDoDisparo, yDoDisparo);

    float somaDosRaios = raioDoAlvo + raioDoDisparo;

    if(distancia <= somaDosRaios)
        printf("ACERTOU");
    else
        printf("ERROU");

    return 0;
}