
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Estudante {
    char ultimo[50];
    char primeiro[50];
    float rendimento;
};

struct Funcionario {
    char ultimo[50];
    char primeiro[50];
    float salario;
};

struct Estudante estudantes[MAX];
struct Funcionario funcionarios[MAX];

int ne = 0, nf = 0;

void cadastrarEstudante() {
    struct Estudante e;
    int i;

    if (ne >= MAX) {
        printf("Limite de estudantes atingido!\n");
        return;
    }

    printf("Primeiro nome: ");
    scanf("%49s", e.primeiro);

    printf("Ultimo nome: ");
    scanf("%49s", e.ultimo);

    for (i = 0; i < ne; i++) {
        if (strcmp(e.primeiro, estudantes[i].primeiro) == 0 &&
            strcmp(e.ultimo, estudantes[i].ultimo) == 0) {
            printf("Estudante ja cadastrado!\n");
            return;
        }
    }

    printf("Rendimento: ");
    scanf("%f", &e.rendimento);

    estudantes[ne] = e;
    ne++;
}

void cadastrarFuncionario() {
    struct Funcionario f;
    int i;

    if (nf >= MAX) {
        printf("Limite de funcionarios atingido!\n");
        return;
    }

    printf("Primeiro nome: ");
    scanf("%49s", f.primeiro);

    printf("Ultimo nome: ");
    scanf("%49s", f.ultimo);

    for (i = 0; i < nf; i++) {
        if (strcmp(f.primeiro, funcionarios[i].primeiro) == 0 &&
            strcmp(f.ultimo, funcionarios[i].ultimo) == 0) {
            printf("Funcionario ja cadastrado!\n");
            return;
        }
    }

    printf("Salario: ");
    scanf("%f", &f.salario);

    funcionarios[nf] = f;
    nf++;
}

void mostrarEstudantes() {
    int i;

    for (i = 0; i < ne; i++) {
        printf("%s %s - Rendimento: %.2f\n",
               estudantes[i].primeiro,
               estudantes[i].ultimo,
               estudantes[i].rendimento);
    }
}

void mostrarFuncionarios() {
    int i;

    for (i = 0; i < nf; i++) {
        printf("%s %s - Salario: %.2f\n",
               funcionarios[i].primeiro,
               funcionarios[i].ultimo,
               funcionarios[i].salario);
    }
}

void mostrarEstudante() {
    char primeiro[50], ultimo[50];
    int i;

    printf("Primeiro nome: ");
    scanf("%49s", primeiro);

    printf("Ultimo nome: ");
    scanf("%49s", ultimo);

    for (i = 0; i < ne; i++) {
        if (strcmp(primeiro, estudantes[i].primeiro) == 0 &&
            strcmp(ultimo, estudantes[i].ultimo) == 0) {
            printf("%s %s - Rendimento: %.2f\n",
                   estudantes[i].primeiro,
                   estudantes[i].ultimo,
                   estudantes[i].rendimento);
            return;
        }
    }

    printf("Estudante nao encontrado!\n");
}

void mostrarFuncionario() {
    char primeiro[50], ultimo[50];
    int i;

    printf("Primeiro nome: ");
    scanf("%49s", primeiro);

    printf("Ultimo nome: ");
    scanf("%49s", ultimo);

    for (i = 0; i < nf; i++) {
        if (strcmp(primeiro, funcionarios[i].primeiro) == 0 &&
            strcmp(ultimo, funcionarios[i].ultimo) == 0) {
            printf("%s %s - Salario: %.2f\n",
                   funcionarios[i].primeiro,
                   funcionarios[i].ultimo,
                   funcionarios[i].salario);
            return;
        }
    }

    printf("Funcionario nao encontrado!\n");
}

int main() {
    int opcao;

    do {
        printf("\n1 - Cadastrar Estudante\n");
        printf("2 - Cadastrar Funcionario\n");
        printf("3 - Mostrar todos Estudantes\n");
        printf("4 - Mostrar todos Funcionarios\n");
        printf("5 - Mostrar dados de um Estudante\n");
        printf("6 - Mostrar dados de um Funcionario\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEstudante();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                mostrarEstudantes();
                break;
            case 4:
                mostrarFuncionarios();
                break;
            case 5:
                mostrarEstudante();
                break;
            case 6:
                mostrarFuncionario();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
