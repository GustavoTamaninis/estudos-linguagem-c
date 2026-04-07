#include <stdio.h>
#include <stdlib.h>
int main(){
    long double *ponteiro_grande = (long double *) malloc(sizeof(long double)*4000000000U); //esse U é um modificador que permite usar um número maior que 2 milhões...
    if(!ponteiro_grande){
        printf("Não alocou - %p\n", ponteiro_grande);
    }else{
        printf("Alocou - %p\n", ponteiro_grande);
    }
    free(ponteiro_grande);

    //Função Malloc:
    int *ponteiro;
    ponteiro = (int *) malloc(sizeof(int) * 10); //um espaço alocado para 10 elementos (um vetor). Por ser int, ao todo dará 40 bytes.
    if(!ponteiro) return 1;

    int i;
    for(i = 0; i < 10; i++) printf("Lixo número %d: ponteiro[%d] = %d\n", i+1, i, ponteiro[i]); //imprime os valores que já estavam na memória naquele momento da alocação. Ou seja, valores lixo. Isso ocorre com a função malloc. (às vezes o espaço pode estar vazio e inicializa com 0 ou branco).
    printf("\n\n");
    free(ponteiro);

    //Função Calloc:
    ponteiro = (int*) calloc(10, sizeof(int)); //com o Calloc, todos os espaços alocados são inicializados com 0 ou branco, se for caractere. Sendo mais custoso...
    if(!ponteiro) return 1;
    for(i = 0; i < 10; i++) printf("ponteiro[%d] = %d\n", i, ponteiro[i]);
    printf("\n\n");
    free(ponteiro);

    //Função Realloc:
    ponteiro =  (int *) malloc(sizeof(int) * 5);
    if(!ponteiro){
        printf("Não alocou!\n");
    }else{
        printf("Alocou espaço para 5 inteiros no endereço: %p\n", ponteiro);
    }

    int *temp = (int *) realloc(ponteiro, sizeof(int) * 10); //realoquei de 5 para 10 espaços no endereço.
    if(!temp){
        printf("Não realocou 5 espaços!\n");
    }else{
        ponteiro = temp;
        printf("Alocou espaço para 10 inteiros por realloc no endereço: %p\n", ponteiro);
    }

    temp = (int *) realloc(ponteiro, sizeof(int) * 10000000);
    if(!temp){
        printf("Não realocou 10 espaços!\n");
    }else{
        ponteiro = temp;
        printf("Alocou espaço para 10000000 inteiros por realloc no endereço: %p\n", ponteiro);
    }
    free(ponteiro);

    return 0;
}