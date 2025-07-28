#include<stdio.h>

int main(){
    int temDesconto = 1;
    int estoque = 1;

    if(temDesconto && estoque){
        printf("Produto com desconto");
    }
    else{
        printf("Produto sem desconto");
    }
    return 0;
}
