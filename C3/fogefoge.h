#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

void move(char direcao);
int fim_de_jogo();
int validar_direcao (char direcao);
void fantasmas();
int movimento_do_fantasma(int x_atual, int y_atual, int* x_destino, int* y_destino);