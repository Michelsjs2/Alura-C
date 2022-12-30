#include <stdio.h>
#include <string.h> //lib necess�ria para o uso do strlen()

#include <locale.h>

void iniciar_jogo(){ //cabe�alho do jogo
    printf("****************************\n");
    printf("*                          *\n");
    printf("*       Jogo da Forca      *\n");
    printf("*                          *\n");
    printf("****************************\n\n");
}

//captura o palpite do jogador e coloca em um array
void fpalpite(char palpites[26], int* tentativas){ //o int* � um ponteiro que aponta para um inteiro
    char palpite;
    printf("D� o palpite de uma letra: ");
    scanf(" %c", &palpite);

    palpites[(*tentativas)] = palpite; //o (*var) � necess�rio para pegar o valor que est� dentro da vari�vel para onde apontou o ponteiro
    (*tentativas)++;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    iniciar_jogo();

    char palavra_secreta [20]; //uma vari�vel que possui um [] no final de um array
    sprintf(palavra_secreta, "TESTANDO"); //esse comando facilita a inser��o de uma palavra dentro de um array de caracteres
    
    /*array que guarda os palpites do usu�rio e int que 
    verifica o n�mero de vezes que o usu�rio deu palpites*/
    char tentativa_usuario[26];
    int num_tentativas = 0;

    int vitoria = 0;
    int forca = 0;

    do {
        //imprime a palavra secreta
        for (int i = 0; i < strlen(palavra_secreta); i++){ 

            int acertou = 0;

            //verifica se uma letra j� foi palpitada
            for(int j = 0; j < num_tentativas; j++){
                if(tentativa_usuario[j] == palavra_secreta[i]){
                    acertou = 1;
                    break;
                }
            }
            
            if(acertou){
                printf("%c ", palavra_secreta[i]);
            } else {
                printf("_ ");
            }
        }

        printf("\n\n");
        
        fpalpite(tentativa_usuario, &num_tentativas);

    } while(!vitoria && !forca);
}
