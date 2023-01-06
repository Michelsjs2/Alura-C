#include <stdio.h>
#include <stdlib.h>

#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao){
    
    m.matriz[heroi.x][heroi.y] = '.'; //limpa o personagem do mapa

    //movendo o personagem de acordo com as teclas pressionadas
    switch(direcao){
        case 'a':
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;

        case 'd':
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;

        case 'w':
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;

        case 's':
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
    }

}

int main (){

    le_mapa(&m);
    encontra_heroi(&m, &heroi, '@');

    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    libera_memoria(&m);
}