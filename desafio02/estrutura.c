#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "lista.h"

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
    else if(renda <= 5000) faixa = 4;
    else faixa = 5;

    return faixa % estrutura->t_lista;
}

void insere_cliente(Estrutura * estrutura, int chave, Cliente * cliente){
    if(estrutura == NULL) estrutura = cria_estrutura();
    
}

void libera_estrutura(Estrutura * estrutura){
    free(estrutura);
}
