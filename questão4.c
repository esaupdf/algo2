
#include <stdio.h>

struct MelhorPassada {
    char tipo;
    int indice;
    int totalColhido;
};

struct MelhorPassada encontrarMelhorPassada(
    int L, int C, int campo[L][C]) {

    struct MelhorPassada melhor;
    int i, j, soma;

    melhor.tipo = 'L';
    melhor.indice = 0;
    melhor.totalColhido = 0;

    for (j = 0; j < C; j++) {
        melhor.totalColhido += campo[0][j];
    }

    for (i = 0; i < L; i++) {
        soma = 0;

        for (j = 0; j < C; j++) {
            soma += campo[i][j];
        }

        if (soma > melhor.totalColhido) {
            melhor.totalColhido = soma;
            melhor.indice = i;
            melhor.tipo = 'L';
        }
    }

    for (j = 0; j < C; j++) {
        soma = 0;

        for (i = 0; i < L; i++) {
            soma += campo[i][j];
        }

        if (soma > melhor.totalColhido) {
            melhor.totalColhido = soma;
            melhor.indice = j;
            melhor.tipo = 'C';
        }
    }

    return melhor;
}

int main() {
    int L, C, i, j;

    scanf("%d %d", &L, &C);

    int campo[L][C];

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    struct MelhorPassada resultado;
    resultado = encontrarMelhorPassada(L, C, campo);

    if (resultado.tipo == 'L') {
        printf("Tipo:Linha de indice %d com total colhido %d\n",
               resultado.indice, resultado.totalColhido);
    } else {
        printf("Tipo:Coluna de indice %d com total colhido %d\n",
               resultado.indice, resultado.totalColhido);
    }

    return 0;
}
