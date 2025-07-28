#include <stdio.h>

int main(){
    int a = 10;
    int *ptr;
    ptr = &a;
    *ptr = -5;
    printf("O valor de a: %d\n", a);


    int b = 20;
    int *ptr2;
    ptr2 = &b;
    *ptr2 = 69;
    printf("O valor de b: %d\n", b);
}


