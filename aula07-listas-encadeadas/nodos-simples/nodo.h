typedef struct Node_ Node;
Node* create_node(int info);
void set_info(Node *node, int info);
int get_info(Node *node);
void set_next(Node *node, Node *next);
Node* get_next(Node *node);
void destroy(Node *node);
