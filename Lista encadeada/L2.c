#include <stdio.h>
#include <stdlib.h>

void descobrirValores(int *v, int *me, int *ma, int tam){
    int i;
    *me = v[0];
    *ma = v[0];

    for (i = 1; i < tam; i++) {
        if (v[i] < *me) {
            *me = v[i];
        }
        if (v[i] > *ma) {
            *ma = v[i];
        }
    }
    printf("na funcao: menor: %d\tmaior: %d\n", *me, *ma);
    printf("na funcao -> endereco de me: %p\tendereco de ma: %p\n", &me, &ma);
    printf("na funcao -> conteudo de me: %p\tconteudo de ma: %p\n", me, ma);
}

int main (){

    int valor = 10, menor, maior, vet[] = {50,10,250,500,25};
    int *p;

    p = &valor;

    printf("o valor eh: %d\tendereco de valor: %p\n", valor, &valor);
    printf("endereco de p: %p\n", &p);
    printf("conteudo de p: %p\n", p);
    printf("conteudo apontado por p: %d\n", *p);

    descobrirValores(vet, &menor, &maior, 5);
    printf("em main: menor: %d\tmaior: %d\n", menor, maior);
    printf("na funcao: endereco de menor: %p\tendereco de maior: %d\n", &menor, &maior);

    return 0;

}