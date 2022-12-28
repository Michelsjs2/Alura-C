#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Lib que permite a acentuação nos prints do código

/*#define NUM_TENTATIVAS 5 - diretiva que cria uma "variável" constante*/

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

    //pontuação do jogo
    int vitoria = 0;
    int tentativas = 0;
    int pontuacao = 1000;

    /*
    for(int i = 1; i <= NUM_TENTATIVAS; i++){ criando um loop com for
    */

    while(vitoria == 0){ //uso do laço while para permitir que usuário faça múltiplas tentativas
        printf("Tentativa %d\n", tentativas+1); //exibindo para o usuário o número de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        if(palpite < 0){
            printf("Você não pode dar palpites utilizando números negativos!\n");

            continue; //faz o loop pular para a próxima iteração. E é um comando que funciona com o While também
        }

        //validando o palpite através de condicionais
        int correto = palpite == num_secreto;
        int num_maior = palpite > num_secreto;

        if(correto){
            printf("Você acertou, parabéns!\n");
            vitoria = 1;
        } else if(num_maior){ //uma cadeia de if com else if faz com que o programa execute somente a condição correta
            printf("O número escolhido foi maior que o secreto...\n");
        } else {
            printf("O número escolhido foi menor que o secreto...\n");
        }

        tentativas++;
        int pontos_perdiros = abs((palpite - num_secreto) / 2); //utilizando função para retorno de número absoluto
        pontuacao = pontuacao - pontos_perdiros;

    }
    
    if(tentativas == 1){
        printf("Você é uma lenda, acertou de primeira!\n");
    } else {
    printf("Você acertou em %d tentativas\n", tentativas);
    }
    
    printf("Sua pontuação foi de: %d\n", pontuacao);
    printf("Fim de jogo!\n");

}
