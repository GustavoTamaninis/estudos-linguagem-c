#include <stdio.h>
#include <stdlib.h>

struct Queue_{
    int *fila;
    int limite;
    int primeiro;
};

struct Queue_* create(int length){
    /*
        Função que cria uma fila vazia, devolvendo-a como retorno. 
        Essa função recebe como parâmetro o tamanho da fila a criar.
        Se a função apresentar erro, o ponteiro devolvido será NULL.
        Sua complexidade é O(1).
    */

    if(length < 0) return NULL;

    struct Queue_ *q = (struct Queue_*) malloc(sizeof(struct Queue_));
    if(q == NULL) return NULL;

    q->fila = (int*) malloc(length * sizeof(int));
    if(q->fila == NULL){
        free(q);
        return NULL;
    }
    // q->fila[0] = 12;
    // q->fila[1] = 84;

    q->limite = length;
    return q;
}

int peek(struct Queue_ *Queue, int *value){
    /*
        A função peek consulta o elemento que está no início da fila, sem retirá-lo.
        O retorno do valor do início da fila acontece pelo ponteiro value passado como
        parâmetro. Sua complexidade é O(1)
    */
    if(Queue == NULL) return 1;
    if(value != NULL) *value = Queue->fila[0];

    return 0;
}

int full(struct Queue_ *Queue_){

}

int insert(struct Queue_ *Queue, int value){
    
}

// int remove(struct Queue_ *Queue, int *value){

// }

int size(struct Queue_){

}

int destroy(struct Queue_ *Queue){
    free(Queue->fila);
    free(Queue);
}