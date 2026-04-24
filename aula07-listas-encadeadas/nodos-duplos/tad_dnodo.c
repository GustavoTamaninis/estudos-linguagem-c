#include <stdlib.h>

struct DNode_{
    int info;
    struct DNode_ *anterior;
    struct DNode_ *proximo;
};

void set_info(struct DNode_ *dnode, int info){
    dnode->info = info;
}

struct DNode_* create_dnode(int info){
    struct DNode_ *dn = (struct DNode_*) malloc(sizeof(struct DNode_)); //O asterisco vem antes pois ele é também um "tipo", usm ponteiro para struct Dnode_.
    dn->info = info;
    dn->anterior = NULL;
    dn->proximo = NULL;

    return dn;
}

int get_info(struct DNode_ *dnode){
    return dnode->info;
}

void set_next(struct DNode_ *dnode, struct DNode_ *proximo){ //lembrar de passar como segundo argumento o endereço.
    dnode->proximo = proximo;
}

struct DNode_* get_next(struct DNode_ *dnode){
    return dnode->proximo;
}

void set_previous(struct DNode_ *dnode, struct DNode_ *anterior){
    dnode->anterior = anterior;
}

struct DNode_* get_previous(struct DNode_ *dnode){ //lembrar de passar como segundo argumento o endereço.
    return dnode->anterior;
}

void destroy(struct DNode_ *dnode){
    free(dnode);
}