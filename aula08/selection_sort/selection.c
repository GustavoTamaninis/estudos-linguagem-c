#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    printf("Selection Sort em Vetor:\n");
    int vetor[5] = {5, 1, 4, 8, 2};

    for(int i = 0; i < 5; i++) printf("Na posição %d está o valor %d\n", i, vetor[i]);
    printf("\n");

    for(int i = 0; i < 5; i++){
        int menor = vetor[i];
        int im = i; //índice do menor.
        for(int j = i + 1; j < 5; j++){
            if(vetor[j] < menor){
                menor = vetor[j];
                im = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = menor;
        vetor[im] = temp;

        for(int k = 0; k < 5; k++) printf("Na posição %d está o valor %d\n", k, vetor[k]);
        printf("\n");
    }
    printf("\n");


    printf("Selection Sort Decrescente em Vetor:\n");
    int vetor_dec[5] = {5, 1, 4, 8, 2};

    for(int i = 0; i < 5; i++) printf("Na posição %d está o valor %d\n", i, vetor_dec[i]);
    printf("\n");

    for(int i = 0; i < 5; i++){
        
        int maior = vetor_dec[i];
        int im = i; //índice do maior.
        for(int j = i + 1; j < 5; j++){
            if(vetor_dec[j] > maior){
                maior = vetor_dec[j];
                im = j;
            }
        }
        int temp = vetor_dec[i];
        vetor_dec[i] = maior;
        vetor_dec[im] = temp;

        for(int k = 0; k < 5; k++) printf("Na posição %d está o valor %d\n", k, vetor_dec[k]);
        printf("\n");
    }
    printf("\n");

    
    printf("Selection Sort em Lista Encadeada:\n");
    struct Node{
        int info;
        struct Node *next;
    };
    typedef struct Node Node;

    Node n1 = {50, NULL};
    Node n2 = {10, NULL};
    Node n3 = {40, NULL};
    Node n4 = {80, NULL};
    Node n5 = {20, NULL};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Node * inicio = &n1;

    printf("Lista encadeada criada:\n");
    for(Node * atual = inicio; atual != NULL; atual = atual->next){
        printf("%d\n", atual->info);
    }

    Node * cursor = inicio;
    for(int i = 0; i < 5; i++){
        int menor = cursor->info;
        int im = i;
        for(int j = i + 1; j < 5; j++){
            int temp = cursor->info;
            cursor->info = cursor->next->info;
            cursor->next->info = temp;
            if(cursor->info < menor){
                menor = cursor->info;
                im = j;
            }
        }
        // for(int j; j <= im; j++){
        //     cursor->info = cursor->next->info;
        //     cursor->next->info = temp;
        //     if(i = j)
        // }

        for(int k = 0; k < 5; k++) printf("Na posição %d está o valor %d\n", k, cursor->info);
        printf("\n");
    }
    printf("\n");


    // printf("Selection Sort decrescente em Lista Encadeada:\n");
    // Node n1_dec = {50, NULL};
    // Node n2_dec = {10, NULL};
    // Node n3_dec = {40, NULL};
    // Node n4_dec = {80, NULL};
    // Node n5_dec = {20, NULL};

    // n1_dec.next = &n2_dec;
    // n2_dec.next = &n3_dec;
    // n3_dec.next = &n4_dec;
    // n4_dec.next = &n5_dec;

    // Node *inicio_dec = &n1_dec;

    // printf("Lista encadeada criada:\n");
    // for(Node *atual = inicio_dec; atual != NULL; atual = atual->next){
    //     printf("%d\n", atual->info);
    // }

    // while(true){
    //     bool trocou = false;
    //     Node * cursor = inicio_dec;
    //     for(int i = 0; i < 5; i++){
    //         if(i != 4 && cursor->info < cursor->next->info){
    //             int temp = cursor->info;
    //             cursor->info = cursor->next->info;
    //             cursor->next->info = temp;
    //             trocou = true;
    //         }
    //         printf("Na posição %d está o valor %d\n", i, cursor->info);
    //         if(i != 4) cursor = cursor->next;
    //     }
    //     printf("\n");
    //     if(trocou == false) break;
    // }


    return 0;
}