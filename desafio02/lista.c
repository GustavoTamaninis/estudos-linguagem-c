#include "nodo.h"
#include "estrutura.h"
#include <stdlib.h>

typedef struct Lista_{
    Nodo * inicio;
    Nodo * fim;
    int qtd;
} Lista;

Lista * cria_listas(int t_lista){
    if(t_lista <= 0) return NULL;
    Lista * listas = (Lista *) malloc(sizeof(Lista) * t_lista);
    for(int i = 0; i < t_lista; i++){
        listas[i].inicio = NULL;
        listas[i].fim = NULL;
        listas[i].qtd = 0;
    }
    return listas;
}

void insere_na_lista(Lista * lista, int indice, Nodo * nodo){
    if(lista[indice].inicio == NULL){
        lista[indice].inicio = nodo;
        lista[indice].fim = nodo;
    }else{
        set_nodo_next(lista[indice].fim, nodo);
        lista[indice].fim = nodo;
    }
    lista[indice].qtd++;
}

Nodo * get_inicio(Lista * lista){
    return  lista->inicio;
}

Nodo * get_fim(Lista * lista){
    return lista->fim;
}

int get_quantidade(Lista * lista){
    return lista->qtd;
}
