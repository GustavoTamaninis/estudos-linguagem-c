#include <stdlib.h>
#include <string.h>

typedef struct Cliente_{
    char * nome;
    char * bairro;
    int pessoas;
    int criancas;
    double renda;
} Cliente;

Cliente * cria_cliente(char * nome, char * bairro, int pessoas, int criancas, double renda){
    if(nome == NULL || bairro == NULL) return NULL;
    Cliente * cliente = (Cliente *) malloc(sizeof(Cliente));
    if(cliente == NULL) return NULL;
    int tamanho_nome = strlen(nome);
    int tamanho_bairro = strlen(bairro);
    cliente->nome = (char *) malloc(sizeof(char) * (tamanho_nome + 1));
    cliente->bairro = (char *) malloc(sizeof(char) * (tamanho_bairro + 1));
    if(cliente->nome == NULL || cliente->bairro == NULL){
        free(cliente);
        return NULL;
    }
    strcpy(cliente->nome, nome);
    strcpy(cliente->bairro, bairro);

    cliente->pessoas = pessoas;

    if(criancas < 0 || criancas > 1){
        free(cliente);
        return NULL;
    }

    cliente->criancas = criancas;

    cliente->renda = renda;
    if(cliente->renda < 0){
        free(cliente);
        return NULL;
    }

    return cliente;
}

char * get_nome(Cliente * cliente){
    if(cliente == NULL) return NULL;
    return cliente->nome;
}

char * get_bairro(Cliente * cliente){
    if(cliente == NULL) return NULL;
    return cliente->bairro;
}

int get_pessoas(Cliente * cliente){
    if(cliente == NULL) return -1;
    return cliente->pessoas;
}

int get_criancas(Cliente * cliente){
    if(cliente == NULL) return -1;
    return cliente->criancas;
}

double get_renda(Cliente * cliente){
    if(cliente == NULL) return -1.0;
    return cliente->renda;
}
