#include <stdio.h>

int main(){
    int num = 7;
    int *p = &num;

    printf("Meu número preferido é o... %d???\n", p);

    printf("Não, o meu número preferido é o %d\n", *p);

    num = 8;

    printf("Mas se bem que o %d também é um bom número...\n", num);

    return 0;
}