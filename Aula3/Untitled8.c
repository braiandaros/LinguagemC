#include<stdio.h>

int main(){
    float v [4] = {7.5, 8.0,6.5,9.0};
    float total = 0;
    float media = 0;
    int tamanho = 4;

    for(int i = 0; i < tamanho; i++){
        total += v[i];
    }

    media = total / tamanho;

    printf("O media do vetor e %f\n",media);

}
