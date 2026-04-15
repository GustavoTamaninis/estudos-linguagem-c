typedef struct DNode_ DNode;
DNode* create_dnode(int info);
void set_info(DNode *dnode, int info);
int get_info(DNode *dnode);
void set_next(DNode *dnode, DNode *proximo);
DNode* get_next(DNode *dnode);
void set_previous(DNode *dnode, DNode *anterior);
DNode* get_previous(DNode *dnode);
void destroy(DNode *dnode);