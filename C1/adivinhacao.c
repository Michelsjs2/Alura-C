#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

/*#define NUM_TENTATIVAS 5 - diretiva que cria uma "vari�vel" constante*/

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

    //pontua��o do jogo
    int vitoria = 0;
    int tentativas = 0;
    int pontuacao = 1000;

    /*
    for(int i = 1; i <= NUM_TENTATIVAS; i++){ criando um loop com for
    */

    while(vitoria == 0){ //uso do la�o while para permitir que usu�rio fa�a m�ltiplas tentativas
        printf("Tentativa %d\n", tentativas+1); //exibindo para o usu�rio o n�mero de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        if(palpite < 0){
            printf("Voc� n�o pode dar palpites utilizando n�meros negativos!\n");

            continue; //faz o loop pular para a pr�xima itera��o. E � um comando que funciona com o While tamb�m
        }

        //validando o palpite atrav�s de condicionais
        int correto = palpite == num_secreto;
        int num_maior = palpite > num_secreto;

        if(correto){
            printf("Voc� acertou, parab�ns!\n");
            vitoria = 1;
        } else if(num_maior){ //uma cadeia de if com else if faz com que o programa execute somente a condi��o correta
            printf("O n�mero escolhido foi maior que o secreto...\n");
        } else {
            printf("O n�mero escolhido foi menor que o secreto...\n");
        }

        tentativas++;
        int pontos_perdiros = abs((palpite - num_secreto) / 2); //utilizando fun��o para retorno de n�mero absoluto
        pontuacao = pontuacao - pontos_perdiros;

    }
    
    if(tentativas == 1){
        printf("Voc� � uma lenda, acertou de primeira!\n");
    } else {
    printf("Voc� acertou em %d tentativas\n", tentativas);
    }
    
    printf("Sua pontua��o foi de: %d\n", pontuacao);
    printf("Fim de jogo!\n");

}
