#include <stdio.h>
#include <ctype.h>

void maiuscula(char *string) {
    while(*string) {
        *string = toupper(*string);
        string++;
    }
}

int main() {
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    size_t tamanho = strlen(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }

    maiuscula(string);
    printf("String em maiúsculas: %s\n", string);

    return 0;
}

    