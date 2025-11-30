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
void jaInserir2(Tree **t){
    Tree *n = *t;
    n = c(10);
    n->esq = c(8);
    n->dir = c(12);
    n->esq->esq = c(6);
    n->esq->dir = c(9);
    n->dir->dir = c(14);
    *t = n;
}
void ex1(Tree **tt){
    Tree *aux, *lost = NULL, *t = *tt;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, t);
    while(!isEmptyFF(f)){
        dequeueFF(&f, &aux);
        if(aux->esq)enqueueFF(&f, aux->esq);
        if(aux->dir)enqueueFF(&f, aux->dir);
        aux->esq = lost;
        if(lost)lost->dir = aux;
        lost = aux;
    }
    *tt = t;
}
void ex2(Tree *t){
    Tree *atual;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, t);
    char e=0, flag=1;
    while(!isEmptyFF(f) && flag){
        dequeueFF(&f, &atual);
        if(atual->esq && atual->dir){
            if(e)flag = 0;
            enqueueFF(&f, atual->esq);
            enqueueFF(&f, atual->dir);
        }
        else if((atual->esq && !atual->dir) || (!atual->esq && atual->dir))
            flag = 0;
        else 
            e = 1;
    }
    if(flag)puts("Eh perfeitamente balanceado");
    else puts("Nao esta balanceado");
}
void imprimir(Tree *t){
    Tree *aux = t;
    while(aux){
        printf("%d -> ", aux->info);
        aux = aux->dir;
    }
    puts("NULL");
}
int main(){
    Tree *t = NULL;
    jaInserir2(&t);
    ex2(t);
    //imprimir(t); 
}