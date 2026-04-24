//Este código não possui um main() porque não é um código para ser executado
//ao invés disso, é uma biblioteca.
//Quem for utilizar esta biblioteca, não saberá nem o nome da estrutura e nem
//as funções que são capazes de manipulá-la. Para isso, é necessário o arquivo
//de cabeçalho ou header (tad_contato.h).
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contato_{
    char nome[50];
    char telefone[12];
};

//Método construtor que realoca o espaço necessário para a string:
struct contato_ *get_contato(){
    struct contato_ *c = (struct contato_ *) calloc(1, sizeof(struct contato_)); //cria um ponteiro *c que será tratado pelo compilador como um struct contato_. Esse ponteiro terá um espaço reservado na memória equivalente à struct contato_. E, por ser inicializado com calloc, seus valores são branco.
    return c;
};

int set_nome(struct contato_ *contato, char nome[]){
    int i;
    for(i = 0; i < 49 && i < strlen(nome); i++){
        contato->nome[i] = nome[i];
    }
    contato->nome[i] = '\0';
    if(strlen(nome) > 49) return 1;
    return 0;
}

char *get_nome(struct contato_ *contato){
    return contato->nome;
}

int set_telefone(struct contato_ * contato, char telefone[]){
    if(strlen(telefone) > 11) return 2;
    int i;
    for(i = 0; i < strlen(telefone); i++){
        contato->telefone[i] = telefone[i];
    }
    contato->telefone[i] = '\0';
    return 0;
}

char *get_telefone(struct contato_ * contato){
    return contato->telefone;
}

char *get_cartao(struct contato_ *contato){
    char *retorno = (char *) malloc(sizeof(char) * 100);

    sprintf(retorno, "Nome: :%s \nTelefone: %s  \n", contato->nome, contato->telefone);

    return retorno;
}

