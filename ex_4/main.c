#include <stdio.h>
#include <stdlib.h>

int** alocar(int linhas, int colunas) {
    int** matriz = malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    return matriz;
}

int main() {
    int linhas_matriz1, colunas_matriz1, linhas_matriz2, colunas_matriz2;

    printf("Digite o número de linhas da primeira matriz: ");
    scanf("%d", &linhas_matriz1);
    printf("Digite o número de colunas da primeira matriz: ");
    scanf("%d", &colunas_matriz1);

    printf("Digite o número de linhas da segunda matriz: ");
    scanf("%d", &linhas_matriz2);
    printf("Digite o número de colunas da segunda matriz: ");
    scanf("%d", &colunas_matriz2);

    if (colunas_matriz1 != linhas_matriz2) {
        printf("As matrizes não podem ser multiplicadas.\n");
        return 1;
    }

    int** matriz1 = alocar(linhas_matriz1, colunas_matriz1);
    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < linhas_matriz1; i++) {
        for (int j = 0; j < colunas_matriz1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    int** matriz2 = alocar(linhas_matriz2, colunas_matriz2);
    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < linhas_matriz2; i++) {
        for (int j = 0; j < colunas_matriz2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // printar matrizes
    printf("Matriz 1:\n");
    for (int i = 0; i < linhas_matriz1; i++) {
        for (int j = 0; j < colunas_matriz1; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("Matriz 2:\n");
    for (int i = 0; i < linhas_matriz2; i++) {
        for (int j = 0; j < colunas_matriz2; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

}