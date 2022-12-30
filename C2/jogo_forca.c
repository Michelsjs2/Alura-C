#include <stdio.h>
#include <string.h> //lib necess�ria para o uso do strlen()

#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    char palavra_secreta [20]; //uma vari�vel que possui um [] no final de um array
    sprintf(palavra_secreta, "TESTANDO"); //esse comando facilita a inser��o de uma palavra dentro de um array de caracteres
    
    /*array que guarda os palpites do usu�rio e int que 
    verifica o n�mero de vezes que o usu�rio deu palpites*/
    char tentativa_usuario[26];
    int num_tentativas = 0;

    int vitoria = 0;
    int forca = 0;

    do {
        for (int i = 0; i < strlen(palavra_secreta); i++){ 

            //verificar se o palpite do usu�rio bate com uma das letras secretas
            int acertou = 0;
            for(int j = 0; j < num_tentativas; j++){
                if(tentativa_usuario[j] == palavra_secreta[i]){
                    acertou = 1;
                    break;
                }
            }
            
            //if que imprime a letra que o usu�rio acertou caso ele o fa�a, ou mant�m o _
            if(acertou){
                printf("%c ", palavra_secreta[i]);
            } else {
                printf("_ ");
            }
        }

        printf("\n");
        
        //intera��o do usu�rio com o jogo
        char palpite;
        printf("D� o palpite de uma letra: ");
        scanf(" %c", &palpite);

        /*guarda a letra que o usu�rio palpitou dentro 
        do array e acrescenta um n�mero aos chutes feitos pelo usu�rio*/
        tentativa_usuario[num_tentativas] = palpite;
        num_tentativas++;

    } while(!vitoria && !forca);
}