#include "nodo.h"

typedef struct Lista_ Lista;

Lista * cria_listas(int t_lista);
void insere_na_lista(Lista * lista, int indice, Nodo * nodo);
Nodo * get_inicio(Lista * lista);
Nodo * get_fim(Lista * lista);
int get_quantidade(Lista * lista);