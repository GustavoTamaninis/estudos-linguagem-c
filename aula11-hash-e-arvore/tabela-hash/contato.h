typedef struct Contato_ Contato;
Contato * get_contato(char * nome, char * telefone);
char * get_nome(Contato * contato);
char * get_telefone(Contato * contato);