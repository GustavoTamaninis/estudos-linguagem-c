#include <stdio.h>
#include "lista.h"

int main(){
    struct List_ *l = create(4);
    int value;
    int *v = &value;
    int i;

    insert_Head(l, 5);
    printf("Adicionado %d à lista na primeira posição!\n", 5);

    for(i = 9; i < 54; i+=9){
        if(insert_Tail(l, i) == 1) printf("a lista está cheia...\n"); //se trocar pra insert_Head, fica invertido (como deveria).
        else printf("Adicionado %d à lista!\n", i);
    }

    printf("----------------------------------------\n");
    list_Tail(l, v);
    printf("O número %d é o último da lista...\n", value);

    printf("A lista possui %d elementos\n", size(l));

    printf("----------------------------------------\n");
    remove_Head(l, v);
    printf("Removi o elemento %d do início da fila...\n", value);
    list_Head(l, v);
    printf("Agora o primeiro item da lista é o número %d\n\n", value);

    remove_Tail(l, v);
    printf("Removi o elemento %d do final da fila...\n", value);
    list_Tail(l, v);
    printf("Agora o último item da lista é o número %d\n\n", value);

    printf("----------------------------------------\n");
    int pos = 1;
    list_position(l, pos, &value);
    printf("O item da posição %d é o número %d\n", 1, value);
    
    printf("----------------------------------------\n");
    printf("A lista agora possui %d elementos\n", size(l));

    printf("----------------------------------------\n");
    insert_Tail(l, 40);
    printf("Adicionado o número 40 à lista.\n");

    pos = 2;
    insert_position(l, pos, 222);
    printf("Adicionado o número %d na posição %d!\n", value, pos);

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    list_Head(l, &value);
    printf("O item na posição inicial da lista é %d.\n", value);
    list_position(l, 1, &value);
    printf("O item na posição 1 da lista é %d.\n", value);
    list_position(l, 2, &value);
    printf("O item na posição 2 da lista é %d.\n", value);
    list_position(l, 3, &value);
    printf("O item na posição final da lista é %d.\n", value);

    printf("----------------------------------------\n");
    pos = 1;
    remove_position(l, pos, v);
    printf("Removido o item %d na posição %d da lista.\n", value, pos);

    printf("----------------------------------------\n");
    list_Head(l, &value);
    printf("O item na posição inicial da lista é %d.\n", value);
    list_position(l, 1, &value);
    printf("O item na posição 1 da lista é %d.\n", value);
    list_position(l, 2, &value);
    printf("O item na posição 2 da lista é %d.\n", value);
    list_position(l, 3, &value);
    printf("O item na posição final da lista é %d.\n", value); //como eu removi 1 item, a função não me retornou nada, portanto, o valor aqui não deve ser levado a sério.

    destroy(l);
}