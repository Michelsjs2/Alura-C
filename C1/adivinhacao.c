#include <stdio.h>
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

int main() {

    //C�digo necess�rio para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabe�alho do jogo
    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinha��o! *\n");
    printf("**************************************\n");

    int num_secreto = 42;

    printf("O n�mero %d � o secreto. Guarde ele muito bem!", num_secreto);
}
