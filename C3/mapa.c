#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mapa.h"

void mapa_auxiliar(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    aloca_mapa(destino);
    for(int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

//se a posição for válida, move o personagem
void move_personagem (MAPA* m, int x_origem, int y_origem, int x_destino, int y_destino){
    char personagem = m->matriz[x_origem][y_origem];
    m->matriz[x_destino][y_destino] = personagem;
    m->matriz[x_origem][y_origem] = VAZIO;
}

//valida se a próxima posição está dentro da matriz
int checa_parede(MAPA* m, int x, int y){
    if(x >= m->linhas) return 0;
    if(y >= m->colunas) return 0;

    return 1;
}

//valida se a proxima posição do mapa é vazia
int posicao_vazia(MAPA* m, int x, int y){
    return m->matriz[x][y] == VAZIO;
}

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

    aloca_mapa(m);

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

//alocando espaço na memória de forma dinâmica
void aloca_mapa(MAPA* m){
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
void libera_mapa(MAPA* m){  
    for (int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}