#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double media(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (double)soma / tamanho;
}

double mediana(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar); 

    if (tamanho % 2 == 0) {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    } else {
        return array[tamanho / 2];
    }
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
    printf("Mediana: %.2f\n", mediana(array, n));
    free(array);

    
}