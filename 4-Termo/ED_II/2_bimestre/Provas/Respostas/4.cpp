#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
Tree *c(int info){
    Tree *n = (Tree*)malloc(sizeof(Tree));
    n->info = info;
    n->esq = n->dir = NULL;
    return n;
}
void jaInserir(Tree **t){
    Tree *n = *t;
    n = c(10);
    n->esq = c(8);
    n->dir = c(12);
    n->esq->esq = c(6);
    n->esq->dir = c(9);
    n->dir->dir = c(14);
    *t = n;
}
void ex2(Tree **tt){
    Tree *aux, *lost = NULL, *t = *tt;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, t);
    while(!isEmptyFF(f)){
        dequeueFF(&f, &aux);
        if(aux->esq)enqueueFF(&f, aux->esq);
        if(aux->dir)enqueueFF(&f, aux->dir);
        aux->dir = lost;
        if(lost)lost->esq = aux;
        lost = aux;
    }
    t = lost;
    *tt = t;
}
void imprimir(Tree *t){
    Tree *aux = t;
    while(aux){
        printf("%d -> ", aux->info);
        aux = aux->dir;
    }
    puts("");
}
int main(){
    Tree *t = NULL;
    jaInserir(&t);
    ex2(&t);
    imprimir(t); 
}