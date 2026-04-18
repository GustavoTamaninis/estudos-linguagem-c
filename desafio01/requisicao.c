#include <stdlib.h>
#include "requisicao.h"
#include <string.h>

typedef struct Requisicao_ Requisicao;

struct Requisicao_{
    char nome[40];
    int inscricao;
    char procedimento[10];
};

Requisicao * cria_requisicao(char * nome, int inscricao, char * procedimento){
    Requisicao * r = (Requisicao *) malloc(sizeof(Requisicao));
    strcpy(r->nome, nome);
    r->inscricao = inscricao;
    strcpy(r->procedimento, procedimento);
    return r;
}

char * get_nome(Requisicao * requisicao){
    return requisicao->nome;
}

int get_inscricao(Requisicao * requisicao){
    return requisicao->inscricao;
}

char * get_procedimento(Requisicao * requisicao){
    return requisicao->procedimento;
}

void libera(Requisicao * requisicao){
    free(requisicao);
}
