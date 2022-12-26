#include <stdio.h>
#include <locale.h> //Lib que permite a acentuação nos prints do código

int main() {

    //Código necessário para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinhação! *\n");
    printf("**************************************\n");
    return 0;
}
