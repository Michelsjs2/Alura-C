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

//imprimindo o mapa
void imprime_mapa(){
    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    //acha a posição do personagem
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if(mapa[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    //movendo o personagem de acordo com as teclas pressionadas
    switch(direcao){
        case 'a':
            mapa[x][y-1] = '@';
            break;

        case 'd':
            mapa[x][y+1] = '@';
            break;

        case 'w':
            mapa[x-1][y] = '@';
            break;

        case 's':
            mapa[x+1][y] = '@';
            break;
    }

    mapa[x][y] = '.'; //limpa o personagem do mapa
}

int main (){

    le_mapa();

    do {
        imprime_mapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    libera_memoria();
}