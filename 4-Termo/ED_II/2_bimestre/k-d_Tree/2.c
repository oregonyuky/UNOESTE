#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TF 6
#define K 2
typedef struct kdtree{
    int ponto[K];
    struct kdtree *esq, *dir;
} KdTree;
KdTree *CriaNo(int ponto[K]){
    int i;
    KdTree *no = (KdTree*)malloc(sizeof(KdTree));
    for(i=0;i<K;i++)no->ponto[i] = ponto[i];
    no->esq = no->dir = NULL;
    return no;
}
void ordena(int pontos[TF][K], int ini, int fim, int d){
    int i, j;
    while(fim>ini){
        for(i=ini;i<fim;i++)
            if(pontos[i][d] > pontos[i+1][d]){
                for(j=0;j<K;j++){
                    int aux = pontos[i][j];
                    pontos[i][j]= pontos[i+1][j];
                    pontos[i+1][j] = aux;
                }
            }
        fim--;
    }
}
void insereBalanceado(KdTree **raiz, int ini, int fim, int pontos[TF][K], int n){
    int d, meio;
        if (ini <= fim)
        {
            d = n % K;
            ordena(pontos, ini, fim, d);
            for (int i = 0; i < TF; i++)
                printf("(%d, %d) ", pontos[i][0], pontos[i][1]);
            puts("");
            meio = (ini + fim) / 2;
            printf("Meio: %d\n", meio);
            *raiz = CriaNo(pontos[meio]);
            insereBalanceado(&(*raiz)->esq, ini, meio - 1, pontos, n + 1);
            insereBalanceado(&(*raiz)->dir, meio + 1, fim, pontos, n + 1);
        }
}
float distancia(int pontoA[K], int pontoB[K]){
    int i;
    float dist=0;
    for(int i=0;i<K;i++)dist += pow(pontoA[i] - pontoB[i], 2);
    return sqrt(dist);
}
void buscaPontos(KdTree *raiz, int ponto[K], int raio){
    if(!raiz){
        if(distancia(raiz->ponto, ponto) <= raio)
            printf("(%d, %d)\n", raiz->ponto[0], raiz->ponto[1]);
        buscaPontos(raiz->esq, ponto, raio);
        buscaPontos(raiz->dir, ponto, raio);
    }
}
int main(){
    KdTree *raiz = NULL; 
    int pontos[TF][K] = {{30, 40}, {5, 25}, {10, 42}, {70,70}, {50,30}, {35, 45}}; 
    insereBalanceado(&raiz, 0, TF-1, pontos, 0);
    int pBusca[K] = {32, 42};
    buscaPontos(raiz, pBusca, 15);
    //ordena(pontos, 0, TF-1, 0);
    int i;
    for(i=0;i<TF;i++)
        printf("(%d, %d) ", pontos[i][0], pontos[i][1]);
}
