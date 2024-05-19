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
    
}