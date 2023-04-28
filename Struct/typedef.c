#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

typedef struct nascimento{
    int dia;
    int mes;
    int ano;
}DataNas;


typedef struct pessoa{
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[TAMANHO];
}Pessoa;


int main() {
    Pessoa pessoa;

    printf("digite seu nome: ");
    fgets(pessoa.nome, TAMANHO, stdin);
    printf("digite sua idade: ");
    scanf("%d", &pessoa.idade);
    scanf("%c");
    printf("digite seu sexo (F/M): ");
    scanf("%c", &pessoa.sexo);
    printf("digite sua data de nascimento no formato dd mm aaaa: ");
    scanf("%d%d%d", &pessoa.dataNas.dia, &pessoa.dataNas.mes, &pessoa.dataNas.ano);

    /*
    pessoa1.idade = 30;
    pessoa1.sexo = 'F';
    strcpy(pessoa1.nome,"maria");
    */
    printf("\nnome: %s\nidade: %d\nsexo: %c\n", pessoa.nome, pessoa.idade, pessoa.sexo);
    printf("data de nascimento: %d/%d/%d\n", pessoa.dataNas.dia, pessoa.dataNas.mes, pessoa.dataNas.ano);

    return 0;
}