#include <stdio.h>
#include <stdlib.h>
#define k 2 
typedef struct kdTree {
    int ponto[k];
    struct kdTree *esq, *dir;
} kdTree;
kdTree* Cria_no(int ponto[k]) {
    kdTree *novo = (kdTree*) malloc(sizeof(kdTree));
    for (int i = 0; i < k; i++)
        novo->ponto[i] = ponto[i];
    novo->esq = novo->dir = NULL;
    return novo;
}
void insereR(kdTree **raiz, int ponto[k], int n) {
    int d;
    if (!*raiz)
        *raiz = Cria_no(ponto);
    else {
        d = n % k;
        if (ponto[d] < (*raiz)->ponto[d])
            insereR(&(*raiz)->esq, ponto, n + 1);
        else
            insereR(&(*raiz)->dir, ponto, n + 1);
    }
}
void imprime(kdTree *raiz) {
    if (raiz) {
        imprime(raiz->esq);
        printf("(%d, %d)\n", raiz->ponto[0], raiz->ponto[1]);
        imprime(raiz->dir);
    }
}
int main() {
    kdTree *raiz = NULL;
    int pontos[][k] = {
        {3, 6},
        {17, 15},
        {13, 15},
        {6, 12},
        {9, 1},
        {2, 7},
        {10, 19}
    };
    int n = sizeof(pontos) / sizeof(pontos[0]);
    for (int i = 0; i < n; i++) 
        insereR(&raiz, pontos[i], 0);
    printf("Pontos inseridos na kd-tree (ordem simétrica):\n");
    imprime(raiz);

    return 0;
}
