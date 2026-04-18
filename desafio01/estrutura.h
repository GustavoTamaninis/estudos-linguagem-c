typedef struct Estrutura_ Estrutura;
typedef struct Requisicao_ Requisicao;
typedef struct Node_ Node;

Estrutura* create();
int inserir(Estrutura * estrutura, Requisicao * Requisicao);
Requisicao * remover(Estrutura * estrutura);
int get_size(Estrutura * estrutura);
void libera_estrutura(Estrutura * estrutura);
