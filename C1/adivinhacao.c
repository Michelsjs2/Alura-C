#include <stdio.h>
#include <stdlib.h> //Lib que nos d� acesso ao abs()
#include <time.h> //Lib que trabalha com tempo e data
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

/*#define NUM_TENTATIVAS 5 - diretiva que cria uma "vari�vel" constante*/

int main() {

    //C�digo necess�rio para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabe�alho do jogo
    printf("   _____________________________________________________________________\n");
    printf(" / \\                                                                    \\\n");
    printf("|   |                                                                    |\n");
    printf(" \\_ |********************************************************************|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                  Bem-vindo ao jogo de adivinha��o!               *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*               Escolha o n�vel de dificuldade que deseja!         *|\n");
    printf("    |*                             (1) F�cil                            *|\n");
    printf("    |*                             (2) M�dio                            *|\n");
    printf("    |*                             (3) Dif�cil                          *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |********************************************************************|\n");
    printf("    |    ________________________________________________________________|___\n");
    printf("    |   /                                                                   /\n");
    printf("     \\_/___________________________________________________________________/\n\n\n");
    printf("                                   Sua escolha: ");

    //escolha de nivel de dificuldade
    int dificuldade;
    scanf("%d", &dificuldade);

    int num_tentativas;
    switch (dificuldade) { //alternativa ao if e elseifs
        case 1:
            num_tentativas = 16;
            break;

        case 2:
            num_tentativas = 11;
            break;
        
        default:
            num_tentativas = 6;
            break;
    }

    //n�mero a ser adivinhado, agora sendo rand�mico!
    int segundos = time(0);
    srand(segundos);
    
    int num_rand = rand();
    int num_secreto = num_rand % 100; //o % � utilizado para pegar o resto da divis�o de um c�lculo, e nesse caso o seu valor ir� de 0 a 99

    //intera��o do usu�rio com o jogo
    int palpite;

    //pontua��o do jogo
    int vitoria = 0;
    int tentativas = 0;
    double pontuacao = 1000;

    //validando o palpite atrav�s de condicionais
    int correto = 0;

   for(int i = 1; i <= num_tentativas; i++){ //voltamos ao la�o for
        printf("Tentativa %d de %d\n", tentativas+1, num_tentativas); //exibindo para o usu�rio o n�mero de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        correto = palpite == num_secreto;
        int num_maior = palpite > num_secreto;

        if(palpite < 0){
            printf("Voc� n�o pode dar palpites utilizando n�meros negativos!\n");

            continue; //faz o loop pular para a pr�xima itera��o. E � um comando que funciona com o While tamb�m
        }

        if(correto){
            break;
        } else if(num_maior){ //uma cadeia de if com else if faz com que o programa execute somente a condi��o correta
            printf("O n�mero escolhido foi maior que o secreto...\n");
        } else {
            printf("O n�mero escolhido foi menor que o secreto...\n");
        }

        tentativas++;
        double pontos_perdiros = abs(palpite - num_secreto) / (double)2; //uso do casting e do abs()
        pontuacao = pontuacao - pontos_perdiros;

    }
    
    if(correto){
        if(tentativas == 0){
            printf("                                              Voc� � uma lenda, acertou de primeira!\n");
        } else {
            printf("                                                  Voc� acertou em %d tentativas\n", tentativas);
        }
        printf("                                          ^(^---^)^ Sua pontua��o foi de: %.1f ^(^---^)^\n", pontuacao);
    } else {
        printf("                                          (;---;) Voc� perdeu... Tente novamente! (;---;)\n");
    }

    printf("                                                 ->>-----> Fim de jogo! <-----<<-\n");

}
