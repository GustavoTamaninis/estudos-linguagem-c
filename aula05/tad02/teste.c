#include <stdio.h>
#include "tad_contato.h"

int main(){
    tipo_contato *c = get_contato(); //esse ponteiro é necessário porque eu não sei o tamanho do tipo_contato.
    set_nome(c, "Joaquim José da Silva Xavier de Orleans e Bragança Da Silva Sauro");
    set_telefone(c, "47911112222");
    printf("------------------------\n");
    printf("--> %s \n", get_nome(c));
    printf("------------------------\n");
    printf("--> %s \n", get_telefone(c));
    printf("------------------------\n");
    printf("--> %s \n", get_cartao(c));
    printf("------------------------\n");
}