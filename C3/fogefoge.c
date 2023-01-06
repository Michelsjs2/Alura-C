#include <stdio.h>
#include <stdlib.h>

#include "fogefoge.h"

struct mapa m;

//lê e escaneia o arquivo
void le_mapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0){
        printf("Erro ao na leitura do arquivo\n");
        exit(1);
    }

    fscanf (f, "%d %d", &(m.linhas), &(m.colunas));

    aloca_memoria();

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", m.matriz[i]);
    }

    fclose(f);
}

//alocando espaço na memória de forma dinâmica
void aloca_memoria(){
    m.matriz = malloc(sizeof(char*) * m.linhas);
    for (int i = 0; i < m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas +1));
    }
}

//liberando o espaço alocado na memória
void libera_memoria(){  
    for (int i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
}

//imprimindo o mapa
void imprime_mapa(){
    for (int i = 0; i < 5; i++){
        printf("%s\n", m.matriz[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    //acha a posição do personagem
    for(int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    //movendo o personagem de acordo com as teclas pressionadas
    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            break;

        case 'd':
            m.matriz[x][y+1] = '@';
            break;

        case 'w':
            m.matriz[x-1][y] = '@';
            break;

        case 's':
            m.matriz[x+1][y] = '@';
            break;
    }

    m.matriz[x][y] = '.'; //limpa o personagem do mapa
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