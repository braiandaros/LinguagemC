#include <stdio.h>

int main(){
    double numero;

    printf("Digite um numero float: ");

    scanf("%lf", &numero);

    printf("O numero foi: %.2lf", numero);

    return 0;
}
