struct mapa{
    char** matriz;
    int linhas;
    int colunas;  
};
typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};
typedef struct posicao POSICAO;

void le_mapa(MAPA* m);
void aloca_memoria(MAPA* m);
void libera_memoria(MAPA* m);
void imprime_mapa(MAPA* m);
void encontra_heroi(MAPA* m, POSICAO* p, char c);
int tem_parede(MAPA* m, int x, int y);
int posicao_vazia(MAPA* m, int x, int y);
void move_personagem (MAPA* m, int x_origem, int y_origem, int x_destino, int y_destino);
