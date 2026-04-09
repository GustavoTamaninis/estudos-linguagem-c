#include <stdio.h>
#include <stdlib.h>

struct Stack_{
    int *pilha;
    int limite;
    int topo;
};

//O "Método Construtor":
struct Stack_* create(int length){
    /*
        Função que cria uma pilha vazia, devolvendo um ponteiro que aponta para ela
        como retorno. Essa função recebe como parâmetro o tamanho da pilha a criar.
        Se a função apresentar erro, o ponteiro devolvido será NULL.
    */
    if(length < 0) return NULL;

    struct Stack_ *s = (struct Stack_*) malloc(sizeof(struct Stack_)); //crio um ponteiro *s que vai apontar para o tipo de dado "struct Stack_", que terá um espaço reservado de uma "struct Stack_" e será convertido para um "struct Stack_".
    if(s == NULL) return NULL;

    s->pilha = (int*) malloc(length * sizeof(int));
    if(s->pilha == NULL){
        free(s);
        return NULL;
    }

    s->limite = length;
    s->topo = -1; //A lista começa vazia.

    return s;
}

int peek(struct Stack_ *Stack, int *value){
    /*
        A função peek consulta o elemento que está no topo da pilha, sem retirá-
        lo. Não há retorno do valor do topo, mas o ponteiro value, passado como
        parâmetro, recebe, dentro da função, esse valor do topo. Ele não pode ser o
        retorno no tipo simples int da função, porque, neste caso, o retorno será usado
        para identificar se houve erro na execução da função. Por exemplo, como se
        sabe que a pilha está vazia sem um retorno de erro? Se o retorno for diferente de
        zero, é porque houve erro na execução da função.
    */
    if(Stack == NULL || Stack->topo == -1) return 1; //pilha tá vazia ou deu erro.

    if(value != NULL) *value = Stack->pilha[Stack->topo]; //altero o valor de value, lá no meu main() para o valor do topo.

    return 0; //sucesso.
}

int full(struct Stack_ *Stack){
    /* 
        A função full é necessária para se saber se a pilha está cheia, pois como
        estamos usando um vetor como base para a pilha, há, por isso, um número de
        elementos máximo. É responsabilidade do tipo abstrato de dados (este arquivo)
        controlar se a pilha está cheia com base em seu tamanho definido na criação.
    */
    if(Stack == NULL) return -1;

    return (Stack->topo == Stack->limite-1);
}

int push(struct Stack_ *Stack, int value){
    /*
        A função push insere o valor passado pelo parâmetro value na pilha.
        Se o retorno da função for zero, a inserção foi realizada com sucesso.
    */
    if(Stack == NULL || full(Stack)) return 1;
    Stack->topo++;
    Stack->pilha[Stack->topo] = value;

    return 0;
}

int pop(struct Stack_ *Stack, int *value ){
    /* 
        A função pop remove o valor do topo da pilha e o armazena no ponteiro
        passado por parâmetro value. Se o retorno da função for zero, a remoção foi
        realizada com sucesso.
    */
    if(Stack == NULL) return -1;

    if(value != NULL){
        *value = Stack->pilha[Stack->topo];
    }
    Stack->topo--;

    return 0;
}

int size(struct Stack_ *Stack){
    /*
        A função size é usada para saber a quantidade de elementos na pilha. Não
        há como saber a quantidade de elementos em um vetor, a não ser que seja
        controlado durante a entrada e a saída de dados. Por isso, a necessidade dessa
        função.
    */
    if(Stack == NULL) return -1; //uso menos um pra deixar claro que é um erro e não que a pilha possui 1 elemento.
    return Stack->topo+1;
}

void destroy(struct Stack_ *Stack){
    /*
        A função destroy é necessária, porque a lista é obtida pela função create,
        que faz a alocação de espaço para a lista. Este espaço não foi alocado pelo
        compilador e, por isso, precisa ser explicitamente liberado. Quem tem acesso à
        lista é o tipo abstrato de dados. Por isso, precisamos de sua função destroy para
        poder liberar o espaço alocado por create.
    */
    if(Stack != NULL){
        free(Stack->pilha);
        free(Stack);
    }
}
