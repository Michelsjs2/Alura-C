#include <stdio.h>
#include <stdlib.h>

int main (){
    //matriz de 5 por 10
    char mapa[5][10+1];

    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0){
        printf("Erro ao na leitura do arquivo\n");
        exit(1);
    }

    //escaneia o arquivo linha a linha
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }

    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);
}