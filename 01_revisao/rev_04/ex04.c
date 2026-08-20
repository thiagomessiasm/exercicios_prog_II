#include <stdio.h>

#define BASE_DESC 10
#define BASE_OC 8

int calculaPotencia(int base, int expoente);

int calculaPotencia(int base, int expoente){
    if(expoente == 0)
        return 1;
    
    int resultado = 1;
    
    for(int i= 0; i < expoente; i++){

        resultado = resultado * base;
    }

   return resultado; 
}

int main(){
    int num;
    scanf("%d", &num);

    int resto, parte_inteira, algarismo = 0, expoente = 0;


    while (num > 0){
    
    resto = num % BASE_OC;
    parte_inteira = num/BASE_OC;
    algarismo = algarismo + (resto * calculaPotencia(BASE_DESC, expoente));
    expoente++;
    num = parte_inteira;

    }
    
    printf("%d\n", algarismo);
}