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

    for(int i = 1; i <= 3; i++){ //criando um loop com for
        printf("Tentativa %d de 3\n", i); //exibindo para o usuário o número de tentativas que ele possui
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        printf("O seu palpite foi: %d\n", palpite);

        //validando o palpite através de condicionais
        int correto = palpite == num_secreto;
        if (correto){
            printf("Boa campeão, você acertou!\n");
            break; //encerra o loop

        } else {
            int num_maior = palpite > num_secreto; //inserir condições dentro de variáveis pode auxiliar na legibilidade do código
            if(num_maior){
                printf("O número escolhido foi maior que o secreto...\n");
            } else {
                printf("O número escolhido foi menor que o secreto\n");
            }

            printf("Tente novamente!\n");

        }
    }

    printf("Fim de jogo!\n");

}
