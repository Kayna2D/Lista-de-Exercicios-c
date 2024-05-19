#include <stdio.h>
#include <stdlib.h>

int** alocar(int linhas, int colunas) {
    int** matriz = malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    return matriz;
}

int** multiplicar(int** matriz1, int** matriz2, int linhas_matriz1, int colunas_matriz1, int colunas_matriz2) {
    int** matriz = alocar(linhas_matriz1, colunas_matriz2);

    for (int i = 0; i < linhas_matriz1; i++) {
        for (int j = 0; j < colunas_matriz2; j++) {
            matriz[i][j] = 0;
            for (int k = 0; k < colunas_matriz1; k++) {
                matriz[i][j] += matriz1[i][k] * matriz2[k][j];
            }
            }
        }

    return matriz;
}

void imprimir(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
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

    int** resultado = multiplicar(matriz1, matriz2, linhas_matriz1, colunas_matriz1, colunas_matriz2);
    printf("Matriz resultante da multiplicação:\n");    
    imprimir(resultado, linhas_matriz1, colunas_matriz2);

}