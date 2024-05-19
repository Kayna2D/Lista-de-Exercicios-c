#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 100
#define FILENAME "funcionarios.bin" 

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float salario;
} Funcionario;

void  clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criar() {
    FILE *f = fopen(FILENAME, "ab");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionario;
    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, MAX_NOME, stdin);
    size_t tamanho = strlen(funcionario.nome);
    if (tamanho > 0 && funcionario.nome[tamanho - 1] == '\n') {
        funcionario.nome[tamanho - 1] = '\0';
    }

    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionario.idade);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);
    clearBuffer();

    fwrite(&funcionario, sizeof(Funcionario), 1, f);
    fclose(f);

    printf("Funcionário adicionado com sucesso!\n");
}

void listar() {
    FILE *f = fopen(FILENAME, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, f)) {
        printf("Nome: %s\t", funcionario.nome);
        printf("Idade: %d\t", funcionario.idade);
        printf("Salário: %.2fR$\n", funcionario.salario);
    }

    fclose(f);
}

void buscar() {
    char nome[MAX_NOME];
    printf("Digite o nome do funcionário que deseja buscar: ");
    fgets(nome, MAX_NOME, stdin);
    size_t tamanho = strlen(nome);
    if (tamanho > 0 && nome[tamanho - 1] == '\n') {
        nome[tamanho - 1] = '\0';
    }

    FILE *f = fopen(FILENAME, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(Funcionario), 1, f)) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("Funcionário encontrado!\n");
            printf("Nome: %s\t", funcionario.nome);
            printf("Idade: %d\t", funcionario.idade);
            printf("Salário: %.2fR$S\n", funcionario.salario);
            printf("\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
    }

    fclose(f);
    
}

int main() {
    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar funcionário\n");
        printf("2 - Listar funcionários\n");
        printf("3 - Buscar funcionário\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                criar();
                break;
            case 2:
                listar();
                break;
            case 3:
                buscar();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
} while (opcao != 0);

    return 0;
}