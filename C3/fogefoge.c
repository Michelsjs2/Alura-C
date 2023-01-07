#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int movimento_do_fantasma(int x_atual, int y_atual, int* x_destino, int* y_destino){

    //direções disponíveis para fantasma se mover
    int opcoes[4][2]= {
        { x_atual   , y_atual+1 },
        { x_atual+1 , y_atual   },
        { x_atual   , y_atual-1 },
        { x_atual-1 , y_atual   }
    };

    srand(time(0));
    for (int i = 0; i < 10; i++){ //10 tentativas para encontrar uma direção válida
        int posicao = rand() % 4;
        if(checa_parede(&m, opcoes[posicao][0], opcoes[posicao][1]) &&
            posicao_vazia(&m, opcoes[posicao][0], opcoes[posicao][1])) {
            *x_destino = opcoes[posicao][0];
            *y_destino = opcoes[posicao][1];

            return 1; //se encontrou uma direção dentro das 10 tentativas, move o fantasma
        }
    }
    
    return 0; //se não encontrou a posição válida, não move o fantasma

}

void fantasmas(){
    MAPA auxiliar;

    mapa_auxiliar(&auxiliar, &m);

    for(int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){

            if(auxiliar.matriz[i][j] == FANTASMA){

                int x_destino;
                int y_destino;

                int encontrou_direcao = movimento_do_fantasma(i, j, &x_destino, &y_destino);

                if(encontrou_direcao){
                    move_personagem(&m, i, j, x_destino, y_destino);
                }
            }
        }
    }

    libera_mapa(&auxiliar);
}

int acabou(){
    return 0;
}

//valida entrada do usuário
int validar_direcao (char direcao){
    return direcao == 'a' || 
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}

void move(char direcao){

    if(!validar_direcao(direcao)) return;

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    
    //aponta para onde o personagem quer se mover e armazena essa informação para ser validada
    switch(direcao){
        case ESQUERDA:
            proximo_y--;
            break;

        case DIREITA:
            proximo_y++;
            break;

        case CIMA:
            proximo_x--;
            break;

        case BAIXO:
            proximo_x++;
            break;
    }

    if(!checa_parede(&m, proximo_x, proximo_y)) return;
    if(!posicao_vazia(&m, proximo_x, proximo_y)) return;

    move_personagem(&m, heroi.x, heroi.y, proximo_x, proximo_y);
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

int main (){

    le_mapa(&m);
    encontra_heroi(&m, &heroi, HEROI);

    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while (!acabou());

    libera_mapa(&m);
}