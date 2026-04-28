#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct Lista_ Lista;

Lista * cria_listas(int t_lista);
void insere_na_lista(Lista * lista, int indice, Nodo * nodo);
Lista * get_lista_bucket(Lista * listas, int t_lista, int indice);
void libera_listas(Lista * listas, int t_lista);
Nodo * get_inicio(Lista * lista);
Nodo * get_fim(Lista * lista);
int get_quantidade(Lista * lista);

#endif