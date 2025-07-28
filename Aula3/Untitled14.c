#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    *ptr = 42;

    printf("Valor armazenado: %d\n", *ptr);

    free(ptr);

    return 0;
}
