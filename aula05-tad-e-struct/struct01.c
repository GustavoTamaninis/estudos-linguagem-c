#include <stdio.h>
#include <string.h>
int main() {
    struct empregado {
        char nome[50];
        int idade;
        double cpf;
        double salario;
    };

    struct empregado e;

    strcpy(e.nome, "Maria Augusta");
    e.idade = 22;
    e.cpf = 12345678912;
    e.salario = 5000;

    printf("Nome: %s\nIdade: %d\nCPF: %.0f\nSalario: %.2f", e.nome, e.idade, e.cpf, e.salario);

    return 0;
}