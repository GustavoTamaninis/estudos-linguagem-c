#include <stdio.h> //se isso é só pra printf, acho que nem é necessário.
#include <stdlib.h>

struct List_{
    int *vetor;
    int limite;
    int fim; //é um contador de quantos elementos há na lista e, ainda, identifica o fim da lista.
};

struct List_* create(int length){
    if(length <= 0) return NULL;

    struct List_ *l = (struct List_*) malloc(sizeof(struct List_));
    if(l == NULL) return NULL;

    l->vetor = (int *) malloc(length * sizeof(int));
    if(l->vetor == NULL){
        free(l);
        return NULL;
    }

    l->limite = length;
    l->fim = 0;

    return l;
}

int list_Head(struct List_ *list, int *value){
    if(list == NULL) return 1;
    *value = list->vetor[0];

    return 0;
}

int list_Tail(struct List_ *list, int *value){
    if(list == NULL) return 1;
    *value = list->vetor[list->fim-1];

    return 0;
}

int list_position(struct List_ *list, int position, int *value){
    if(list == NULL || position < 0 || position > list->limite) return 1;
    *value = list->vetor[position];

    return 0;
}

int full(struct List_ *list){
    if(list == NULL) return -1;
    
    return list->fim == list->limite;
}

int insert_Head(struct List_ *list, int value){
    if(list == NULL || full(list) || list->fim == 0) return 1;  

    int i;
    for(i = list->fim; i > 0; i--){
        list->vetor[i] = list->vetor[i-1];
    }

    list->vetor[0] = value;
    list->fim++;

    return 0;
}

int insert_Tail(struct List_ *list, int value){
    if(list == NULL || full(list) || list->fim == 0) return 1;
    list->vetor[list->fim] = value;
    list->fim++; //de repente puxar pra cima este e ajustar o código (DEPOIS) -> confira o insert_Head tbm.

    return 0;
}

int insert_position(struct List_ *list, int position, int value){
    if(list == NULL || full(list) || position > list->fim || position < 0) return 1;
    
    int i;
    for(i = list->fim; i >= position; i--){
        list->vetor[i] = list->vetor[i-1];
    }
    list->vetor[position] = value;
    list->fim++;

    return 0;
}

int remove_Head(struct List_ *list, int *value){
    if(list == NULL) return 1;
    *value = list->vetor[0];


    int i;
    for(i = 0; i < list->fim-1; i++){
        list->vetor[i] = list->vetor[i+1]; //digamos que eu tenha [10, 20, 30]. Ao usar esta função, removo o 10, o 20 se desloca para o lugar do 10, e o 30, para o lugar no 20. O último item (30) fica duplicado, mas é lixo, que, no primeiro insert_Tail, será sobrescrito. O que importa aqui é a variável contadora, neste caso, o "list->fim".
    }
    list->fim--;

    return 0;
}

int remove_Tail(struct List_ *list, int *value){
    if(list == NULL) return 1;
    *value = list->vetor[list->fim-1];

    list->vetor[list->fim-1] = 0;
    list->fim--;

    return 0;
}

int remove_position(struct List_ *list, int position, int *value){
    if(list == NULL || position < 0 || position > list->fim-1) return 1;
    *value = list->vetor[position];

    int i;
    for(i = position; i < list->fim-1; i++){
        list->vetor[i] = list->vetor[i+1];
    }
    list->fim--;

    return 0;
}

int size(struct List_ *list){
    if(list == NULL) return -1;

    return list->fim;
}

void destroy(struct List_ *list){
    free(list->vetor);
    free(list);
}