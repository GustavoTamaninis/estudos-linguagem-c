#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int fullscan(int * v, int tamanho, int dado_proc){
    int indice = -1;
    bool achou = false;
    for(int j = 0; j < tamanho; j++){
        if(v[j] == dado_proc){
            achou = true;
            indice = j;
            break;
        }
    }
    
    return indice;
}

void fullscan_multiplo(int * v, int * tamanho, int dado_proc, int * indices){
    int encontrados = 0;
    for(int j = 0; j < *tamanho; j++){
        if(v[j] == dado_proc){
            indices[encontrados] = j;
            encontrados++;
        }
    }

    *tamanho = encontrados;
}

void fullscan_multiplo_ordenado(int * v, int * tamanho, int dado_proc, int * indices){
    int encontrados = 0;
    for(int j = 0; j < *tamanho; j++){
        if(v[j] > dado_proc) break;
        if(v[j] == dado_proc){
            indices[encontrados] = j;
            encontrados++;
        }
    }
    *tamanho = encontrados;
}

int main(){
    int vetor[6] = {4, 5, 2, -4, 9, -4};
    for(int i = 0; i < 6; i++){
        printf("Na pos %d, temos: %d\n", i, vetor[i]);
    }

    int dado_proc = -4;
    int tamanho = 6;

    printf("\nAchado o valor %d no índice %d...", dado_proc, fullscan(vetor, tamanho, dado_proc));

    printf("\nAchado o valor %d nos índices: ", dado_proc);
    int indices[tamanho];
    fullscan_multiplo(vetor, &tamanho, dado_proc, indices);
    for(int i = 0; i < tamanho; i++){
        printf("%d | ", indices[i]);
    }

    vetor[0] = 5;
    vetor[1] = 8;
    vetor[2] = 10;
    vetor[3] = 12;
    vetor[4] = 12;
    vetor[5] = 13;

    dado_proc = 12;
    tamanho = 6;
    int indices_2[tamanho];
    printf("\nAchado o valor %d nos índices: ", dado_proc);
    fullscan_multiplo_ordenado(vetor, &tamanho, dado_proc, indices_2);
    printf("\nTamanho %d\n", tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%d | ", indices_2[i]);
    }
}

