//Código da aula "Recursividade", onde são comparadas uma função de cálculo de fatorial
//iterativa e uma recursiva:
#include <stdio.h>

int fatorial_iterativa(int n){
    int resultado = 1;
    if(n < 0) return -1;
    if(n == 0) return resultado;
    for(;n > 0; n--){
        resultado *= n;
    }
    return resultado;
}

int fatorial_recursiva(int n){
    if(n < 0) return -1;
    if(n == 0) return 1;
    return n * fatorial_recursiva(n-1);
}

int fatorial_recursiva_final(int n, int resultado){
    if(n < 0) return -1;
    if(n == 0) return resultado;
    return fatorial_recursiva_final(n-1, n * resultado);
}

int main(){
    int i;
    printf("Fatorial Iterativa:\n");
    for(i = -2; i < 8; i++){
        if(fatorial_iterativa(i) < 0){
            printf("Não existe fatorial de %d...\n", i);
        }else{
            printf("Fatorial de %d = %8d\n", i, fatorial_iterativa(i));
        }
    }

    printf("\nFatorial Recursiva (Básica):\n");
    for(i = -2; i < 8; i++){
        if(fatorial_recursiva(i) < 0){
            printf("Não existe fatorial de %d...\n", i);
        }else{
            printf("Fatorial de %d = %8d\n", i, fatorial_recursiva_final(i, 1));
        }
    }

    printf("\nFatorial Recursiva (Final):\n");
    for(i = -2; i < 8; i++){
        if(fatorial_recursiva_final(i, 1) < 0){
            printf("Não existe fatorial de %d...\n", i);
        }else{
            printf("Fatorial de %d = %8d\n", i, fatorial_recursiva_final(i, 1));
        }
    }

    return 0;
}