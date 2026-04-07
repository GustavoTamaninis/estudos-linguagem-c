#include <stdio.h>
int main(){
    int v1 = 99;
    int v2[] = {10, 20, 30, 40, 50};
    int v3[10] = {100, 200, 300, 400, 500};

    printf("Tamanho de v1: %d\nTamanho de v2: %d\nTamanho de v3: %d\n\n", sizeof(v1), sizeof(v2), sizeof(v3));

    int *ponteiro;

    ponteiro = &v1;
    printf("O valor de v1 por ponteiro: %d - %d\n\n", *ponteiro, v1);

    *ponteiro = 88;
    printf("Alterando o valor de v1 pelo ponteiro: %d - %d\n\n", *ponteiro, v1);

    ponteiro = v2; //este ponteiro apenas está pegando o primeiro elemento e não o vetor inteiro...
    printf("Tamanho de v2: %d, tamanho de ponteiro %d\n\n", sizeof(v2), sizeof(*ponteiro));

    ponteiro = &v3[2];
    printf("Valor de v3[2] pelo ponteiro: %d e pelo vetor: %d\n", *ponteiro, v3[2]);
}