#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar(Produto *p) {
    printf("Digite o nome do produto: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    size_t tamanho = strlen(p->nome);
    if (tamanho > 0 && p->nome[tamanho - 1] == '\n') {
        p->nome[tamanho - 1] = '\0';
    }
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidade);
    printf("Digite o preço do produto: ");
    scanf("%f", &p->preco);
    clearBuffer();
}

void mostrar(const Produto *p) {
    printf("Nome: %s\nQuantidade: %d\nPreço: %.2f\n", p->nome, p->quantidade, p->preco);
}

float calculaTotal(const Produto *p) {
    return p->quantidade * p->preco;
}

int main() {
    int n;
    int i;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);
    clearBuffer();

    Produto* produtos = malloc(n * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Cadastrando o %d° produto\n", i + 1);
        cadastrar(&produtos[i]);
    }

    float total = 0;
    for (i = 0; i < n; i++) {
        printf("%d° produto\n", i + 1);
        mostrar(&produtos[i]);
        total += calculaTotal(&produtos[i]);
    }

    printf("Valor total em estoque: %.2fR$\n", total);

    free(produtos);
    
}