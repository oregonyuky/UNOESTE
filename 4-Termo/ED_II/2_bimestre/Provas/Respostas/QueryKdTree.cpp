#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FilaPilha.h"
#define K 2
KdTree *c(int a, int b){
    KdTree *n = (KdTree*)malloc(sizeof(KdTree*));
    n->ponto[0] = a;
    n->ponto[1] = b;
    n->esq = n->dir = NULL;
    return n;
}
void jaInserir(KdTree **r){
    KdTree *t = *r;
    t = c(2, 1);
    t->esq = c(1, 3);
    t->dir = c(4, 3);
    t->dir->esq = c(5, 1);
    t->dir->dir = c(6, 3);
    *r = t;
}
float dist(KdTree *r, int ponto[K]) {
    int i;
    int sum = 0;
    for(i = 0; i < K; i++){
        int d = r->ponto[i] - ponto[i];
        sum += d * d;
    }
    return sqrt(sum);
}
void buscaP(KdTree *r, int ponto[K], int d, int raio){
    if(r){
        char dd = ponto[d] > r->ponto[d];
        if(dd)buscaP(r->dir, ponto, (d+1)%K, raio);
        else buscaP(r->esq, ponto, (d+1)%K, raio);

        if(dist(r, ponto) <= raio)printf("(%d, %d) ", r->ponto[0], r->ponto[1]);
        int de = abs(ponto[d] - r->ponto[d]);

        if(de < raio && !dd)buscaP(r->dir, ponto, (d+1)%K, raio);
        else if(de < raio)buscaP(r->esq, ponto, (d+1)%K, raio);
    }
}
void buscaPIterativo(KdTree *r, int ponto[K], int raio){
    
}
int main() {
    KdTree *t = NULL;
    jaInserir(&t);
    int ponto[2] = {3, 2};
    buscaP(t, ponto, 0, 2);

    return 0;
}