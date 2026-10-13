
#include <stdio.h>
#include <string.h>

void substituir(char frase[], char alvo[], char nova[], char resultado[]) {
    int i = 0, j = 0;
    int tam = strlen(alvo);

    while (frase[i] != '\0') {
        if (strncmp(&frase[i], alvo, tam) == 0 &&
            (i == 0 || frase[i - 1] == ' ') &&
            (frase[i + tam] == ' ' || frase[i + tam] == '\0')) {
            strcpy(&resultado[j], nova);
            j += strlen(nova);
            i += tam;
        } else {
            resultado[j++] = frase[i++];
        }
    }

    resultado[j] = '\0';
}

int main() {
    char frase[500], alvo[100], nova[100], resultado[1000];

    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    fgets(nova, sizeof(nova), stdin);
    nova[strcspn(nova, "\n")] = '\0';

    substituir(frase, alvo, nova, resultado);

    printf("%s\n", resultado);

    return 0;
}
