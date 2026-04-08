//Um ponteiro pode ter seu endereço alterado por operações aritméticas. Por exemplo,
//se um ponteiro é do tipo char (ocupa 2 bytes), e seu endereço atual for 200 e,
//se somado 2 a ele, ele terá como novo endereço 204. Isso acontece porque na soma de
//endereços o tamanho do tipo é considerado, ou seja, na soma ele fará 200 + (2 * 2).
#include <stdio.h>
#include <stdlib.h>
int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ponteiro = (int *) malloc(sizeof(int) * 10);
    int i;
    
    for(i = 0; i < 10; i++) {
        *ponteiro = vetor[i] * 10;
        printf("vetor[%d] = %d, ponteiro[%d] = %d\n", i, vetor[i], i, *ponteiro);
        ponteiro++; //estou somando 1 espaço de int.
    }
    ponteiro -= 10;
    free(ponteiro);

    return 0;
}