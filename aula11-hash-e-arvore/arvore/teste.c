#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct Arvore_{
    int info;
    struct Arvore_ *esquerda;
    struct Arvore_ *direita;
} Arvore;

Arvore * criar(int valor){
    Arvore * arvore = (Arvore *) malloc(sizeof(struct Arvore_));
    arvore->info = valor;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    
    return arvore;
}

Arvore * inserir(Arvore * arvore, int valor){
    if(arvore == NULL){
        arvore = criar(valor);
    }else if(arvore->info > valor){
        if(arvore->esquerda == NULL){
            arvore->esquerda = criar(valor);
        }else{
            arvore->esquerda = inserir(arvore->esquerda, valor);
        }
    }else{
        if(arvore->direita == NULL){
            arvore->direita = criar(valor);
        }else{
            arvore->direita = inserir(arvore->direita, valor);
        }
    }
    
    return arvore;
}

void em_ordem(Arvore * arvore){
    if(arvore != NULL){
        em_ordem(arvore->esquerda);
        printf("%d ", arvore->info);
        em_ordem(arvore->direita);
    }
}

void pre_ordem(Arvore * arvore){
    if(arvore != NULL){
        printf("%d ", arvore->info);
        pre_ordem(arvore->esquerda);
        pre_ordem(arvore->direita);
    }
}

void pos_ordem(Arvore * arvore){
    if(arvore != NULL){
        pos_ordem(arvore->esquerda);
        pos_ordem(arvore->direita);
        printf("%d ", arvore->info);
    }
}

Arvore * maior(Arvore * arvore){
    Arvore * temp = arvore;
    if(temp->direita == NULL){
        arvore = arvore->esquerda;
    }else{
        return maior(arvore->direita);
    }
}

int busca(Arvore * arvore, int valor){
    if(arvore == NULL){ //útil para a recursão abaixo.
        return FALSE;
    }else{
        if(arvore->info == valor){
            return TRUE;
        }else{
            if(arvore->info > valor){
                return busca(arvore->esquerda, valor);
            }else{
                return busca(arvore->direita, valor);
            }
        }
    }
}

Arvore * remover(Arvore * arvore, int valor){
    if(arvore == NULL){
        printf("Arvore vazia\n");
        return NULL;
    }
    if(arvore->info == valor){ //Remover valor na raíz
        if(arvore->esquerda == NULL){ //Se não tiver filho à esquerda:
            arvore = arvore->direita; //o filho da direita assume seu lugar.
        }else if(arvore->direita == NULL){ //Caso o da direita não exista:
            arvore = arvore->esquerda; //o filho da esquerda assume seu lugar.
        }else{ //possui os dois filhos
            Arvore * temp = maior(arvore->esquerda); //busca o maior
            int aux = temp->info;
            arvore->info = aux; //coloca o valor do maior na raíz.
            free(temp);
        }
    }else{
        if(arvore->info > valor){
            arvore->esquerda = remover(arvore->esquerda, valor);
        }else{
            arvore->direita = remover(arvore->direita, valor);
        }
    }

    return arvore;
}

int main(){
    int valores[] = {10, 1, 5, 3, 9, 2, 4, 7, 6, 8};
    int i;
    Arvore * arvore = NULL;
    for(i = 0; i < 10; i++){
        printf("Inseriu %d\n", valores[i]);
        arvore = inserir(arvore, valores[i]);
    }
    printf("Em ordem: ");
    em_ordem(arvore);
    printf("\n");
    printf("Pré Ordem: ");
    pre_ordem(arvore);
    printf("\n");
    printf("Pós Ordem: ");
    pos_ordem(arvore);
    printf("\n");

    printf("=--------------------------------------=\n");
    if(busca(arvore, 8)) printf("O valor %d está na lista!", 8);
    printf("\n");

    printf("=--------------------------------------=\n");

    printf("Ao remover o elemento 8:\n");
    arvore = remover(arvore, 8);
    printf("Em ordem: ");
    em_ordem(arvore);
    printf("\n");

    printf("=--------------------------------------=\n");
    if(!busca(arvore, 8)) printf("O valor %d não está mais na lista...", 8);

    return 0;
}