//Tipos homogêneos (arrays) são a representação de locais contíguos de memória,
//permitindo definir uma determinada quantidade de valores de mesmo tipo.

//A seguir, arrays feito com ponteiros:
#include <stdio.h>
#include <stdlib.h>
int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //tecnicamente o vetor é um ponteiro alocado pelo compilador.
    int *ponteiro = (int *) malloc(sizeof(int) * 10);
    int i;
    
    for(i = 0; i < 10; i++) {
        ponteiro[i] = vetor[i] * 10;
        printf("vetor[%d] = %d, ponteiro[%d] = %d\n", i, vetor[i], i,
        ponteiro[i]);
    }
    free(ponteiro);

    return 0;
}