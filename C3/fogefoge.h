void le_mapa();
void aloca_memoria();
void libera_memoria();

void imprime_mapa();
void move(char direcao);
int acabou();

struct mapa{
    char** matriz;
    int linhas;
    int colunas;  
};