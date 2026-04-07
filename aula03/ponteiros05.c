//Passagem de ponteiros como parâmetros em funções:
#include <stdio.h>
void adiciona1PorValor(int valor) {
    valor++;
    printf("Argumento valor = %d\n", valor);
}

void adiciona1PorReferencia(int *valor) {
    (*valor)++;
    printf("Argumento valor = %d\n", *valor);
}

int main() {
    int valor_original = 100;
    adiciona1PorValor(valor_original);
    printf("Valor_original = %d\n\n", valor_original);

    adiciona1PorReferencia(&valor_original);
    printf("Valor_original = %d\n", valor_original);
    return 0;
}