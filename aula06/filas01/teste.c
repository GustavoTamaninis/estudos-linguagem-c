#include <stdio.h>
#include "fila.h"

int main(){
    struct Queue_ *q = create(5);
    int value;
    int i = 0;

    peek(q, &value);
    printf("O primeiro na fila é o número %d!\n", value);

    int v = 5;
    insert(q, v);
    printf("Adicionei o valor %d à fila!\n", v);

    peek(q, &value);
    printf("O primeiro continua sendo o número %d!\n", value);

    v = 10;
    insert(q, v);
    printf("Adicionei o valor %d à fila!\n", v);

    peek(q, &value);
    printf("O primeiro continua sendo o número %d.\n", value);

    for(v = 15; v < 40; v+=5){
        if(insert(q, v) == 1){
            printf("A fila está cheia...\n");
        }else{{
            printf("Adicionei o valor %d à fila!\n", v);
        }}
    }

    printf("--------------------------------------\n");
    printf("Essa fila tem %d elementos...\n", size(q));
    
    printf("--------------------------------------\n");
    remover(q, &value);
    printf("Removido o valor %d da fila!\n", value);

    printf("--------------------------------------\n");
    peek(q, &value);
    printf("O primeiro na fila é o número %d.\n", value);

    printf("--------------------------------------\n");
    remover(q, &value);
    printf("Removido o valor %d da fila!\n", value);

    printf("--------------------------------------\n");
    peek(q, &value);
    printf("O primeiro na fila é o número %d.\n", value);

    destroy(q);
}