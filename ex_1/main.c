#include <stdio.h>

int main() {
    int n;
    int i;
    printf("Digite quantos valores deseja somar: ");
    scanf("%d", &n);

    int array[n];
    
    for(i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int sum = 0;
    for(i = 0; i < n; i++) {
        sum += array[i];
    }

    printf("Soma dos valores: %d\n", sum);

    return 0;
}