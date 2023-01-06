#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

//encontra a posição do herói no mapa quando o jogo inicia
void encontra_heroi(MAPA* m, POSICAO* p, char c){
    for(int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

//lê e escaneia o arquivo
void le_mapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0){
        printf("Erro ao na leitura do arquivo\n");
        exit(1);
    }

    fscanf (f, "%d %d", &(m->linhas), &(m->colunas));

    aloca_memoria(m);

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

//alocando espaço na memória de forma dinâmica
void aloca_memoria(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas +1));
    }
}

//imprimindo o mapa
void imprime_mapa(MAPA* m){
    for (int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}

//liberando o espaço alocado na memória
void libera_memoria(MAPA* m){  
    for (int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}