//Código da aula "Lista baseada em vetores":
typedef struct List_ List;

List* create(int length);
int list_head(List *list, int *value);
int list_tail(List *list, int *value);
int list_position(List *list, int position, int *value);
int insert_head(List *list, int value);
int insert_tail(List *list, int value);
int insert_position(List *list, int position, int value);
int remove_head(List *list, int *value);
int remove_tail(List *list, int *value);
int remove_position(List *list, int position, int *value);
int size(List *list);
int full(List *list);
void destroy(List *list);