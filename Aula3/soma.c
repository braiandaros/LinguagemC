#include<stdio.h>
#include <string.h>

int main(){
    int ope;
    char operacao[20];
    double n1, n2, resultado;

    printf("Escolha a operacao:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Divisao\n");
    printf("4 - Multiplicacao\n");
    printf("Opcao: ");
    scanf("%d", &ope);

    if (ope < 1 || ope > 4) {
        printf("Erro: Opcao invalida!\n");
        return 1;
    }

    printf("Digite o primeiro numero: ");
    scanf("%lf", &n1);

    printf("Digite o segundo numero: ");
    scanf("%lf", &n2);

    switch (ope) {
        case 1:
            resultado = n1 + n2;
             strcpy(operacao, "soma");
            break;
        case 2:
            resultado = n1 - n2;
             strcpy(operacao, "subtracao");
            break;
        case 3:
            if (n2 == 0) {
                printf("Erro: Divisao por zero!\n");
                return 1;
            }
            resultado = n1 / n2;
             strcpy(operacao, "divisao");
            break;
        case 4:
            resultado = n1 * n2;
             strcpy(operacao, "multiplicacao");
            break;
    }

    printf("O resultado da %s eh: %.2lf\n", operacao, resultado);

    return 0;
}
