    #include <stdio.h>
    #include "pilha.h"

    int main(){
        struct Stack_ *s = create(4);

        int i;
        int value = 0;
        for(i = 0; i < 35; i+=5){
            if(full(s)){
                printf("A pilha já está cheia...\n");
            }else{
                value = 0;
                if(peek(s, &value) == 1){
                    printf("A pilha está vazia!\n");
                }else{
                    printf("A pilha possui %d elementos.\n", size(s));
                }

                push(s, i);
                printf("Inseri o valor %d à pilha!\n", i);
            }
        }

        pop(s, &value);
        printf("Removi o valor %d da pilha!\n", value);
        pop(s, &value);
        printf("Removi o valor %d da pilha!\n", value);

        destroy(s);
    }