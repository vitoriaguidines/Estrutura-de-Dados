#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* inserir(No *inicio, int x) {
    No *novo = malloc(sizeof(No));
    if(novo) {
        novo -> valor = x;
        novo -> proximo = inicio;
    }
    return novo;
}

void inserir2(No **inicio, int x) {
    No *novo = malloc(sizeof(No));
    if(novo) {
        novo -> valor = x;
        novo -> proximo = *inicio;
        *inicio = novo;
    }
}

void imprimir(No *inicio) {
    if(inicio) {
        printf("%d ", inicio -> valor);
        imprimir(inicio -> proximo);
    }
}

int main() {
    No *lista = NULL;

    lista = inserir(lista, 10);
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);

    inserir2(&lista, 17);
    inserir2(&lista, 57);
    inserir2(&lista, 107);

    imprimir(lista);

    return 0;
}