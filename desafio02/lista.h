#include "nodo.h"
#include "estrutura.h"

typedef struct Lista_ Lista;

Lista * cria_listas(int t_lista);
void insere_na_lista(Lista * lista, Cliente * cliente);
Lista * recupera_cliente(Estrutura * estrutura, int criterio, int complemento, char * busca);
Nodo * get_inicio(Lista * lista);
Nodo * get_fim(Lista * lista);
int get_quantidade(Lista * lista);