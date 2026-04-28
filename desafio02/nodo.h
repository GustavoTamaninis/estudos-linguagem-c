#include "cliente.h"

typedef struct Node_ Nodo;

Nodo * cria_nodo(Cliente * cliente);
void set_nodo_next(Nodo * nodo, Nodo * next);
Cliente * get_next(Nodo * nodo);
Nodo * get_data(Nodo * nodo);