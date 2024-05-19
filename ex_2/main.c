#include <stdio.h>
#include <string.h>

int vogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    size_t tamanho = strlen(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }

    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vogal(string[i])) {
            cont++;
        }
    }

    printf("Quantidade de vogais: %d\n", cont);

    return 0;
}