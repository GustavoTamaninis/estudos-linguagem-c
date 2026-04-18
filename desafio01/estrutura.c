#include <stdlib.h>
#include "estrutura.h"

typedef struct Requisicao_ Requisicao;
typedef struct Estrutura_ Estrutura;
typedef struct Node_ Node;

struct Node_{
    Requisicao * info;
    Node * next;
};

struct Estrutura_{
    int size;
    Node * head;
    Node * tail;
};

Estrutura * create(){
    Estrutura * e = (Estrutura *) malloc(sizeof(Estrutura));
    e->head = NULL;
    e->tail = NULL;
    e->size = 0;
    return e;
}

int inserir(Estrutura * estrutura, Requisicao * requisicao){
    if(estrutura == NULL) return 1;
    Node * n = (Node *) malloc(sizeof(Node));
    n->info = requisicao;
    n->next = NULL;
    if(estrutura->head == NULL){
        estrutura->head = n;
    }else{
        estrutura->tail->next = n;
    }
    estrutura->tail = n;
    estrutura->size++;
    return 0;
}

Requisicao * remover(Estrutura * estrutura){
    if(estrutura->size == 0) return NULL;
    Requisicao * r = estrutura->head->info;
    Node * cursor = estrutura->head;
    estrutura->head = cursor->next;
    estrutura->size--;
    return r;
}

int get_size(Estrutura * estrutura){
    return estrutura->size;
}

void libera_estrutura(Estrutura * estrutura){
    free(estrutura);
}