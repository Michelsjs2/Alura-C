#include <stdio.h>
#include <string.h> //lib necessária para o uso do strlen()

#include <locale.h>

//variáveis globais
int vitoria = 0;
int derrota = 0;

void iniciar_jogo(){ //cabeçalho do jogo
    printf("****************************\n");
    printf("*                          *\n");
    printf("*       Jogo da Forca      *\n");
    printf("*                          *\n");
    printf("****************************\n\n");
}

//captura o palpite do jogador e coloca em um array
void fpalpite(char possibilidades_palpites[26], int* palpites_feitos){ //o int* é um ponteiro que aponta para um inteiro
    char palpite;
    printf("Dê o palpite de uma letra: ");
    scanf(" %c", &palpite);

    possibilidades_palpites[(*palpites_feitos)] = palpite; //o (*var) é necessário para pegar o valor que está dentro da variável para onde apontou o ponteiro
    (*palpites_feitos)++;
}

//verifica se uma letra já foi palpitada
int verifica_palpite(char letra, char possibilidades_palpites[26], int palpites_feitos){
    int acertou = 0;

    for(int j = 0; j < palpites_feitos; j++){
        if(possibilidades_palpites[j] == letra){
            acertou = 1;
            break;
        }
    }

    return acertou;
}

//imprime a palavra secreta
void desenha_forca(char palavra_secreta[20], char possibilidades_palpites[26], int palpites_feitos){
    for (int i = 0; i < strlen(palavra_secreta); i++){ 

        int acertou = verifica_palpite(palavra_secreta[i], possibilidades_palpites, palpites_feitos);
        if(acertou){
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

void escolhe_palavra(char palavra_secreta[20]){
    sprintf(palavra_secreta, "TESTANDO"); //esse comando facilita a inserção de uma palavra dentro de um array de caracteres
}

//valida o erro dos palpites e derrota do jogador
void verifica_erros(char palavra_secreta[20], char possibilidades_palpites[26], int palpites_feitos){

    int erros = 0;

    for(int i; i < palpites_feitos; i++){
        int letra_certa = 0;

        for (int j = 0; j < strlen(palavra_secreta); j++){
            if(possibilidades_palpites[i] == palavra_secreta[j]){
                
                letra_certa = 1;
                break;
            }
        }
        
        if(!letra_certa) erros++;
    }

    if(erros >= 5){
        derrota = 1;
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    char palavra_secreta [20]; //uma variável que possui um [] no final de um array
    char possibilidades_palpites[26];
    int palpites_feitos = 0;

    escolhe_palavra(palavra_secreta);
    iniciar_jogo();

    do {

        desenha_forca(palavra_secreta, possibilidades_palpites, palpites_feitos);
        fpalpite(possibilidades_palpites, &palpites_feitos);
        verifica_erros(palavra_secreta, possibilidades_palpites, palpites_feitos);

    } while(!vitoria && !derrota);
}
