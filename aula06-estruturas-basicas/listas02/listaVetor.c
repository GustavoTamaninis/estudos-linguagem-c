#include <stdio.h>
#include <stdlib.h> //pra usar o malloc
#include "listaVetor.h"

struct List_{
    int *values;
    int length; //o tamanho do vetor
    int size; //quantos elementos há na lista
};

List* create(int length) {
    List *list = (List *) malloc(sizeof(List));
    list->values = (int *) malloc(sizeof(int) * length);
    list->length = length;
    list->size = 0;
    return list;
}

int list_head(List *list, int *value) {
    if(list->size == 0) return 1;
    *value = list->values[0];
    return 0;
}

int list_tail(List *list, int *value) {
    if(list->size == 0) return 1;
    *value = list->values[list->size - 1];
    return 0;
}

int list_position(List *list, int position, int *value) {
    if(list->size < position) return 1;
    *value = list->values[position];
    return 0;
}

int insert_head(List *list, int value) {
    if(full(list)) return 1;
    int i;
    for(i = list->size; i > 0; i--) {
        list->values[i] = list->values[i - 1];
    }
    list->values[0] = value;
    list->size++;
    return 0;
}
int insert_tail(List *list, int value) {
    if(full(list)) return 1;
    list->values[list->size] = value;
    list->size++;
    return 0;
}

int insert_position(List *list, int position, int value) {
    if(full(list) || list->size < position) return 1;
    int i;
    for(i = list->size; i > position; i--) {
        list->values[i] = list->values[i - 1];
    }
    list->values[position] = value;
    list->size++;
    return 0;
}

int remove_head(List *list, int *value) {
    if(list->size == 0) return 1;
    *value = list->values[0];
    int i;
    for(i = 1; i < list->size; i++) {
        list->values[i - 1] = list->values[i];
    }
    list->size--;
    return 0;
}

int remove_tail(List *list, int *value) {
    if(list->size == 0) return 1;
    *value = list->values[list->size - 1];
    list->size--;
    return 0;
}

int remove_position(List *list, int position, int *value) {
    if(list->size <= position) return 1;
    *value = list->values[position];
    int i;
    for(i = position; i < (list->size - 1); i++) {
        list->values[i] = list->values[i + 1];
    }
    list->size--;
    return 0;
}

int size(List *list) {
    return list->size;
}

int full(List *list){
    if(list->size == list->length) return 1;
    return 0;
}

void destroy(List *list){
    free(list->values);
    free(list);
}

int main(){
    List *l = create(10);
    if(l != NULL){
        printf("Lista criada!\n");
        int i;
        for(i = 0; i < 5; i++){
            insert_head(l, (i+1) * 10);
            // insert_tail(l, (i+1) * 10);
        }
        
        if(insert_position(l, 3, 35) != 0) printf("Erro na insercao de posicao\n");
        int temp;
        for(i = 0; i < 6; i++) {
            if(remove_tail(l, &temp) == 0) {
                //if(remove_position(l, 2, &temp) == 0) {
                printf("removido %d\n", temp);
            }else {
                printf("Erro na remocao\n");
            }
        }
        destroy(l);
    }
}
