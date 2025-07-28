#include<stdio.h>

int main(){
    int d;
    printf("Insira o valor do dia da semana: \n");
    printf("1-Domingo\n");
    printf("2-Segunda Feira\n");
    printf("3-Terca Feira\n");
    printf("4-Quarta Feira\n");
    printf("5-Quinta Feira\n");
    printf("6-Sexta Feira\n");
    printf("7-Sabado\n");
    printf("Valor: ");.
++.accumulate


    scanf("%d",&d);

    switch(d){
        case 1:
            printf("Hoje e Domingo.\n");
            break;
        case 2:
            printf("Hoje e Segunda Feira.\n");
            break;
        case 3:
            printf("Hoje e Terca Feira.\n");
            break;
        case 4:
            printf("Hoje e Quarta Feira.\n");
            break;
        case 5:
            printf("Hoje e Quinta Feira.\n");
            break;
        case 6:
            printf("Hoje e Sexta Feira.\n");
            break;
        case 7:
            printf("Hoje e domingo.\n");
            break;
        default:
            printf("Dia nao esta correto.\n");
    }
}
