#include <stdio.h>
#include <stdlib.h>

#include "fogefoge.h"
#include "mapa.h"

MAPA m;

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

    le_mapa(&m);

    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    libera_memoria(&m);
}