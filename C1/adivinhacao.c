#include <stdio.h>
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

int main() {

    //C�digo necess�rio para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabe�alho do jogo
    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinha��o! *\n");
    printf("**************************************\n");

    //n�mero a ser adivinhado
    int num_secreto = 42;

    //intera��o do usu�rio com o jogo
    int palpite;
    printf("Qual o seu palpite? ");
    scanf("%d", &palpite);
    printf("O seu palpite foi: %d\n", palpite);
}
