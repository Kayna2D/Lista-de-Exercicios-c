#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrar(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* inverter(int *array, int tamanho) {
    int *array_invertido = (int *)malloc(tamanho * sizeof(int));
    if (array_invertido == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        array_invertido[i] = array[tamanho - 1 - i];
    }

    return array_invertido;
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

    for (int i = 0; i < n; i++) {
        printf("Digite o %d° valor: ", i + 1);
        scanf("%d", &array[i]);
    }

    //int array[] = {1, 2, 3, 4, 5};
    //int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    mostrar(array, n);

    int *array_invertido = inverter(array, n);
    if (array_invertido != NULL) {
        printf("Array invertido: ");
        mostrar(array_invertido, n);
        free(array_invertido);
    }

    return 0;
}