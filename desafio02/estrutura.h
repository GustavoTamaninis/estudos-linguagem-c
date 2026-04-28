#include "cliente.h"
#include "lista.h"
typedef struct Estrutura_ Estrutura;
Estrutura * cria_estrutura();
int calc_indice_nome(Estrutura * estrutura, char * nome);
int calc_indice_bairro(Estrutura * estrutura, char * bairro);
int calc_indice_pessoas(Estrutura * estrutura, int pessoas);
int calc_indice_criancas(Estrutura * estrutura, int criancas);
int calc_indice_renda(Estrutura * estrutura, double renda);
void insere_cliente(Estrutura * estrutura, int chave, Cliente * cliente); //int?
Lista * recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);
void libera_estrutura(Estrutura *estrutura);