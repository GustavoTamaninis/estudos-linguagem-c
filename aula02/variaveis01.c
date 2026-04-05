#include <stdio.h>
int global = 100;

void funcao(){
    printf("Na função, endereço: %p, valor: %d\n", &global, global); //& representa o endereço da variável.
}
void main(){
    printf("No main, antes da declaração, endereço: %p, valor %d\n", &global, global);
    int global = 200;
    printf("No main, depois da declaração, endereço: %p, valor %d\n", &global, global);

    int i = 1;
    while(i > 0){
        i--;
        printf("No while antes da declaração, endereço: %p, valor: %d\n", &global, global);
        int global = 300;
        printf("No while depois da declaração, endereço: %p, valor %d\n", &global, global);
    }
    funcao();
}