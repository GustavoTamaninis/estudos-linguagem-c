//Código da aula "Manipulando estruturas com nodos simples":
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode;
typedef struct List_ List;

struct DNode_{
    int info;
    DNode * next;
    DNode * previous;
};

struct List_{
    DNode * head;
    DNode * tail;
    int size;
};

DNode* create_node(int info){
    DNode * node = (DNode*) malloc(sizeof(DNode));
    node->info = info;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

List* create(){
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int list_head(List *list, int *value){
    if(list->size == 0) return 1;
    *value = list->head->info;
    return 0;
}

int list_tail(List *list, int *value){
    if(list->size == 0) return 1;
    *value = list->tail->info;
    return 0;
}

int list_position(List *list, int position, int *value){
    if(list->size < position) return 1;
    DNode * cursor = list->head;
    int i;
    for(i = 0; i < position; i++) cursor = cursor->next;
    *value = cursor->info;
    return 0;
}

int insert_head(List *list, int value){
    DNode * node = create_node(value);
    if(list->head == NULL){
        list->tail = node;
    }else{
        node->next = list->head;
        list->head->previous = node;
    }
    list->head = node;
    list->size++;
    return 0;
}

int insert_tail(List *list, int value){
    DNode * node = create_node(value);
    if(list->tail == NULL){
        list->head = node;
    }else{
        node->previous = list->tail;
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

int insert_position(List * list, int position, int value){
    if(list->size < position) return 1;
    if(position == 0) return insert_head(list, value);
    if(position == list->size) return insert_tail(list, value);
    DNode * node = create_node(value);
    DNode * cursor = list->head;
    int i;
    for(i = 0; i < position - 1; i++) cursor = cursor->next;
    node->next = cursor->next; //defino que o novo vai apontar "next" pra aquele nodo que ocupava o lugar;
    node->previous = cursor; //defino que o novo nodo vai apontar "previous" pro anterior;
    cursor->next->previous = node; //defino que aquele que ocupada o lugar passe a apontar "previous" para o novo nodo;
    cursor->next = node; //defino que o anterior vai apontar "next" pro novo nodo;
    list->size++;
    return 0;
}

void destroy(List *list){
    DNode * cursor = list->head;
    DNode * temp;
    while(cursor->next != NULL){
        temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    free(cursor);
    free(list);
}


int main() {
    List *l = create();
    if(l != NULL) {
        printf("Lista criada!\n");
        int i;
        for(i = 0; i < 5; i++) {
            //insert_head(l, (i + 1) * 10);
            insert_tail(l, (i + 1) * 10);
        }
        if(insert_position(l, 3, 35) != 0) printf("Erro na insercao de posicao\n");
        //Direção início --> fim:
        DNode *cursor = l->head;
        for(i = 0; i < 6; i++) {
            if(cursor != NULL) {
                printf("Posição %d: %d\n", i, cursor->info);
                cursor = cursor->next;
            }
        }
        printf("\n");
        //Direção fim --> início:
        cursor = l->tail;
        for(i = 0; i < 6; i++){
            if(cursor != NULL){
                printf("Posição %d: %d\n", i, cursor->info);
                cursor = cursor->previous;
            }
        }
        destroy(l);
        printf("Lista destruída.");
    }else{
        printf("Erro na criação da lista...");
    }
}