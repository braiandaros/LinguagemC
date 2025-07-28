#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)malloc(100 * sizeof(char));

    if (str == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    strcpy(str, "Programacao em C");

    printf("String armazenada: %s\n", str);

    free(str);

    return 0;
}
