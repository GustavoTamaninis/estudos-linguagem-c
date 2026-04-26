//Código da aula "Tabela hash de contatos":
#include "contato.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node_{
    Contato * contato;
    struct Node_ * next;
} Node;

typedef struct Lista_{
    Node * inicio;
    Node * fim;
} Lista;

typedef struct Tabela_{
    Lista * lista;
    int t_lista;
    int qtd;
} Tabela;

//Funções de Node:
Node * cria_node(Contato * contato){
    Node * node = (Node *) malloc(sizeof(Node));
    if(node == NULL) return NULL;
    node->contato = contato;
    node->next = NULL;

    return node;
}

void set_node_next(Node * node, Node * next){
    node->next = next;
}

Node * get_node_next(Node * node){
    return node->next;
}

Contato * get_node_contato(Node * node){
    return node->contato;
}

Contato * clone_contato(Contato * contato){
    Contato * contato_clone = get_contato(get_nome(contato), get_telefone(contato));
    return contato_clone;
}

//Função Hash:
int calc_indice(Tabela * tabela, char * nome){ //o nome é a chave desta tabela hash.
    int tamanho = strlen(nome);
    int i, indice = 0;
    for(i = 0; i < tamanho; i++){
        indice += (nome[i] * (i + 1) / ((i % tabela->t_lista) + 1));
    }

    return indice % tabela->t_lista; //a posição em que o elemento será inserido na tabela.
}

//Funções Tabela:
Tabela * cria_tabela(int tamanho){
    Tabela * tabela = (Tabela *) malloc(sizeof(Tabela));
    tabela->lista = (Lista *) malloc(sizeof(Lista) * tamanho);
    int i;
    for(i = 0; i < tamanho; i++){
        tabela->lista[i].inicio = NULL;
        tabela->lista[i].fim = NULL;
    }
    tabela->qtd = 0;
    tabela->t_lista = tamanho;

    return tabela;
}

void insere(Tabela * tabela, Contato * contato){
    Node * node = cria_node(contato);
    int indice = calc_indice(tabela, get_nome(contato));
    if(tabela->lista[indice].inicio == NULL){
        tabela->lista[indice].inicio = node;
        tabela->lista[indice].fim = node;
    }else{
        set_node_next(tabela->lista[indice].fim, node);
        tabela->lista[indice].fim = node;
    }
    tabela->qtd++;
}

Contato * consulta(Tabela * tabela, char * nome){
    int indice = calc_indice(tabela, nome);
    Node * cursor = tabela->lista[indice].inicio;
    while(cursor != NULL){
        char * nome_lista = get_nome(cursor->contato);
        if(strcmp(nome, nome_lista) == 0) return cursor->contato;
        cursor = get_node_next(cursor);
    }
    return NULL;
}

Contato * retira(Tabela * tabela, char * nome){
    int indice = calc_indice(tabela, nome);
    Contato * contato;
    Node * cursor = tabela->lista[indice].inicio;
    Node * anterior = tabela->lista[indice].inicio;
    while(cursor != NULL){
        char * nome_lista = get_nome(cursor->contato);
        if(strcmp(nome, nome_lista) == 0){
            contato = clone_contato(cursor->contato);
            if(anterior == cursor){
                tabela->lista[indice].inicio = NULL;
                tabela->lista[indice].fim = NULL;
            }else if(get_node_next(cursor) == NULL){
                set_node_next(cursor, NULL);
            }else{
                set_node_next(anterior, get_node_next(cursor));
            }
            free(cursor);
            tabela->qtd--;
            return contato;
        }
        cursor = get_node_next(cursor);
    }
    return NULL;
}

int main(){
    char nomes[][20] = {"Joao 1", "Alberto 2", "Sônia 3", "Maria 4", "Gustavo 5", "Antonio 6", "Sérgio 7", "Fernando 8", "Eduardo 9", "Ana 10"};
    char tels[][20] = {"1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999", "0000"};
    int i;
    Tabela * tabela = cria_tabela(7);
    for(i = 0; i < 10; i++){
        Contato * contato = get_contato(nomes[i], tels[i]);
        insere(tabela, contato);
    }
    printf("Retirado o contato %d\n", retira(tabela, "Joao 1"));
    for(i = 0; i < 10; i++){
        Contato * contato = consulta(tabela, nomes[i]);
        if(!contato){
            printf("Contato %s não encontrado\n", nomes[i]);
        }else{
            printf("Nome: %10s, Telefone: %10s\n", get_nome(contato), get_telefone(contato));
        }
    }

    return 0;
}
