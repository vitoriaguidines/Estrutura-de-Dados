#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int n;
    printf("declare um valor maior do que zero: ");
    scanf("%d", &n);

    printf("o fatorial eh: %d\n",fatorial(n));

    return 0;
}