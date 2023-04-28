#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "cliente.c"

#include <limits.h>
//#include <dirent.h>
#include <string.h>

typedef struct vetor {
    TCliente *cli;
} TVet;

void imprime_arquivo(char *nome) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(nome, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets(linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets(linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

char *gera_nome_particao(int num_part) {
    char *nome_particao = (char *) malloc(sizeof(char[10]));
    char num_particao[10];

    strcpy(nome_particao, "p");
    sprintf(num_particao, "%d", num_part);
    strcat(nome_particao, num_particao);
    strcat(nome_particao, ".txt");

    return nome_particao;
}

int indexOfMin (TCliente **memoria, int length) {
    int i;
    int iMin=-1;

    for(i=0; i<length; i++){
        if(!memoria[i]) continue;

        if(iMin==-1 || memoria[i]->cod_cliente<memoria[iMin]->cod_cliente) iMin=i;
        
    }

    return iMin;
}

int selecao_natural(char *nome_arquivo_entrada, int tam_memoria) {
    FILE *arq = fopen(nome_arquivo_entrada, "r");
    FILE *part = fopen(gera_nome_particao(1), "w");
    if(!arq || !part) exit(1);

    int i = 0;
    int part_atual = 1;
    int anterior = INT_MIN;
    int reservatorio_i = 0;

    TCliente **memoria = (TCliente **)malloc(sizeof(TCliente*)*tam_memoria);
    TCliente **reservatorio = (TCliente **)malloc(sizeof(TCliente*)*tam_memoria);

    while(!feof(arq) && i<tam_memoria){
        memoria[i]=le_cliente(arq);
        i++;
    }

    int menor = indexOfMin(memoria, tam_memoria);

    while(!feof(arq)){
        TCliente *atual = memoria[menor];

        if(anterior > atual->cod_cliente){ 
            reservatorio[reservatorio_i] = atual;
            reservatorio_i++;

            if(reservatorio_i == tam_memoria){
                memoria[menor] = NULL;

                int menor2;
                menor2 = indexOfMin(memoria, tam_memoria);

                while(menor2 != -1){
                    TCliente *atual = memoria[menor2];
                    memoria[menor2] = NULL;
                    salva_cliente(atual, part);
                    menor2 = indexOfMin(memoria, tam_memoria);
                }

                int i;

                for(i=0; i<tam_memoria; i++) {
                    memoria[i] = reservatorio[i];
                    reservatorio[i] = NULL;
                }

                reservatorio_i = 0;

                anterior = INT_MIN;

                part_atual++;
                fclose(part);
                part=fopen(gera_nome_particao(part_atual), "w");
                if(!part) exit(1);
            } else {
                memoria[menor]=le_cliente(arq);
            }

        } else {
            salva_cliente(atual, part);
            TCliente* novo = le_cliente(arq);
            memoria[menor] = novo;
            anterior = atual->cod_cliente;
        }

        menor = indexOfMin(memoria, tam_memoria);
    }

    menor = indexOfMin(memoria, tam_memoria);

    while(menor != -1) {
        TCliente *atual = memoria[menor];
        memoria[menor] = NULL;
        salva_cliente(atual, part);
        menor = indexOfMin(memoria, tam_memoria);
    }

    if(reservatorio[0]) {
        part_atual++;
        fclose(part);
        part = fopen(gera_nome_particao(part_atual), "w");
        if(!part) exit(1);

        menor = indexOfMin(reservatorio,tam_memoria);

        while(menor != -1){
            TCliente *atual = reservatorio[menor];
            reservatorio[menor] = NULL;
            salva_cliente(atual, part);
            menor = indexOfMin(reservatorio, tam_memoria);
        }
    }

    fclose(arq);
    fclose(part);

    return part_atual;
}

int main() {
    int tam_memoria;
    scanf("%d", &tam_memoria);
    int num_part = selecao_natural("entrada.txt", tam_memoria);
    for (int i = 1; i < num_part+1; i++) {
        printf("*** %s\n", gera_nome_particao(i));
        imprime_arquivo(gera_nome_particao(i));
    }
}