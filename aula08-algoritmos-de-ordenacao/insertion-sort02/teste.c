#include <stdio.h>
#include "insertion.h"

void listaArray(int * array, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%02d  ", array[i]);
    }
    printf("\n");
}

int main(){
    int lista[] = {3, 18, 9, 7, 4, 14, 10, 51, 11, 2, 15, 12};
    listaArray(lista, 12);
    insertionSort(lista, 12);
    listaArray(lista, 12);

    return 0;
}