#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"
#include "eleitor.h"
#include "candidato.h"


int main(){
    tEleicao *e = InicializaEleicao();
    RealizaEleicao(e);
    ImprimeResultadoEleicao(e);
    ApagaEleicao(e);
    return 0;
}