#include <stdio.h>
#include "dnodo.h"

int main(){
    struct DNode_ *dn = create_dnode(3);
    if(dn != NULL){
        set_info(dn, 7);
        printf("O valor do primeiro nodo duplo é -> %d", get_info(dn));
        struct DNode_ *dn_2 = create_dnode(6);
        if(dn_2 != NULL){
            set_next(dn, dn_2);
            printf(", ele aponta para o endereço do próximo nodo -> %p, cujo valor é %d", get_next(dn), get_info(get_next(dn)));
            struct DNode_ *dn_3 = create_dnode(9);
            if(dn_3 != NULL){
                set_previous(dn, dn_3);
                printf(", e também aponta para o endereço do nodo anterior -> %p, cujo valor é %d.\n", get_previous(dn), get_info(get_previous(dn)));
            }
            destroy(dn_3);
        }
        destroy(dn_2);
    }
    destroy(dn);
    
}