#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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

void mapa_auxiliar(MAPA* destino, MAPA* origem);
void le_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void libera_mapa(MAPA* m);
void imprime_mapa(MAPA* m);

int encontra_heroi(MAPA* m, POSICAO* p, char c);
void move_personagem (MAPA* m, int x_origem, int y_origem, int x_destino, int y_destino);

int checa_limite_mapa(MAPA* m, int x, int y);
int posicao_vazia(MAPA* m, int x, int y);
int checa_parede(MAPA* m, int x, int y);
int mesmo_personagem(MAPA* m, char personagem, int x, int y);
int valida_movimento(MAPA* m, char personagem, int x, int y);