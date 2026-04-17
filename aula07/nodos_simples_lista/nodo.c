//Código da aula "Manipulando estruturas com nodos simples":
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
    int info;
    struct Node_ *next;
};

struct List_ {
    struct Node_ *head;
    struct Node_ *tail;
    int size;
};

typedef struct Node_ Node;
typedef struct List_ List;

//Node* create_node(...)  (Estilo comum em C++: enfatiza que o tipo é um ponteiro).
//Node *create_node(...)  (Estilo comum em C: enfatiza que o resultado da função, ao ser "desreferenciado", é um Node).
Node* create_node(int info){
    Node * node = (Node *) malloc(sizeof(Node)); //esse typecast é opcional, aparentemente.
    node->info = info;
    node->next = NULL;
    return node;
}

List* create(){
    List * list = (List *) malloc(sizeof(List));
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
    Node * cursor = list->head;
    int i;
    for(i = 0; i < position; i++) cursor = cursor->next; //complexidade O(n)?
    *value = cursor->info;
    return 0;
}

int insert_head(List * list, int value){ //complexidade O(1)?
    Node * node = create_node(value);
    if(list->head == NULL){
        list->tail = node;
    }else{
        node->next = list->head;
    }
    list->head = node;
    list->size++;
    return 0;
}

int insert_tail(List * list, int value){
    Node * node = create_node(value);
    if(list->tail == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return 0;
}

int insert_position(List * list, int position, int value){
    if(list->size < position) return 1;
    if(position == 0) return insert_head(list, value);
    if(position == list->size) return insert_tail(list, value);
    Node * node = create_node(value);
    Node * cursor = list->head; //o curso vai começar do início
    int i;
    for(i = 0; i < position - 1; i++) cursor = cursor->next; //O cursor precisa parar 1 elemento antes da posição desejada, porque ele precisa apontar para o nó que está na posição que ele deseja ocupar.
    node->next = cursor->next; //atribuo esse próximo do cursor para o próximo do nó real que eu criei.
    cursor->next = node; // agora aponto o anterior para o meu novo nó, encaixando-o na lista.
    list->size++;
    return 0;
}

void destroy(List *list){
    Node *cursor = list->head;
    Node *temp;
    while(cursor->next != NULL){
        temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    free(cursor);
    free(list);
}


int main(){
    List *l = create(); //aqui uso um ponteiro porque o create já reserva um espaço na memória (função malloc). Outro ponto, é que uma variável "morre" após o término desta função (main); por outro lado, um ponteiro, armazenado no Heap da memória, só some quando eu a libero manualmente (função free). Além disso, é necessário para listas encadeadas, pois não preciso definir um espaço fixo de memória (o "&" até poderia ser usado, mas seria jogado no lixo automaticamente...). Por fim, economiza nas funções em que passo o "l" como parâmetro, pois não preciso "copiar" o "l" inteiro, mas somente o seu endereço.
    if(l != NULL){
        printf("Lista criada!\n");
        int i;
        for(i = 1; i < 6; i++){
            insert_tail(l, i * 10);
        }
        if(insert_position(l, 3, 35) != 0) printf("Erro na inserção de posição!\n");
        Node * cursor = l->head;
        for(int i = 0; i < 6; i++){
            printf("%d\n", cursor->info);
            cursor = cursor->next;
        }
        destroy(l);
        printf("Lista destruída.\n");
    }else{
        printf("Erro na criação da lista.");
    }
}
