typedef struct Queue_ Queue;
Queue* create(int length);
int peek(Queue *Queue, int *value);
int insert(Queue *Queue, int value);
int remover(Queue *Queue, int *value); //deixei em português, pois "remove()" já é uma função da biblioteca <stdio.h>
int size(Queue *Queue);
int full(Queue *Queue);
void destroy(Queue *Queue);