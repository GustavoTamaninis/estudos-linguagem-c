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

    
    printf("Selection Sort em Lista Encadeada\n");
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
        Node * menor = cursor;
        Node * cursor_2 = cursor->next;
        for(int j = i + 1; j < 5; j++){
            if(cursor_2->info < menor->info){
                menor = cursor_2;
            }
            cursor_2 = cursor_2->next;
        }
        int temp = cursor->info;
        cursor->info = menor->info;
        menor->info = temp;

        Node * cursor_3 = inicio;
        for(int j = 0; j < 5; j++){
            printf("Na posição %d está o valor %d\n", j, cursor_3->info);
            if(j != 4) cursor_3 = cursor_3->next;
        }
        if(i != 4) cursor = cursor->next;
        printf("\n");
    }
    printf("\n");


    printf("Selection Sort decrescente em Lista Encadeada:\n");
    Node n1_dec = {50, NULL};
    Node n2_dec = {10, NULL};
    Node n3_dec = {40, NULL};
    Node n4_dec = {80, NULL};
    Node n5_dec = {20, NULL};

    n1_dec.next = &n2_dec;
    n2_dec.next = &n3_dec;
    n3_dec.next = &n4_dec;
    n4_dec.next = &n5_dec;

    Node *inicio_dec = &n1_dec;

    printf("Lista encadeada decrescente criada:\n");
    for(Node * atual = inicio; atual != NULL; atual = atual->next){
        printf("%d\n", atual->info);
    }

    Node * cursor_dec = inicio;
    for(int i = 0; i < 5; i++){
        Node * maior = cursor_dec;
        Node * cursor_dec_2 = cursor_dec->next;
        for(int j = i + 1; j < 5; j++){
            if(cursor_dec_2->info > maior->info){
                maior = cursor_dec_2;
            }
            cursor_dec_2 = cursor_dec_2->next;
        }
        int temp = cursor_dec->info;
        cursor_dec->info = maior->info;
        maior->info = temp;

        Node * cursor_dec_3 = inicio;
        for(int j = 0; j < 5; j++){
            printf("Na posição %d está o valor %d\n", j, cursor_dec_3->info);
            if(j != 4) cursor_dec_3 = cursor_dec_3->next;
        }
        if(i != 4) cursor_dec = cursor_dec->next;
        printf("\n");
    }
    printf("\n");


    return 0;
}