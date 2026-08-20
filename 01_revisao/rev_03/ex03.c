#include <stdio.h>

int main(){

    int qtd_de_livros = 0;

    scanf("%d", &qtd_de_livros);

    int idLivros[qtd_de_livros];
    int id_livros_sem_copia[qtd_de_livros];

    for(int i = 0; i < qtd_de_livros; i++){

        scanf("%d", &idLivros[i]);
    }

    for(int i = 0; i < qtd_de_livros; i++){

        int repetiu = 0;

        if(idLivros[i] != 0){

            for(int j = i + 1; j < qtd_de_livros; j++){

                if(idLivros[i] == idLivros[j]){
                    idLivros[j] = 0;
                    repetiu = 1;
                }
            }

            if(repetiu == 1){
                idLivros[i] = 0;
            }
        }
    }

    int cont = 0;

    for(int i = 0; i < qtd_de_livros; i++){

        if(idLivros[i] != 0){
            id_livros_sem_copia[cont] = idLivros[i];
            cont++;
        }
    }

    if(cont == 0){
        printf("NENHUM");
    }
    else{

        for(int i = 0; i < cont; i++){
            printf("%d ", id_livros_sem_copia[i]);
        }
    }

    return 0;
}