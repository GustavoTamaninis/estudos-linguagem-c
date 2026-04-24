//Código do infocast "Busca fullscan versus busca com sentinela"
#include <stdio.h>
void busca_sequencial(int *valores, int tamanho, int valor){
    int i = 0;
    int posicao = -1;
    do{
        if(valores[i] == valor){
            posicao = i;
            break;
        }
        i++;
    }while(i < tamanho);
    if(posicao < 0){
        printf("Valor não encontrado...\n");
    }else{
        printf("Achou: %d na posicao %d\n.", valor, posicao);
    }
}

void busca_com_sentinela(int valores[], int tamanho, int valor){
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
    if(posicao == tamanho){
        printf("Valor não encontrado...\n");
    }else {
        printf("Achou: %d na posicao %d.\n", valor, posicao);
    }
}

int main(){
    int vetor[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    busca_sequencial(vetor, 10, 5);
    busca_sequencial(vetor, 10, 11);
    busca_com_sentinela(vetor, 10, 5);
    busca_com_sentinela(vetor, 10, 11);

    return 0;
}