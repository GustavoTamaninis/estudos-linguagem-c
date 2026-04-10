#include <stdio.h>
#include <stdlib.h>

struct Queue_{
    int *fila;
    int limite;
    int ultimo;
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
    q->ultimo = 0;
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

int full(struct Queue_ *Queue){
    /*
        A função full é usada para avaliar se a fila está cheia.
        Sua complexidade é O(1).
    */
    if(Queue == NULL) return -1;

    return (Queue->ultimo == Queue->limite);
}

int insert(struct Queue_ *Queue, int value){
    /*
        A função insert insere o valor passado pelo parâmetro value no final da
        fila. Se o retorno da função for zero, a inserção foi realizada com sucesso. 
        Sua complexidade é O(1).
    */
    if(Queue == NULL || full(Queue) != 0) return 1;
    
    Queue->fila[Queue->ultimo] = value;
    Queue->ultimo++;

    return 0;
}

// int get_primeiro(struct Queue_ *Queue){ //usado para debugar...
//     return Queue->fila[0];
// }

int size(struct Queue_ *Queue){
    /*
        A função size é usada para saber a quantidade de elementos na fila.
        Sua complexidade é O(1).
    */
    if(Queue == NULL) return -1;
    return Queue->ultimo;
}

int remover(struct Queue_ *Queue, int *value){
    /*
        A função remover retira o valor do início da fila e devolve no ponteiro passado
        por parâmetro value. Se o retorno da função for zero, a remoção foi realizada
        com sucesso. A novidade aqui fica por conta da sua complexidade, que neste
        caso é O(n), pois como a função precisa deslocar todos os elementos da fila, a
        complexidade depende da quantia de elementos.
    */
    if(Queue == NULL || size(Queue) == -1) return 1;

    *value = Queue->fila[0];
    Queue->fila[0] = 0;

    //deslocar todos os elementos um espaço antes:
    int i;
    for(i = 1; i < Queue->ultimo; i++){
        Queue->fila[i-1] = Queue->fila[i];
    }
    Queue->ultimo--;
    Queue->fila[Queue->ultimo] = 0; //libera a última posição, pra não vazar memória no free abaixo.
    return 0;
}

int destroy(struct Queue_ *Queue){
    free(Queue->fila);
    free(Queue);

    return 0;
}