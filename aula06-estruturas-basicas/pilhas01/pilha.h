typedef struct Stack_ Stack;

Stack* create(int length);
int peek(Stack *Stack, int *value);
int push(Stack *Stack, int value);
int pop(Stack *Stack, int *value);
int size(Stack *Stack);
int full(Stack *Stack);
void destroy(Stack *Stack);