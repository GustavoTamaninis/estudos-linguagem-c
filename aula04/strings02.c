#include <stdio.h>
#include <string.h> //inclusão para poder usar strcpy
int main() {
    char nome_1[] = "Alberto Roberto";
    char nome_2[20];

    strcpy(nome_2, nome_1); //1º parâmetro: destino; 2º parâmetro: origem.
    printf("%s - %s\n", nome_1, nome_2);

    strcpy(nome_2, "Pedro"); //Sempre que é usada uma string entre aspas duplas, o compilador coloca o "\0".
    printf("%s - %s\n", nome_1, nome_2);  //aqui, o printf para de imprimir quando chega no caractere "\0".
    int i;
    printf("nome_2: %s\n", nome_2);
    for(i = 0; i < 20; i++){
        printf("%c-", nome_2[i]); //Por algum motivo, o strcpy não limpa o array, mas apenas sobrescreve... e o for ignora o "sentido" da string e, portanto, o caractere "\0"
    }

    return 0;
}