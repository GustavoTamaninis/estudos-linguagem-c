#ifndef NODO_H
#define NODO_H
#include "cliente.h"
typedef struct Nodo_ Nodo;

Nodo * cria_nodo(Cliente * cliente);
void set_nodo_next(Nodo * nodo, Nodo * next);
Nodo * get_next(Nodo * nodo);
Cliente * get_data(Nodo * nodo);

#endif