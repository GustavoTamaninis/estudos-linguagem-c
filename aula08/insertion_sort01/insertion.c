#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    printf("Insertion Sort em Vetor:\n");
    int vetor[6] = {85, 12, 59, 45, 72, 51};

    for(int i = 0; i < 6; i++) printf("Na posição %d está o valor %d\n", i, vetor[i]);
    printf("\n");

    for(int i = 1; i < 6; i++){
        int temp = vetor[i]; //1- guardo
        int j = i - 1;

        while(j >= 0 && vetor[j] > temp){ //2- comparo com os anteriores
            vetor[j + 1] = vetor[j]; //3- se o elemento anterior for maior, desloco uma casa para a direita
            j--;
        }

        vetor[j + 1] = temp; //4- insiro o valor guardado no espaço aberto.

        for(int j = 0; j < 6; j++) printf("Na posição %d está o valor %d\n", j, vetor[j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}