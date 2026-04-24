typedef struct contato_ tipo_contato; //renomeio "struct contato_" para "tipo_contato".

tipo_contato *get_contato();

int set_nome(tipo_contato *contato, char nome[]);

char *get_nome(tipo_contato *contato);

int set_telefone(tipo_contato *contato, char telefone[]);

char *get_telefone(tipo_contato *contato);

int *get_cartao(tipo_contato *contato);