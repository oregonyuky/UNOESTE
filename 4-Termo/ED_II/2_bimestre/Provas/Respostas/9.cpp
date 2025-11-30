#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
typedef struct Reg{
    int esq, info, dir;
} Reg;
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
int tamanhoFila(FILA *f){
    int cont = 0;
    FILA *aux = f;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}
int altura(Tree *r){
    if(r == NULL) return 0;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, r);
    int altura = 0;
    while(!isEmptyFF(f)){
        int nivel = tamanhoFila(f); // precisamos contar quantos nós existem neste nível
        for(int i=0; i<nivel; i++){
            Tree *aux;
            dequeueFF(&f, &aux);
            if(aux->esq) enqueueFF(&f, aux->esq);
            if(aux->dir) enqueueFF(&f, aux->dir);
        }
        altura++;
    }
    return altura;
}
int ehAVL(Tree *raiz){
    if(raiz == NULL) return 1;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, raiz);
    while(!isEmptyFF(f)){
        Tree *n;
        dequeueFF(&f, &n);
        int h_esq = altura(n->esq);
        int h_dir = altura(n->dir);
        int fb = h_esq - h_dir;
        printf("%d ", altura(n));
        if(abs(fb) > 1)
            return 0;
        if(n->esq) enqueueFF(&f, n->esq);
        if(n->dir) enqueueFF(&f, n->dir);
    }
    return 1;
}
void destruirArvore(Tree *r){
    if(r == NULL) return;
    FILA *f;
    initFF(&f);
    enqueueFF(&f, r);
    while(!isEmptyFF(f)){
        Tree *aux;
        dequeueFF(&f, &aux);
        if(aux->esq) enqueueFF(&f, aux->esq);
        if(aux->dir) enqueueFF(&f, aux->dir);
        free(aux);
    }
}
void jaInserirDisco(Reg r){
    FILE *file = fopen("arquiv.dat", "wb");
    if(!file)perror("Erro ao abrir");
    Reg r[6] = {
        {1, 10, 2},
        {3, 8, 4},
        {0, 12, 5},
        {0, 6, 0},
        {0, 9, 0},
        {0, 14, 0}
    };
    fwrite(&r, sizeof(Reg), 6, file);
    fclose(file);
}
int tam(Fila *f){
    int cont=0;
    No *aux = f->ini;
    while(aux){
        aux = aux->prox;
        cont++;
    }
    return cont;
}
int altura(FILE *file, int pos){
    if(pos==0)return 0;
    Fila *f;
    Reg r;
    int altura=0;
    initF(&f);
    enqueue(&f, pos);
    while(!isEmptyF(f)){
        int nivel = tam(f);
        for(int i=0;i<nivel;i++){
            dequeue(&f, &pos);
            fseek(file, pos * sizeof(Reg), 0);
            fread(&r, sizeof(Reg), 1, file);
            if(r.esq)enqueue(&f, r.esq);
            if(r.dir)enqueue(&f, r.dir);
        }
        altura++;
    }
    return altura;
}
void isAVLDisco(){
    FILE *file = fopen("arquivo.dat", "rb");
    if(!file)perror("Deu erro");
    Fila *f; int pos;
    Reg r, r1, r2;
    initF(&f);
    enqueue(&f, 0);
    char flag=1;
    while(!isEmptyF(f) && flag){
        dequeue(&f, &pos);
        fseek(file, pos * sizeof(Reg), 0);
        fread(&r, sizeof(Reg), 1, file);

        int fb = altura(file, r.dir) - altura(file, r.esq);
        if(abs(fb) > 1)flag=0;
        
        if(r.esq)enqueue(&f, r.esq);
        if(r.dir)enqueue(&f, r.dir);
    }
    if(flag)puts("Eh avl");
    else puts("Nao eh avl");
    fclose(file);
}
int main(){
    Tree *t=NULL;
    jaInserir(&t);
    if(ehAVL(t))puts("Eh avl");
    else puts("Nao eh avl");
}
