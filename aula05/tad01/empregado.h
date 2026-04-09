//define um struct e apresenta as assinaturas as assinaturas das funções.
//é parecido com interfaces...? Ou era classes abstratas?
struct empregado;
struct empregado* get_empregado();
void set_nome(struct empregado *e, char *c);
char* get_nome(struct empregado *e);
void set_cpf(struct empregado *e, double cpf);
double get_cpf(struct empregado *e);
void set_salario(struct empregado *e, double salario);
double get_salario(struct empregado *e);