#include <stdlib.h>
typedef struct no {
    int info;
    struct no *esq, *dir;
} Tree;

typedef struct noPilha {
    Tree *end;
    struct noPilha *prox;
} NoPilha;

typedef struct pilha {
    NoPilha *base;
    NoPilha *topo;
} Pilha;
void initP(Pilha **p) {
    *p = (Pilha*)malloc(sizeof(Pilha));
    (*p)->base = NULL;
    (*p)->topo = NULL;
}
int isEmptyP(Pilha **p) {
    return ((*p)->topo == NULL);
}
int push(Pilha **p, Tree *no) {
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (!novo) return 0;

    novo->end = no;
    novo->prox = NULL;

    if ((*p)->base == NULL) {
        (*p)->base = novo;
        (*p)->topo = novo;
    } else {
        (*p)->topo->prox = novo;
        (*p)->topo = novo;
    }

    return 1;
}
int pop(Pilha **p, Tree **no) {
    if (isEmptyP(p)) return 0;

    NoPilha *aux = (*p)->topo;
    *no = aux->end;

    // só um elemento
    if ((*p)->topo == (*p)->base) {
        (*p)->topo = NULL;
        (*p)->base = NULL;
        free(aux);
        return 1;
    }

    // percorrer até o penúltimo
    NoPilha *ant = (*p)->base;
    while (ant->prox != (*p)->topo)
        ant = ant->prox;

    ant->prox = NULL;
    (*p)->topo = ant;

    free(aux);
    return 1;
}
