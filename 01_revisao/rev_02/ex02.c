#include<stdio.h>

int main(){

    int N, aux = 1;
    
    scanf("%d", &N);
    printf("\n");

    if(N < 1)
        printf("VALOR INVALIDO!");

    else if( N == 1)
        printf("%d", aux);

    else{

        for(int i = 0; i < N; i++){

            for(int j = 0; j <= i; j++){
                printf("%d ",aux);
                aux++;
            }
        
            printf("\n");
        }
    }

    return 0;
}