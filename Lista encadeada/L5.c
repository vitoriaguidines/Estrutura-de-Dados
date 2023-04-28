#include <stdio.h>
#include <stdlib.h>

void acrescenta(int valor, int *v){
    int i;
    for (i = 0; i < valor; i++){
        v[i]++;
    }    
}

int main() {
    int a[] = {1, 2, 3};

    acrescenta(3, a);

    printf("%d %d %d \n", a[0], a[1], a[2]);
    return 0;
}