#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int* calcular_moda(int *array, int tamanho, int *moda_tamanho) {
    int *freq = (int *)calloc(tamanho, sizeof(int));
    int max_freq = 0;

    qsort(array, tamanho, sizeof(int), comparar);

    int cont = 1;
    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i-1]) {
            cont++;
        } else {
            cont = 1;
        }

        if (cont > max_freq) {
            max_freq = cont;
        }
    }

    int *moda = (int *)malloc(tamanho * sizeof(int));
    int j = 0;
    cont = 1;
    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i-1]) {
            cont++;
        } else {
            cont = 1;
        }

        if (cont == max_freq) {
            if (j == 0 || moda[j-1] != array[i]) {
                moda[j++] = array[i];
            }
        }
    }

    if (max_freq == 1) { 
        free(moda);
        moda = NULL;
        *moda_tamanho = 0;
    } else {
        *moda_tamanho = j;
    }

    free(freq);
    return moda;
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

    printf("Média: %.2f\n", media(array, n));
    printf("Mediana: %.2f\n", mediana(array, n));
    int moda_tamanho;
    int *moda = calcular_moda(array, n, &moda_tamanho);

    if (moda_tamanho > 0) {
        printf("Moda: ");
        for (int i = 0; i < moda_tamanho; i++) {
            printf("%d ", moda[i]);
        }
        printf("\n");
    } else {
        printf("Moda: Não existe.\n");
    }

    free(array);    
    free(moda);

    return 0;
}
