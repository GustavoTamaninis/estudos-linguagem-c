typedef struct Requisicao_ Requisicao;

Requisicao* cria_requisicao(char * nome, int inscricao, char * procedimento);
char* get_nome(Requisicao * requisicao);
int get_inscricao(Requisicao * requisicao);
char* get_procedimento(Requisicao * requisicao);
void libera(Requisicao * requisicao);
