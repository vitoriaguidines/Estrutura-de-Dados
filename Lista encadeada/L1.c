#include <stdio.h>
#include <stdlib.h>

void imprimir(int x){
    if (x == 0){
        printf("%d ", x);
    }else{
        imprimir(x - 1);
        printf("%d ", x);
    }
}

int main(){

    int n;

    printf("digite um valor maior que zero: ");
    scanf("%d", &n);

    imprimir(n);

    return 0;
}