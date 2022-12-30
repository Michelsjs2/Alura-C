#include <stdio.h>
#include <string.h> //lib necess�ria para o uso do strlen()

#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    char palavra_secreta [20]; //uma vari�vel que possui um [] no final de um array
    sprintf(palavra_secreta, "TESTANDO"); //esse comando facilita a inser��o de uma palavra dentro de um array de caracteres
    
    int vitoria = 0;
    int forca = 1;

    do {
        char palpite;
        printf("D� o palpite de uma letra: ");
        scanf("%c", &palpite);

        for(int i = 0; i < strlen(palavra_secreta); i++){ //o strlen() faz uma leitura da string dentro do array de char
            if(palavra_secreta[i] == palpite){ //comparando o palpite com o array
                printf("A posi��o %d tem essa letra!\n", i);
            }
        }

    } while(!vitoria && !forca);
}