#include <stdio.h>
#include "esfera_utils.h"

int main(){
    float R;
    scanf("%f", &R);
    float area = calcula_area(R), volume = calcula_volume(R);
    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
}