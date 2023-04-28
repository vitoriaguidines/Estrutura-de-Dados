#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
}Data;

void imprimirData(Data *x) {
    printf("%d/%d/%d", x->dia, x->mes, x->ano);

}

int main() {

    Data data;
    Data *p;

    p = &data;

    printf("data: %p\tp: %p\n", &data, p);

    data.dia = 29;
    data.mes = 2;
    data.ano = 2021;

    imprimirData(p);

    return 0;
}