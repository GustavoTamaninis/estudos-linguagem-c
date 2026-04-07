//Função Malloc (Memory Allocation):

#include <stdio.h> //Inclusão para poder usar a função printf
#include <stdlib.h> //Inclusão para poder usar a função malloc

int main(){
    int a = 10;
    int *p;

    //Alocando espaço para o valor que o ponteiro apontará, devolvendo o endereço alocado:
    p = (int *) malloc(sizeof(int)); // (int *) é um typecast (conversão de tipo); ssso é necessário porque o endereço retornado pelo malloc é do tipo void e o ponteiro é do tipo int

    //Se a alocação não for possível (sem memória livre), o resultado da alocação é null:
    if(p == NULL) return 1; 

    *p = a; //Atribuindo o valor da variável "a" para o local onde "p" aponta

    printf("a = %d, *p = %d\n", a, *p); //Nessa impressão, "a" e "*p" possuem o mesmo valor, mas estão em endereços distintos

    *p = 20;

    printf("a = %d, *p = %d\n", a, p); //Nessa impressão, tanto os endereços quanto os valores são diferentes

    free(p); //libero o espaço ocupado pelo "p"

    return 0; //Por alguma razão, em C, 0 é sucesso e 1, erro...
}