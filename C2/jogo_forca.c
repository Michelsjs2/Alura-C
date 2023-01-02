#include <stdio.h>
#include <string.h> //lib necessária para o uso do strlen()
#include <stdlib.h>
#include <time.h>
#include "jogo_forca.h"

#include <locale.h>

//variáveis globais
char palavra_secreta[TAMANHO_PALAVRA];
char num_de_palpites[26];
int tentativas = 0;
int dificuldade;

void iniciar_jogo(){ //cabeçalho do jogo
    printf("****************************\n");
    printf("*                          *\n");
    printf("*       Jogo da Forca      *\n");
    printf("*                          *\n");
    printf("****************************\n\n");

    printf("(1) Fácil, palavra com 5 letras\n");
    printf("(2) Médio, palavras com 7 letras\n");
    printf("(3) Difícil, palavras com 10 letras\n\n");
    printf("Escolha o nível de dificuldade que deseja: ");
    scanf("%d", &dificuldade);
}

void escolhe_palavra(){
    FILE* f;

    switch (dificuldade){
    case 1:
        f = fopen("facil.txt", "r");
        break;
    case 2:
        f = fopen("medio.txt", "r");
        break;

    default:
        f = fopen("dificil.txt", "r");
        break;
    }

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

    printf("\nDicas: Digite os palpites com letra MAIÚSCULA\n");
    printf("Não é necessário digitar as letras com acento\n\n");
    printf("Você pode errar até 4 vezes, na 5ª você perde!\n\n");
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

    iniciar_jogo();
    escolhe_palavra();

    do {

        desenha_forca();
        dar_palpite();

    } while(!vitoria() && !derrota());

    if(vitoria()) {
        printf("\n                                                        Parabéns, você ganhou!\n\n");

        printf("                                                             ___________      \n");
        printf("                                                            '._==_==_=_.'     \n");
        printf("                                                            .-\\:      /-.    \n");
        printf("                                                           | (|:.     |) |    \n");
        printf("                                                            '-|:.     |-'     \n");
        printf("                                                              \\::.    /      \n");
        printf("                                                               '::. .'        \n");
        printf("                                                                 ) (          \n");
        printf("                                                               _.' '._        \n");
        printf("                                                              '-------'       \n\n");

    } else {
        printf("\n                                                        Poxa vida, você foi enforcado!\n");
        printf("                                                       A palavra era *** %s ***\n\n", palavra_secreta);

        printf("                                                             _______________         \n");
        printf("                                                            /               \\       \n"); 
        printf("                                                           /                 \\      \n");
        printf("                                                          /                   \\  \n");
        printf("                                                          |   XXXX     XXXX   |    \n");
        printf("                                                          |   XXXX     XXXX   |     \n");
        printf("                                                          |   XXX       XXX   |      \n");
        printf("                                                          |                   |      \n");
        printf("                                                          \\__      XXX      __/     \n");
        printf("                                                            |\\     XXX     /|       \n");
        printf("                                                            | |           | |        \n");
        printf("                                                            | I I I I I I I |        \n");
        printf("                                                            |  I I I I I I  |        \n");
        printf("                                                            \\_             _/       \n");
        printf("                                                              \\_         _/         \n");
        printf("                                                                \\_______/           \n\n");
    }
}
