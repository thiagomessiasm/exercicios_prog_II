#include <stdio.h>
#include "botao.h"
#include "tela.h"

void salvar(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluir(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void opcoes(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    
    Tela t = CriarTela(400, 200);

    Botao b0 = CriarBotao("Salvar", 12, "FFF", CLICK, salvar);
    RegistraBotaoTela(&t, b0);

    Botao b1 = CriarBotao("Excluir", 18, "000", CLICK, excluir);
    RegistraBotaoTela(&t, b1);

    Botao b2 = CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, opcoes);
    RegistraBotaoTela(&t, b2);

    DesenhaTela(t);
    OuvidorEventosTela(t);

    return 0;
}