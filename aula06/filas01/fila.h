typedef struct Queue_ Queue;
Queue* create(int length);
int peek(Queue *Queue, int *value);
int insert(Queue *Queue, int value);
// int remove(Queue *Queue, int *value);
int size(Queue *Queue);
int full(Queue *Queue);
void destroy(Queue *Queue);