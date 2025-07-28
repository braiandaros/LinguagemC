#include <stdio.h>

int main(){
    int opcao;
    printf("Escolha uma opcao: \n 1.Cafe \n 2.Cha \n 3.Suco \n Digite: ");
    scanf("%d", &opcao);
    switch(opcao){
    case 1:
        printf("Voce escolheu cafe.\n");
        break;
    case 2:
        printf("Voce escolheu cha.\n");
        break;
    case 3:
        printf("Voce escolheu suco.\n");
        break;
    default:
        printf("Opcao invalida.\n");
        break;
    }
}
