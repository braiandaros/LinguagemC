#include<stdio.h>

int main(){
    int numero = 7;

    if(numero & 1){
        printf("%d e impar (ultimo bit = 1)\n", numero);
    }
    else{
        printf("%d e par (ultimo bit = 0)\n", numero);
    }
    return 0;
}
