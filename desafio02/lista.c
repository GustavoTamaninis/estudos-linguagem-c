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
        listas[i].qtd = 0; //remover essa variável?
    }
    return listas;
}

Lista * recupera_cliente(Estrutura * estrutura, int criterio, int complemento, char * busca){
    
}

Nodo * get_inicio(Lista * lista){
    return  lista->inicio;
}



int get_quantidade(Lista * lista){
    return lista->qtd;
}
