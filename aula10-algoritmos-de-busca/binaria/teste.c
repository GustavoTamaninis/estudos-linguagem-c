#include <stdio.h>
int busca_com_sentinela(int valores[], int tamanho, int valor) {
    int i = 0;
    int posicao = -1;
    valores[tamanho] = valor;
    do{
        if(valores[i] == valor) {
            posicao = i;
            break;
        }
        i++;
    }while(1);
    return posicao == tamanho ? -1 : posicao;
}

int busca_binaria(int valores[], int inicio, int fim, int valor) {
    int meio;
    if (inicio > fim) return -1;
    else{
        meio = (inicio + fim) / 2;
        if(valores[meio] == valor) {
            return meio;
        }else if (valores[meio] > valor) {
            return busca_binaria(valores, inicio, --meio, valor);
        }else {
            return busca_binaria(valores, ++meio, fim, valor);
        }
    }
}

int main() {
    int vetor[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Posicao = %d\n", busca_binaria(vetor, 0, 9, 5));
    printf("Posicao = %d\n", busca_binaria(vetor, 0, 9, 11));
    printf("Posicao = %d\n", busca_com_sentinela(vetor, 10, 5));
    printf("Posicao = %d\n", busca_com_sentinela(vetor, 10, 11));

    return 0;
}