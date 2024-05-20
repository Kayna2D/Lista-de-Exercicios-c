#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float salario;
} Funcionario;

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int comparar(const void *a, const void *b) {
    Funcionario *fa = (Funcionario *)a;
    Funcionario *fb = (Funcionario *)b;
    return (fa->idade - fb->idade);
}

void listar(Funcionario *funcionarios, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
}

int main() {
    int n;
    
    printf("Quantos funcionários deseja cadastrar? ");
    scanf("%d", &n);
    clearBuffer();

    Funcionario *funcionarios = (Funcionario *)malloc(n * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do %d° funcionário: ", i + 1);
        fgets(funcionarios[i].nome, MAX_NOME, stdin);
        size_t tamanho = strlen(funcionarios[i].nome);
        if (tamanho > 0 && funcionarios[i].nome[tamanho - 1] == '\n') {
            funcionarios[i].nome[tamanho - 1] = '\0';
        }

        printf("Digite a idade do %d° funcionário: ", i + 1);
        scanf("%d", &funcionarios[i].idade);

        printf("Digite o salário do %d° funcionário: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
        clearBuffer();
    }

    qsort(funcionarios, n, sizeof(Funcionario), comparar);

    printf("Funcionários em ordem de idade:\n");
    listar(funcionarios, n);

    printf("Primeiro funcionário: %s\n", funcionarios[0].nome);

    free(funcionarios);

    return 0;
}
