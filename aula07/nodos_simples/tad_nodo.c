#include <stdlib.h>

struct Node_{
    int info;
    struct Node_ *next;
};

void set_info(struct Node_ *node, int info){
    node->info = info;
}

struct Node_* create_node(int info){
    struct Node_ *n = (struct Node_*) malloc(sizeof(struct Node_));
    if(n == NULL) return NULL;

    set_info(n, info);
    n->next = NULL;

    return n;
}

int get_info(struct Node_ *node){
    return node->info;
}

void set_next(struct Node_ *node, struct Node_ *next){
    node->next = next;
}

struct Node_* get_next(struct Node_ *node){
    return node->next;
}

void destroy(struct Node_ *node){
    free(node);
}