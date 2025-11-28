#include <stdio.h>
#include <stdlib.h>
#include "pilhaP.h"
#include <math.h>
#define TF 6
#define K 2
KdTree *CriaNo(int ponto[K]){
    int i;
    KdTree *no = (KdTree*)malloc(sizeof(KdTree));
    for(i=0;i<K;i++)no->ponto[i] = ponto[i];
    no->esq = no->dir = NULL;
    return no;
}
void ordena(int pontos[TF][K], int ini, int fim, int d){
    int i, j;
    for(i = ini + 1; i <= fim; i++){
        int pontoAtual[K];
        for(j = 0; j < K; j++) {
            pontoAtual[j] = pontos[i][j];
        }
        j = i - 1;
        while(j >= ini && pontos[j][d] > pontoAtual[d]) {
            for(int k = 0; k < K; k++) {
                pontos[j + 1][k] = pontos[j][k];
            }
            j--;
        }
        for(int k = 0; k < K; k++) {
            pontos[j + 1][k] = pontoAtual[k];
        }
    }
}

void insereBalanceado(KdTree **raiz, int ini, int fim, int pontos[TF][K], int n){
    int d, meio;
    if (ini <= fim){
        d = n % K;
        ordena(pontos, ini, fim, d);
        meio = (ini + fim) / 2;
        printf("Meio: %d - ", meio);
        for (int i = ini; i <= fim; i++)printf("(%d, %d) ", pontos[i][0], pontos[i][1]);
        puts("");
        *raiz = CriaNo(pontos[meio]);
        insereBalanceado(&(*raiz)->esq, ini, meio - 1, pontos, n + 1);
        insereBalanceado(&(*raiz)->dir, meio + 1, fim, pontos, n + 1);
    }
}

void insereBalaceadoIterativoC(KdTree **raiz, int pontos[TF][K]){
    Pilha *p1, *p2, *p3;
    PilhaP *pK;
    init(&p1); init(&p2); init(&p3); initP(&pK);
    pushP(&pK, *raiz);  
    push(&p1, 0);        
    push(&p2, TF-1);  
    push(&p3, 0);       
    
    int ini = 0, fim = TF - 1, n = 0;
    KdTree *k = NULL;

    while (!isEmpty(p1)){  
        pop(&p1, &ini);
        pop(&p2, &fim);
        pop(&p3, &n);
        popP(&pK, &k);
        if (ini <= fim){
            int d = n % K;  
            ordena(pontos, ini, fim, d);
            printf("Intervalo [%d, %d]: ", ini, fim);
            int meio = (ini + fim) / 2; 
            printf("M: %d - ", meio);
            for (int i = ini; i <= fim; i++) {
                printf("(%d, %d) ", pontos[i][0], pontos[i][1]);
            }
            puts("");  
            k = CriaNo(pontos[meio]);
            if (fim > meio) {
                push(&p1, meio + 1);
                push(&p2, fim);
                push(&p3, n + 1);
                pushP(&pK, k->dir);
            }
            if (ini < meio) {
                push(&p1, ini);
                push(&p2, meio - 1);
                push(&p3, n + 1);
                pushP(&pK, k->esq);
            }
        }
    }
}


float distancia(int pontoA[K], int pontoB[K]){
    float dist=0;
    for(int i=0;i<K;i++)dist += pow(pontoA[i] - pontoB[i], 2);
    return sqrt(dist);
}
void buscaPontos(KdTree *raiz, int ponto[K], int raio){
    if(raiz){
        if(distancia(raiz->ponto, ponto) <= raio)
            printf("(%d, %d)\n", raiz->ponto[0], raiz->ponto[1]);
        buscaPontos(raiz->esq, ponto, raio);
        buscaPontos(raiz->dir, ponto, raio);
    }
}
void imprimir(KdTree *raiz){
    Fila *f;
    KdTree *aux;
    initF(&f);
    enqueue(&f, raiz);
    while(!isEmptyF(f)){
        dequeue(&f, &aux);
        printf("(%d, %d) ", aux->ponto[0], aux->ponto[1]);
        if(aux->esq)enqueue(&f, aux->esq);
        if(aux->dir)enqueue(&f, aux->dir);
    }
}
int main(){
    KdTree *raiz = NULL; 
    int pontos[TF][K] = {{30, 40}, {5, 25}, {10, 12}, {70,70}, {50,30}, {35, 45}}; 
    puts("Insere Balanceando recursivo: ");
    insereBalanceado(&raiz, 0, TF-1, pontos, 0);
    //int pBusca[K] = {32, 42};
    //buscaPontos(raiz, pBusca, 15);

    puts("\nInsere Balanceando iterativo: ");
    int pontosB[TF][K] = {{30, 40}, {5, 25}, {10, 12}, {70,70}, {50,30}, {35, 45}}; 
    insereBalaceadoIterativoC(&raiz, pontosB);
    puts("\nGrafico percorrendo pelo nivel: ");
    imprimir(raiz);
}
