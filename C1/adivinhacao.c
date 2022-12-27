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

    for(int i = 1; i <= 3; i++){ //criando um loop com for
        printf("Tentativa %d de 3\n", i); //exibindo para o usu�rio o n�mero de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        //validando o palpite atrav�s de condicionais
        int correto = palpite == num_secreto;
        if (correto){
            printf("Boa campe�o, voc� acertou!\n");
            break; //encerra o loop

        } else {
            int num_maior = palpite > num_secreto; //inserir condi��es dentro de vari�veis pode auxiliar na legibilidade do c�digo
            if(num_maior){
                printf("O n�mero escolhido foi maior que o secreto...\n");
            } else {
                printf("O n�mero escolhido foi menor que o secreto\n");
            }

            printf("Tente novamente!\n");

        }
    }

    printf("Fim de jogo!\n");

}
