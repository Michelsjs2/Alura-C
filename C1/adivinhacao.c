#include <stdio.h>
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

int main() {

    //C�digo necess�rio para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinha��o! *\n");
    printf("**************************************\n");
    return 0;
}
