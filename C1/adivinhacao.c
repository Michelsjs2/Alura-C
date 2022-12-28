#include <stdio.h>
#include <locale.h> //Lib que permite a acentua��o nos prints do c�digo

#define NUM_TENTATIVAS 5 //diretiva que cria uma "vari�vel" constante

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

    for(int i = 1; i <= NUM_TENTATIVAS; i++){ //criando um loop com for
        printf("Tentativa %d de %d\n", i, NUM_TENTATIVAS); //exibindo para o usu�rio o n�mero de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        //validando o palpite atrav�s de condicionais
        int correto = palpite == num_secreto;
        int num_maior = palpite > num_secreto;
        int num_menor = palpite < num_secreto;

        if (correto){
            printf("Boa campe�o, voc� acertou!\n");
            break; //encerra o loop
        }
        
        else if(num_maior){ //uma cadeia de if com else if faz com que o programa execute somente a condi��o correta
            printf("O n�mero escolhido foi maior que o secreto...\n");
        } 

        else {
            printf("O n�mero escolhido foi menor que o secreto\n");
        }
    }
    
    printf("Fim de jogo!\n");

}
