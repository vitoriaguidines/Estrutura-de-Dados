#include <stdio.h>
#include <stdlib.h>


int main() {

    struct estudante {
        int nMatricula;
        char nome[30];
        float vMensalidade;
        char dataBacharelado[30];
    };

    struct estudante stud1, *ptr_stud1;

    ptr_stud1 = &stud1;
    printf("\n entre matricula: ");
    scanf("%d", &ptr_stud1->nMatricula);
    printf("\n entre nome: ");
    scanf("%s", &ptr_stud1->nome);
    printf("\n entre mesanlidade: ");
    scanf("%f", &ptr_stud1->vMensalidade);
    printf("\n entre data: ");
    scanf("%s", &ptr_stud1->dataBacharelado);

    printf("\n *************CADASTRO DO ESTUDANTE*************\n");
    printf("\n numero matricula = %d\n", ptr_stud1->nMatricula);
    printf("\n nome estudante = %s\n", ptr_stud1->nome);
    printf("\n mensalidade = %9.2f\n", ptr_stud1->vMensalidade);
    printf("\n data bacharelado = %s\n\n", ptr_stud1->dataBacharelado);


    return 0;
}