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

//verifica se uma letra j� foi palpitada
int verifica_palpite(char letra, char palpites[26], int tentativas){
    int acertou = 0;

    for(int j = 0; j < tentativas; j++){
        if(palpites[j] == letra){
            acertou = 1;
            break;
        }
    }

    return acertou;
}

//imprime a palavra secreta
void desenha_forca(char palavra_secreta[20], char palpites[26], int tentativas){
    for (int i = 0; i < strlen(palavra_secreta); i++){ 

        int acertou = verifica_palpite(palavra_secreta[i], palpites, tentativas);
        if(acertou){
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

void escolhe_palavra(char palavra_secreta[20]){
    sprintf(palavra_secreta, "TESTANDO"); //esse comando facilita a inser��o de uma palavra dentro de um array de caracteres
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char palavra_secreta [20]; //uma vari�vel que possui um [] no final de um array
    
    /*array que guarda os palpites do usu�rio e int que 
    verifica o n�mero de vezes que o usu�rio deu palpites*/
    char tentativa_usuario[26];
    int num_tentativas = 0;

    int vitoria = 0;
    int forca = 0;

    escolhe_palavra(palavra_secreta);
    iniciar_jogo();

    do {

        desenha_forca(palavra_secreta, tentativa_usuario, num_tentativas);
        fpalpite(tentativa_usuario, &num_tentativas);

    } while(!vitoria && !forca);
}
