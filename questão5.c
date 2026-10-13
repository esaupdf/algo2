
#include <stdio.h>

void somarLinhas(int N, int matriz[N][N][N]) {
    int i, j, k, soma;

    for (i = 0; i < N; i++) {
        printf("Camada %d:\n", i);

        for (j = 0; j < N; j++) {
            soma = 0;

            for (k = 0; k < N; k++) {
                soma += matriz[i][j][k];
            }

            printf("Soma da linha %d: %d\n", j, soma);
        }
    }
}

void contarPositivos(int N, int matriz[N][N][N]) {
    int i, j, k, x, y, z;
    int quantidade, jaContado;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {

                if (matriz[i][j][k] > 0) {
                    jaContado = 0;

                    /* Verifica todas as posições anteriores */
                    for (x = 0; x <= i; x++) {
                        for (y = 0; y < N; y++) {
                            for (z = 0; z < N; z++) {

                                if (x == i && y == j && z >= k) {
                                    continue;
                                }

                                if (matriz[x][y][z] == matriz[i][j][k]) {
                                    jaContado = 1;
                                }
                            }
                        }
                    }

                    if (jaContado == 0) {
                        quantidade = 0;

                        for (x = 0; x < N; x++) {
                            for (y = 0; y < N; y++) {
                                for (z = 0; z < N; z++) {
                                    if (matriz[x][y][z] == matriz[i][j][k]) {
                                        quantidade++;
                                    }
                                }
                            }
                        }

                        printf("O valor %d aparece %d vezes\n",
                               matriz[i][j][k], quantidade);
                    }
                }
            }
        }
    }
}

int calcularValorAbsoluto(int N, int matriz[N][N][N]) {
    int i, j, k, soma = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                soma += matriz[i][j][k];
            }
        }
    }

    if (soma < 0) {
        soma = -soma;
    }

    return soma;
}

void filtrarValores(int N, int matriz[N][N][N], int valorAbsoluto) {
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                if (matriz[i][j][k] < valorAbsoluto) {
                    matriz[i][j][k] = 0;
                }
            }
        }
    }
}

void exibirMatriz(int N, int matriz[N][N][N]) {
    int i, j, k;

    for (i = 0; i < N; i++) {
        printf("Camada %d:\n", i);

        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }

        printf("\n");
    }
}

int main() {
    int N, i, j, k;
    int valorAbsoluto;

    scanf("%d", &N);

    int matriz[N][N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }

    somarLinhas(N, matriz);

    contarPositivos(N, matriz);

    valorAbsoluto = calcularValorAbsoluto(N, matriz);
    printf("Valor absoluto da soma: %d\n", valorAbsoluto);

    filtrarValores(N, matriz, valorAbsoluto);

    printf("Matriz final:\n");
    exibirMatriz(N, matriz);

    return 0;
}
