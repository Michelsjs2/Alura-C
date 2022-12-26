#include <stdio.h>
#include <locale.h> //Lib que permite a acentuação nos prints do código

int main() {

    //Código necessário para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabeçalho do jogo
    printf("**************************************\n");
    printf("* Bem-vindo ao jogo de adivinhação! *\n");
    printf("**************************************\n");

    //número a ser adivinhado
    int num_secreto = 42;

    //interação do usuário com o jogo
    int palpite;
    printf("Qual o seu palpite? ");
    scanf("%d", &palpite);
    printf("O seu palpite foi: %d\n", palpite);
}
