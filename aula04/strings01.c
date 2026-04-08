#include <stdio.h>
#include <string.h> //inclusão para poder usar strcmp
int main() {
    char nome_1[] = "Jose Antonio"; // realmente não é necessário dizer o tamanho do vetor, pois o compilador calcula sozinho. E quando se passa uma string entre aspas duplas, o compilador coloca o \0 automaticamente.
    char nome_2[] = {'J', 'o', 's', 'e', ' ', 'A', 'n', 't', 'o', 'n',
    'i', 'o', '\0'};
    char nome_3[50];

    int i = 0;
    for(i = 0; i < 12; i++) {
        nome_3[i] = nome_1[i];
    }
    nome_3[12] = '\0';

    int dif;

    //printf("%s\n", nome_1);
    //printf("%c\n", nome_1[3]);
    
    dif = strcmp(nome_1, nome_2);
    if(dif == 0) printf("nome_1 e nome_2 são iguais\n");

    dif = strcmp(nome_2, nome_3);
    if(dif == 0) printf("nome_2 e nome_3 são iguais\n");

    return 0;

    //A função strcmp permite comparar strings. Se a primeira for maior que a segunda,
    //ela retorna um número positivo; se a segunda for maior que a primeira, ela retorna
    //um número negativo. Se a primeira e a segunda forem iguais, ela retorna zero. Observe que, independentemente do tamanho do vetor, as strings foram consideradas iguais.
}