#include "contato.h"
#include <stdlib.h>
#include <string.h>

struct Contato_{
    char * nome;
    char * telefone;
};

Contato * get_contato(char * nome, char * telefone){
    Contato * contato = (Contato *) malloc(sizeof(Contato));
    if(contato == NULL) return NULL;
    int tamanho_nome = strlen(nome);
    int tamanho_telefone = strlen(telefone);
    contato->nome = (char *) malloc(sizeof(char) * (tamanho_nome + 1));
    if(contato->nome == NULL){
        free(contato);
        return NULL;
    }
    contato->telefone = (char *) malloc(sizeof(char) * (tamanho_telefone + 1));
    if(contato->telefone == NULL){
        free(contato);
        return NULL;
    }
    strcpy(contato->nome, nome);
    strcpy(contato->telefone, telefone);

    return contato;
}

char * get_nome(Contato * contato){
    return contato->nome;
}

char * get_telefone(Contato * contato){
    return contato->telefone;
}
