#include <stdlib.h>
#include "cliente.h"
typedef struct Nodo_{
    Cliente * cliente;
    struct Nodo_ * next;
} Nodo;

Nodo * cria_nodo(Cliente * cliente){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    if(nodo == NULL) return NULL;
    nodo->cliente = cliente;
    nodo->next = NULL;
    return nodo;
}

void set_nodo_next(Nodo * nodo, Nodo * next){
    nodo->next = next;
}

Nodo * get_next(Nodo * nodo){
    return nodo->next;
}

Cliente * get_data(Nodo * nodo){
    return nodo->cliente;
}

