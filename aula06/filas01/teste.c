#include <stdio.h>
#include "fila.h"

int main(){
    struct Queue_ *q = create(5);

    int value;
    peek(q, &value);
    printf("O primeiro na fila é o número %d!\n", value);

    destroy(q);

}