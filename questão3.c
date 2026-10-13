
#include <stdio.h>

void preencherDicas(int L, int C, int matriz[L][C]) {
    int i, j, x, y, cont;
    int aux[L][C];

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            aux[i][j] = matriz[i][j];
        }
    }

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            if (aux[i][j] == 0) {
                cont = 0;

                for (x = i - 1; x <= i + 1; x++) {
                    for (y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < L &&
                            y >= 0 && y < C) {
                            if (aux[x][y] == -1) {
                                cont++;
                            }
                        }
                    }
                }

                matriz[i][j] = cont;
            }
        }
    }
}

int main() {
    int L, C, i, j;

    scanf("%d %d", &L, &C);

    int matriz[L][C];

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    preencherDicas(L, C, matriz);

    printf("Matriz preenchida:\n");

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
