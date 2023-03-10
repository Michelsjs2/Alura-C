#include <stdio.h>
#include <string.h> //lib necess?ria para o uso do strlen()
#include <stdlib.h>
#include <time.h>
#include "jogo_forca.h"

#include <locale.h>
#include <unistd.h> //para visualizar melhor no cmd

//vari?veis globais
char palavra_secreta[TAMANHO_PALAVRA];
char num_de_palpites[26];
int tentativas = 0;
int dificuldade;

void iniciar_jogo(){ //cabe?alho do jogo
    printf("****************************\n");
    printf("*                          *\n");
    printf("*       Jogo da Forca      *\n");
    printf("*                          *\n");
    printf("****************************\n\n");

    printf("(1) F?cil, palavra com 5 letras\n");
    printf("(2) M?dio, palavras com 7 letras\n");
    printf("(3) Dif?cil, palavras com 10 letras\n\n");
    printf("Escolha o n?vel de dificuldade que deseja: ");
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

    if(f == 0){ //tratamento de poss?vel falha do banco de dados
        printf("Infelizmente, o banco de dados n?o est? dispon?vel\n\n");
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

    printf("\nDicas: Digite os palpites com letra MAI?SCULA e o jogo n?o tem um tema espec?fico\n");
    printf("N?o ? necess?rio digitar as letras com acento\n");
    printf("Voc? pode errar at? 6 vezes, na 7? voc? perde!\n");
}

//captura o palpite do jogador e coloca em um array
void dar_palpite(){
    char palpite;
    printf("D? o palpite de uma letra: ");
    scanf(" %c", &palpite);

    num_de_palpites[tentativas] = palpite;
    tentativas++; 
}

//verifica se uma letra j? foi palpitada
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

    int erros = palpites_errados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
                                (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=4?'\\':' '), 
                                (erros>=2?'|':' '), (erros>=5?'/': ' '));
    printf(" |       %c     \n", (erros>=3?'|':' '));
    printf(" |      %c %c   \n", (erros>=6?'/':' '), 
                                (erros>=7?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavra_secreta); i++){ 

        if(verifica_palpite(palavra_secreta[i])){
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

int palpites_errados(){
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

    return erros;
}

//valida derrota do jogador
int derrota(){
    return palpites_errados() >= 7;
}

//valida a vit?ria do jogador
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
        desenha_forca();
        printf("\nParab?ns, voc? ganhou!\n");

        printf("     ___________   \n");
        printf("    '._==_==_=_.'  \n");
        printf("    .-\\:      /-. \n");
        printf("   | (|:.     |) | \n");
        printf("    '-|:.     |-'  \n");
        printf("      \\::.    /   \n");
        printf("       '::. .'     \n");
        printf("         ) (       \n");
        printf("       _.' '._     \n");
        printf("      '-------'    \n\n");

        printf("O jogo ir? fechar... ");
        sleep(3); //para dar um tempo ao usu?rio antes do jogo fechar no cmd

    } else {
        desenha_forca();
        printf("\nPoxa vida, voc? foi enforcado!\n");
        printf("A palavra era *** %s ***\n\n", palavra_secreta);

        printf("       _______________      \n");
        printf("      /               \\    \n"); 
        printf("     /                 \\   \n");
        printf("    /                   \\  \n");
        printf("    |   XXXX     XXXX   |   \n");
        printf("    |   XXXX     XXXX   |   \n");
        printf("    |   XXX       XXX   |   \n");
        printf("    |                   |   \n");
        printf("    \\__      XXX      __/  \n");
        printf("      |\\     XXX     /|    \n");
        printf("      | |           | |     \n");
        printf("      | I I I I I I I |     \n");
        printf("      |  I I I I I I  |     \n");
        printf("      \\_             _/    \n");
        printf("        \\_         _/      \n");
        printf("          \\_______/        \n\n");

        printf("O jogo ir? fechar... ");
        sleep(3);
    }
}
