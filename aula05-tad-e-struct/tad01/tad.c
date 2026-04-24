//O arquivo com o TAD contém a definição da estrutura de dados que será
//usada e todas as funções que sabem manipular este tipo de estrutura.
//Resumindo, é parecido com classes e objetos...

//Por alguma razão, o tamanho da estrutura é desconhecido para o compilador.
//Por isso não se pode fazer declaração de variáveis simples e nem se
//esquecer de fazer a função get_empregado, pois depois eu não conseguiria
//fazer o malloc. Por essa razão, o TAD tem que devolver um espaço já alocado
//para quem for usá-lo
#include <string.h>
#include <stdlib.h>
#define TAMANHONOME 50

struct empregado {
    char nome[TAMANHONOME];
    double cpf;
    double salario;
};

struct empregado* get_empregado() { //retorna um ponteiro que persiste mesmo depois do fim da execução da função.
    return (struct empregado *) malloc(sizeof(struct empregado)); //aviso ao compilador: "trate como um empregado e lhe reserve um espaço de empregado."
}

void set_nome(struct empregado *e, char *nome) {
    int tamanho = strlen(nome);
    strcpy(e->nome, nome);
    if(tamanho > TAMANHONOME) {
        nome[TAMANHONOME - 1] = '\0';
    }
}

char* get_nome(struct empregado *e) {
    return e->nome;
}

void set_cpf(struct empregado *e, double cpf) {
    e->cpf = cpf;
}

double get_cpf(struct empregado *e) {
    return e->cpf;
}

void set_salario(struct empregado *e, double salario) {
    e->salario = salario;
}

double get_salario(struct empregado *e) {
    return e->salario;
}