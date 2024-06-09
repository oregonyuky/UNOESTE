#include <stdio.h>
#define LINHAS 5
#define COLUNAS 7
int main() {
    int matriz[LINHAS][COLUNAS] = {
        {1, 2, 3, 4, 5, 6, 7},
        {2, 3, 4, 5, 6, 7, 8},
        {13, 14, 15, 10, 15, 14, 13},
        {4, 5, 6, 7, 8, 9, 10},
        {5, 6, 7, 8, 9, 10, 11}
    };
    int i, j, k;
    int ponto_de_sela_encontrado = 0;
    printf("A matriz fornecida é:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nPontos de sela:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            int elemento = matriz[i][j];
            int menor_na_linha = 1;
            int maior_na_coluna = 1;
            for (k = 0; k < COLUNAS; k++) {
                if (matriz[i][k] < elemento) {
                    menor_na_linha = 0;
                    break;
                }
            }
            for (k = 0; k < LINHAS; k++) {
                if (matriz[k][j] > elemento) {
                    maior_na_coluna = 0;
                    break;
                }
            }
            if (menor_na_linha && maior_na_coluna) {
                printf("Ponto de sela encontrado em (%d, %d): %d\n", i, j, elemento);
                ponto_de_sela_encontrado = 1;
            }
        }
    }
    if (!ponto_de_sela_encontrado) {
        printf("Nenhum ponto de sela encontrado na matriz.\n");
    }
    return 0;
}

