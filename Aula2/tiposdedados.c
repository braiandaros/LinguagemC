#include <stdio.h>
#include<string.h>

int main(){
    char nome[100];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    //scanf("%s", nome);

    printf("O seu nome eh: %s", nome);
    printf("Agora digite sua idade: ");

    scanf("%d", &idade);

    nome[strcspn(nome, "\n")] = '\0';

    printf("A idade de %s eh %d", nome, idade);

    return 0;
}
