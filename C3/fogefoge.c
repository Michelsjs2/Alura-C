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

    //valida entrada do usuário
    if(direcao != 'a' && 
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd') return;

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    
    //aponta para onde o personagem quer se mover e armazena essa informação para ser validada
    switch(direcao){
        case 'a':
            proximo_y--;
            break;

        case 'd':
            proximo_y++;
            break;

        case 'w':
            proximo_x--;
            break;

        case 's':
            proximo_x++;
            break;
    }

    //valida se a próxima posição é válida para o personagem se mover
    if(proximo_x >= m.linhas) return;
    if(proximo_y >= m.colunas) return;
    if(m.matriz[proximo_x][proximo_y] != '.') return;

    //se a posição for válida, move o personagem
    m.matriz[proximo_x][proximo_y] = '@';
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = proximo_x;
    heroi.y = proximo_y;

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