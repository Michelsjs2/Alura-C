#include <stdio.h>
#include <locale.h> //Lib que permite a acentuação nos prints do código

int main() {

    //Código necessário para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabeçalho do jogo
    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinhação! *\n");
    printf("**************************************\n");

    int num_secreto = 42;

    printf("O número %d é o secreto. Guarde ele muito bem!", num_secreto);
}
