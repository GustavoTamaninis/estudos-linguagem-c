#include <limits.h>
#include <stdio.h>

int main(){
    //% d para dígitos tanto positivos quanto negativos; %u para unsigned (somente positivos).
    printf("Inteiro mínimo: %d máximo: %d\n", INT_MIN, INT_MAX);
    printf("Inteiro sem sinal máximo: %u\n", UINT_MAX); //int unsigned
    printf("Número de bits por byte: %d\n", CHAR_BIT);
    printf("Char mínimo: %d máximo: %d\n", CHAR_MIN, CHAR_MAX);

    //Uma vez que as variáveis estejam declaradas, possuem informações o suficiente para que 
    //o compilador possa alocar memória para elas. Isso se dá pelo tipo que declarei antes
    //da variável:
    
    char vchar;
    int vint;
    short int vshortint;
    long int vlongint;
    float vfloat;
    double vdouble;
    long double vlongdouble;
    
    printf("Tamanho do char: %d bytes\nTamanho do int: %d bytes\nTamanho do short int: %d bytes\nTamanho do long int: %d bytes\nTamanho do float: %d bytes\nTamanho do double: %d bytes\nTamanho do long double: %d bytes.", vchar, vint, vshortint, vlongint, vfloat, vdouble, vlongdouble);

    //O 0 é considerado positivo...

    return 0;
}