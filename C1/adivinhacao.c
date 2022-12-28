#include <stdio.h>
#include <stdlib.h> //Lib que nos dá acesso ao abs()
#include <time.h> //Lib que trabalha com tempo e data
#include <locale.h> //Lib que permite a acentuação nos prints do código

/*#define NUM_TENTATIVAS 5 - diretiva que cria uma "variável" constante*/

int main() {

    //Código necessário para que os acentos funcionem
    setlocale(LC_ALL, "Portuguese_Brazil");

    //cabeçalho do jogo
    printf("   _____________________________________________________________________\n");
    printf(" / \\                                                                    \\\n");
    printf("|   |                                                                    |\n");
    printf(" \\_ |********************************************************************|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                  Bem-vindo ao jogo de adivinhação!               *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*                                                                  *|\n");
    printf("    |*               Escolha o nível de dificuldade que deseja!         *|\n");
    printf("    |*                             (1) Fácil                            *|\n");
    printf("    |*                             (2) Médio                            *|\n");
    printf("    |*                             (3) Difícil                          *|\n");
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

    //número a ser adivinhado, agora sendo randômico!
    int segundos = time(0);
    srand(segundos);
    
    int num_rand = rand();
    int num_secreto = num_rand % 100; //o % é utilizado para pegar o resto da divisão de um cálculo, e nesse caso o seu valor irá de 0 a 99

    //interação do usuário com o jogo
    int palpite;

    //pontuação do jogo
    int vitoria = 0;
    int tentativas = 0;
    double pontuacao = 1000;

    //validando o palpite através de condicionais
    int correto = 0;

   for(int i = 1; i <= num_tentativas; i++){ //voltamos ao laço for
        printf("Tentativa %d de %d\n", tentativas+1, num_tentativas); //exibindo para o usuário o número de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        correto = palpite == num_secreto;
        int num_maior = palpite > num_secreto;

        if(palpite < 0){
            printf("Você não pode dar palpites utilizando números negativos!\n");

            continue; //faz o loop pular para a próxima iteração. E é um comando que funciona com o While também
        }

        if(correto){
            break;
        } else if(num_maior){ //uma cadeia de if com else if faz com que o programa execute somente a condição correta
            printf("O número escolhido foi maior que o secreto...\n");
        } else {
            printf("O número escolhido foi menor que o secreto...\n");
        }

        tentativas++;
        double pontos_perdiros = abs(palpite - num_secreto) / (double)2; //uso do casting e do abs()
        pontuacao = pontuacao - pontos_perdiros;

    }
    
    if(correto){
        if(tentativas == 0){
            printf("                                              Você é uma lenda, acertou de primeira!\n");
        } else {
            printf("                                                  Você acertou em %d tentativas\n", tentativas);
        }
        printf("                                          ^(^---^)^ Sua pontuação foi de: %.1f ^(^---^)^\n", pontuacao);
    } else {
        printf("                                          (;---;) Você perdeu... Tente novamente! (;---;)\n");
    }

    printf("                                                 ->>-----> Fim de jogo! <-----<<-\n");

}
