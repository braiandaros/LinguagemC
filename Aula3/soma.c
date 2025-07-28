#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    bool calcular = true;
    char continuar;

    while (calcular) {
        int ope;
        char operacao[20];
        double n1, n2, resultado;
        int entrada_valida;

        do {
            printf("Escolha a operacao:\n");
            printf("1 - Soma\n");
            printf("2 - Subtracao\n");
            printf("3 - Divisao\n");
            printf("4 - Multiplicacao\n");
            printf("Opcao: ");

            entrada_valida = scanf("%d", &ope);

            if (entrada_valida != 1 || ope < 1 || ope > 4) {
                printf("Erro: Opcao invalida! Tente novamente.\n");
                while (getchar() != '\n');
            }
        } while (entrada_valida != 1 || ope < 1 || ope > 4);

        do {
            printf("Digite o primeiro numero: ");
            entrada_valida = scanf("%lf", &n1);

            if (entrada_valida != 1) {
                printf("Erro: Entrada invalida! Digite um numero valido.\n");
                while (getchar() != '\n');
            }
        } while (entrada_valida != 1);


        do {
            printf("Digite o segundo numero: ");
            entrada_valida = scanf("%lf", &n2);

            if (entrada_valida != 1) {
                printf("Erro: Entrada invalida! Digite um numero valido.\n");
                while (getchar() != '\n');
            }
        } while (entrada_valida != 1);

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
                while (n2 == 0) {
                    printf("Erro: Divisao por zero nao permitida! Digite outro valor para o segundo numero: ");
                    scanf("%lf", &n2);
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
dadw
        do {
            printf("Deseja continuar calculando? (y - sim / n - nao): ");
            scanf(" %c", &continuar);

            if (continuar != 'y' && continuar != 'n') {
                printf("Erro: Opcao invalida! Digite 'y' para continuar ou 'n' para sair.\n");
            }
        } while (continuar != 'y' && continuar != 'n');

        if (continuar == 'n') {
            calcular = false;
        }
    }

    return 0;
}
