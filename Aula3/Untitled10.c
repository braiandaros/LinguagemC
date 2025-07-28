#include <stdio.h>

int main() {
    // Declarando duas matrizes 2x2 e uma para o resultado
    int matrizA[2][2] = {{1, 2},
                         {3, 4}};
    int matrizB[2][2] = {{5, 6},
                         {7, 8}};

    int resultado[2][2];

    // Somando as matrizes
    printf("Somando as matrizes:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    // Mostrando o resultado
    printf("\nMatriz Resultado:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n"); // Nova linha ap�s cada linha da matriz
    }

    return 0;
}
