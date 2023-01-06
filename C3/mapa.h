struct mapa{
    char** matriz;
    int linhas;
    int colunas;  
};
typedef struct mapa MAPA;

void le_mapa(MAPA* m);
void aloca_memoria(MAPA* m);
void libera_memoria(MAPA* m);
void imprime_mapa(MAPA* m);