#include <stdio.h>
#include <stdlib.h>

//matriz de 5 por 10
char** mapa;
int linhas;
int colunas;

int main (){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0){
        printf("Erro ao na leitura do arquivo\n");
        exit(1);
    }

    fscanf (f, "%d %d", &linhas, &colunas);

    //alocando espaço na memória de forma dinâmica
    mapa = malloc(sizeof(char*) * linhas);
    for (int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas +1));
    }

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }

    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);

    //liberando o espaço alocado na memória
    for (int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}