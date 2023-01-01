#include <stdio.h>
#include <string.h> //lib necessária para o uso do strlen()
#include <stdlib.h>
#include <time.h>
#include "jogo_forca.h"

#include <locale.h>

//variáveis globais
char palavra_secreta[20];
char num_de_palpites[26];
int tentativas = 0;

void iniciar_jogo(){ //cabeçalho do jogo
    printf("****************************\n");
    printf("*                          *\n");
    printf("*       Jogo da Forca      *\n");
    printf("*                          *\n");
    printf("****************************\n\n");
}

void escolhe_palavra(){
    FILE* f;

    f = fopen("palavras.txt", "r"); //abre o arquivo
    if(f == 0){ //tratamento de possível falha do banco de dados
        printf("Infelizmente, o banco de dados não está disponível\n\n");
        exit(1);
    }

    int qtd_de_palavras;
    fscanf(f, "%d", &qtd_de_palavras); //verifica a quantidade de palavras, checando a primeira linha do arquivo

    srand(time(0));
    int randomico = rand() % qtd_de_palavras;

    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavra_secreta);
    }

    fclose(f); //fecha o arquivo
}

//captura o palpite do jogador e coloca em um array
void dar_palpite(){
    char palpite;
    printf("Dê o palpite de uma letra: ");
    scanf(" %c", &palpite);

    num_de_palpites[tentativas] = palpite;
    tentativas++; 
}

//verifica se uma letra já foi palpitada
int verifica_palpite(char letra){
    int acertou = 0;

    for(int j = 0; j < tentativas; j++){
        if(num_de_palpites[j] == letra){
            acertou = 1;
            break;
        }
    }

    return acertou;
}

//imprime a palavra secreta
void desenha_forca(){
    for (int i = 0; i < strlen(palavra_secreta); i++){ 

        if(verifica_palpite(palavra_secreta[i])){
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

//valida os erros dos palpites e derrota do jogador
int derrota(){
    int erros = 0;

    for(int i = 0; i < tentativas; i++){

        int letra_certa = 0;

        for(int j = 0; j < strlen(palavra_secreta); j++){
            if(num_de_palpites[i] == palavra_secreta[j]){
                letra_certa = 1;
                break;
            }
        }

        if(!letra_certa) erros++;
    }

    return erros >= 5;
}

//valida a vitória do jogador
int vitoria(){
    for(int i = 0; i < strlen(palavra_secreta); i++){
        if(!verifica_palpite(palavra_secreta[i])){
            return 0;
        }
    }

    return 1;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    escolhe_palavra();
    iniciar_jogo();

    do {

        desenha_forca();
        dar_palpite();

    } while(!vitoria() && !derrota());
}
