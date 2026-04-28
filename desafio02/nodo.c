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

    return NULL;
}

void set_nodo_next(Nodo * nodo, Nodo * next){
    nodo->next = next;
}

Cliente * get_next(Nodo * nodo){
    return nodo->next;
}

Nodo * get_data(Nodo * nodo){
    return nodo->cliente; //passar um nodo na verdade
}

