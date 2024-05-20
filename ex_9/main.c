#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double media(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (double)soma / tamanho;
}

int main() {
    int n;

    printf("Quantos valores deseja inserir no array? ");
    scanf("%d", &n);
    clearBuffer();

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Insira os %d valores do array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d° valor: ", i + 1);
        scanf("%d", &array[i]);
        clearBuffer();
    }

    printf("Media: %.2f\n", media(array, n));
    free(array);

    
}