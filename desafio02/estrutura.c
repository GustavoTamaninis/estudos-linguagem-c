#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "lista.h"
#include "nodo.h"

typedef struct Estrutura_{
    Lista * lista_nomes;
    Lista * lista_bairros;
    Lista * lista_pessoas;
    Lista * lista_criancas;
    Lista * lista_renda;
    int t_lista;
    int qtd;
} Estrutura;

Estrutura * cria_estrutura(){
    Estrutura * estrutura = (Estrutura *) malloc(sizeof(Estrutura));
    estrutura->qtd = 0;
    estrutura->t_lista = 11;

    estrutura->lista_nomes = cria_listas(estrutura->t_lista);
    estrutura->lista_bairros = cria_listas(estrutura->t_lista);
    estrutura->lista_pessoas = cria_listas(estrutura->t_lista);
    estrutura->lista_criancas = cria_listas(estrutura->t_lista);
    estrutura->lista_renda = cria_listas(estrutura->t_lista);
    
    return estrutura;
}

int calc_indice_nome(Estrutura * estrutura, char * nome){
    if(estrutura == NULL || nome == NULL) return -1;
    int tamanho = strlen(nome);
    int indice = 0;
    for(int i = 0; i < tamanho; i++){
        indice += (nome[i] * (i + 1) / ((i % estrutura->t_lista) + 1));
    }

    return indice % estrutura->t_lista;
}

int calc_indice_bairro(Estrutura * estrutura, char * bairro){
    if(estrutura == NULL || bairro == NULL) return -1;
    int tamanho = strlen(bairro);
    int indice = 0;
    for(int i = 0; i < tamanho; i++){
        indice += (bairro[i] * (i + 1) / ((i % estrutura->t_lista) + 1));
    }

    return indice % estrutura->t_lista;
}

int calc_indice_pessoas(Estrutura * estrutura, int pessoas){
    if(estrutura == NULL || pessoas <= 0) return -1;
    int faixa;
    if(pessoas == 1) faixa = 1;
    if(pessoas == 2) faixa = 2;
    if(pessoas == 3) faixa = 3;
    if(pessoas == 4) faixa = 4;
    if(pessoas >= 5) faixa = 5;
    return faixa % estrutura->t_lista;
}

int calc_indice_criancas(Estrutura * estrutura, int criancas){
    if(estrutura == NULL || criancas < 0 || criancas > 1) return -1;

    return criancas % estrutura->t_lista;
}

int calc_indice_renda(Estrutura * estrutura, double renda){
    if(estrutura == NULL || renda < 0) return -1;
    int faixa;
    if(renda <= 2000) faixa = 1;
    else if(renda <= 3000) faixa = 2;
    else if(renda <= 5000) faixa = 3;
    else faixa = 4;

    return faixa % estrutura->t_lista;
}

void insere_cliente(Estrutura * estrutura, int chave, Cliente * cliente){
    if(estrutura == NULL){
        estrutura = cria_estrutura();
        if(estrutura == NULL) return;
    }
    if(cliente == NULL) return;
    Nodo * nodo = cria_nodo(cliente);
    if(nodo == NULL) return;

    if(chave == 1){
        int indice = calc_indice_nome(estrutura, get_nome(cliente));
        if(indice != -1) insere_na_lista(estrutura->lista_nomes, indice, nodo);
    }else if(chave == 2){
        int indice = calc_indice_bairro(estrutura, get_bairro(cliente));
        if(indice != -1) insere_na_lista(estrutura->lista_bairros, indice, nodo);
    }else if(chave == 3){
        int indice = calc_indice_pessoas(estrutura, get_pessoas(cliente));
        if(indice != -1) insere_na_lista(estrutura->lista_pessoas, indice, nodo);
    }else if(chave == 4){
        int indice = calc_indice_criancas(estrutura, get_criancas(cliente));
        if(indice != -1) insere_na_lista(estrutura->lista_criancas, indice, nodo);
    }else if(chave == 5){
        int indice = calc_indice_renda(estrutura, get_renda(cliente));
        if(indice != -1) insere_na_lista(estrutura->lista_renda, indice, nodo);
    }
}

Lista * recupera_cliente(Estrutura * estrutura, int criterio, int complemento, char * busca){
    if(estrutura == NULL) return NULL;
    if(criterio < 1 || criterio > 5) return NULL;

    if(criterio == 1 || criterio == 2){
        if(busca == NULL) return NULL;
        int indice = (criterio == 1)
            ? calc_indice_nome(estrutura, busca)
            : calc_indice_bairro(estrutura, busca);
        if(indice < 0) return NULL;

        Lista * buckets = (criterio == 1) ? estrutura->lista_nomes : estrutura->lista_bairros;
        Lista * bucket = get_lista_bucket(buckets, estrutura->t_lista, indice);
        if(bucket == NULL) return NULL;

        Lista * resultado = cria_listas(1);
        if(resultado == NULL) return NULL;

        Nodo * cursor = get_inicio(bucket);
        while(cursor != NULL){
            Cliente * cliente = get_data(cursor);
            const char * valor = (criterio == 1) ? get_nome(cliente) : get_bairro(cliente);
            if(valor != NULL && strcmp(valor, busca) == 0){
                Nodo * novo = cria_nodo(cliente);
                if(novo != NULL) insere_na_lista(resultado, 0, novo);
            }
            cursor = get_next(cursor);
        }
        return resultado;
    }

    if(criterio == 3){
        int indice = calc_indice_pessoas(estrutura, complemento);
        if(indice < 0) return NULL;
        return get_lista_bucket(estrutura->lista_pessoas, estrutura->t_lista, indice);
    }

    if(criterio == 4){
        int indice = calc_indice_criancas(estrutura, complemento);
        if(indice < 0) return NULL;
        return get_lista_bucket(estrutura->lista_criancas, estrutura->t_lista, indice);
    }

    if(criterio == 5){
        if(complemento < 1 || complemento > 4) return NULL;
        int indice = complemento % estrutura->t_lista;
        return get_lista_bucket(estrutura->lista_renda, estrutura->t_lista, indice);
    }

    return NULL;
}

void libera_estrutura(Estrutura * estrutura){
    if(estrutura == NULL) return;
    libera_listas(estrutura->lista_nomes, estrutura->t_lista);
    libera_listas(estrutura->lista_bairros, estrutura->t_lista);
    libera_listas(estrutura->lista_pessoas, estrutura->t_lista);
    libera_listas(estrutura->lista_criancas, estrutura->t_lista);
    libera_listas(estrutura->lista_renda, estrutura->t_lista);
    free(estrutura->lista_nomes);
    free(estrutura->lista_bairros);
    free(estrutura->lista_pessoas);
    free(estrutura->lista_criancas);
    free(estrutura->lista_renda);
    free(estrutura);
}
