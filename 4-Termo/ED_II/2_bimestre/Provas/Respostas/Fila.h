#include <stdlib.h>
typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Fila {
    No *ini;
    No *fim;
} Fila;
 
typedef struct tree{
    tree *esq, *dir;
    int info;
} Tree;

typedef struct FILA{
    Tree *dado;
    struct FILA *prox;
} FILA;

Fila *initF(Fila **f) {
    (*f)->ini = NULL;
    (*f)->fim = NULL;
    return *f;
}
int isEmptyF(Fila *f) {
    return (f->ini == NULL);
}
void enqueue(Fila **f, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if ((*f)->fim == NULL) {  // fila vazia
        (*f)->ini = novo;
        (*f)->fim = novo;
    } else {
        (*f)->fim->prox = novo;
        (*f)->fim = novo;
    }
}
int dequeue(Fila **f, int *valor) {
    if (isEmptyF(*f))
        return 0; // falha, fila vazia

    No *temp = (*f)->ini;
    *valor = temp->dado;

    (*f)->ini = temp->prox;

    if ((*f)->ini == NULL)
        (*f)->fim = NULL;  // fila ficou vazia

    free(temp);
    return 1; // sucesso
}

void initFF(FILA **fila) {
    *fila = NULL;
}

int isEmptyFF(FILA *fila) {
    return (fila == NULL);
}

// enqueue O(n)
void enqueueFF(FILA **fila, Tree *valor) {
    FILA *novo = (FILA*) malloc(sizeof(FILA));
    novo->dado = valor;
    novo->prox = NULL;

    if (*fila == NULL) {
        *fila = novo;
    } else {
        FILA *aux = *fila;
        while (aux->prox) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// dequeue com parâmetro para guardar o removido
// agora NÃO retorna Tree*, devolve via parâmetro
void dequeueFF(FILA **fila, Tree **removido) {
    if (*fila == NULL) {
        *removido = NULL;
        return;
    }

    FILA *aux = *fila;
    *removido = aux->dado;

    *fila = aux->prox;

    free(aux);
}

typedef struct Func{
    struct Func *esq, *dir;
    int pos; // Posição/dado do funcionário no nó
} Func;

#define MAX_PILHA 100 // Tamanho máximo da pilha

typedef struct PilhaP {
    Func *itens[MAX_PILHA]; // Array de ponteiros para Func
    int topo;              // Índice do topo da pilha
} PilhaP;

// --- Funções da PilhaP ---

void initPP(PilhaP **p) {
    *p = (PilhaP *)malloc(sizeof(PilhaP));
    if (*p == NULL) {
        printf("Erro de alocacao de memoria para a PilhaP.\n");
        exit(1);
    }
    (*p)->topo = -1;
}

int isEmptyPP(PilhaP *p) {
    if (p == NULL) {
        return 1;
    }
    return p->topo == -1;
}

int isFullPP(PilhaP *p) {
    if (p == NULL) {
        return 0;
    }
    return p->topo == MAX_PILHA - 1;
}

void pushPP(PilhaP **p, Func *item) {
    if (*p == NULL) {
        initPP(p);
    }
    if (isFullPP(*p)) {
        printf("Erro: Pilha Cheia! Nao foi possivel inserir o item.\n");
        return;
    }
    (*p)->topo++;
    (*p)->itens[(*p)->topo] = item;
}

int popPP(PilhaP **p, Func **item) {
    if (*p == NULL || isEmptyPP(*p)) {
        *item = NULL;
        return 0;
    }
    *item = (*p)->itens[(*p)->topo];
    (*p)->topo--;
    return 1;
}
