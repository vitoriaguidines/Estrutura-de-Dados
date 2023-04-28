#include <stdio.h>
#include <stdlib.h>

void troca(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int a, b;
    a = 5;
    b = 7;

    troca(&a, &b);
    printf("%d %d", a, b);

    return 0;
}