#include <stdio.h>
#include <stdlib.h>

#include "fogefoge.h"

//variáveis globais da matriz
char** mapa;
int linhas;
int colunas;

//lê e escaneia o arquivo
void le_mapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0){
        printf("Erro ao na leitura do arquivo\n");
        exit(1);
    }

    fscanf (f, "%d %d", &linhas, &colunas);

    aloca_memoria();

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

//alocando espaço na memória de forma dinâmica
void aloca_memoria(){
    mapa = malloc(sizeof(char*) * linhas);
    for (int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas +1));
    }
}

//liberando o espaço alocado na memória
void libera_memoria(){  
    for (int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

int main (){

    le_mapa();

    //imprimindo o mapa
    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    libera_memoria();
}