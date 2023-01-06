#include <stdio.h>
#include <stdlib.h>

#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

//valida entrada do usuário
int direcao_valida (char direcao){
    return direcao == 'a' || 
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}

void move(char direcao){

    if(!direcao_valida(direcao)) return;

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

    if(!tem_parede(&m, proximo_x, proximo_y)) return;
    if(!posicao_vazia(&m, proximo_x, proximo_y)) return;

    move_personagem(&m, heroi.x, heroi.y, proximo_x, proximo_y);
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