#include <stdio.h>
#include "nodo.h"

int main(){
    struct Node_ *n = create_node(8);
    struct Node_ *n_2 = create_node(11);

    printf("O meu primeiro nó contém o número %d\n", get_info(n));
    set_next(n, n_2);
    printf("O próximo nó possui o endereço %d\n", get_next(n));
    destroy(n);
}
