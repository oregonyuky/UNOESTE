#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==========================
// Estrutura da Lista Genérica
// ==========================
typedef struct listagen {
    char terminal; // 1 = átomo, 0 = lista
    union {
        char info[30]; // se for átomo
        struct {
            struct listagen *cabeca;
            struct listagen *cauda;
        } lista; // se for lista
    } no;
} ListaGen;

// ==========================
// Funções básicas da ListaGen
// ==========================
ListaGen* CriaT(const char *info) {
    ListaGen *novo = (ListaGen*) malloc(sizeof(ListaGen));
    novo->terminal = 1;
    strcpy(novo->no.info, info);
    return novo;
}

ListaGen* Cons(ListaGen *h, ListaGen *t) {
    ListaGen *novo = (ListaGen*) malloc(sizeof(ListaGen));
    novo->terminal = 0;
    novo->no.lista.cabeca = h;
    novo->no.lista.cauda = t;
    return novo;
}

ListaGen* Head(ListaGen *l) {
    if (l && !l->terminal) return l->no.lista.cabeca;
    return NULL;
}

ListaGen* Tail(ListaGen *l) {
    if (l && !l->terminal) return l->no.lista.cauda;
    return NULL;
}

int Atomo(ListaGen *l) {
    return (l && l->terminal);
}

void Libera(ListaGen *l) {
    if (!l) return;
    if (l->terminal) {
        free(l);
    } else {
        Libera(l->no.lista.cabeca);
        Libera(l->no.lista.cauda);
        free(l);
    }
}

// ==========================
// Fila genérica (para nós)
// ==========================
typedef struct nodoFila {
    void *info;
    struct nodoFila *prox;
} NodoFila;

typedef struct fila {
    NodoFila *ini, *fim;
} Fila;

void init(Fila **f) {
    *f = (Fila*) malloc(sizeof(Fila));
    (*f)->ini = (*f)->fim = NULL;
}

int isEmpty(Fila *f) {
    return f->ini == NULL;
}

void enqueue(Fila **f, void *x) {
    NodoFila *novo = (NodoFila*) malloc(sizeof(NodoFila));
    novo->info = x;
    novo->prox = NULL;
    if ((*f)->fim) (*f)->fim->prox = novo;
    else (*f)->ini = novo;
    (*f)->fim = novo;
}

void dequeue(Fila **f, void **x) {
    if (isEmpty(*f)) {
        *x = NULL;
        return;
    }
    NodoFila *tmp = (*f)->ini;
    *x = tmp->info;
    (*f)->ini = tmp->prox;
    if (!(*f)->ini) (*f)->fim = NULL;
    free(tmp);
}

// ==========================
// Fila de inteiros (níveis)
// ==========================
typedef struct nodoFilaP {
    int valor;
    struct nodoFilaP *prox;
} NodoFilaP;

typedef struct filaP {
    NodoFilaP *ini, *fim;
} FilaP;

void initP(FilaP **f) {
    *f = (FilaP*) malloc(sizeof(FilaP));
    (*f)->ini = (*f)->fim = NULL;
}

int isEmptyP(FilaP *f) {
    return f->ini == NULL;
}

void enqueueP(FilaP **f, int x) {
    NodoFilaP *novo = (NodoFilaP*) malloc(sizeof(NodoFilaP));
    novo->valor = x;
    novo->prox = NULL;
    if ((*f)->fim) (*f)->fim->prox = novo;
    else (*f)->ini = novo;
    (*f)->fim = novo;
}

void dequeueP(FilaP **f, int *x) {
    if (isEmptyP(*f)) {
        *x = -1;
        return;
    }
    NodoFilaP *tmp = (*f)->ini;
    *x = tmp->valor;
    (*f)->ini = tmp->prox;
    if (!(*f)->ini) (*f)->fim = NULL;
    free(tmp);
}

// ==========================
// Exibir Lista
// ==========================
void Exibir(ListaGen *L) {
    printf("(");
    while (L) {
        ListaGen *h = Head(L);
        if (h && Atomo(h)) {
            printf("%s", h->no.info);
        } else if (h) {
            Exibir(h);
        }
        L = Tail(L);
        if (L) printf(" ");
    }
    printf(")");
}

// ==========================
// Excluir átomos em nível n
// ==========================
void exclui_nivel(ListaGen **L, int n) {
    if (!L || !*L) return;

    Fila *f;
    FilaP *fp;
    init(&f);
    initP(&fp);

    enqueue(&f, *L);
    enqueueP(&fp, 1); // raiz está no nível 1

    while (!isEmpty(f)) {
        ListaGen *atual;
        int nivel;

        dequeue(&f, (void**)&atual);
        dequeueP(&fp, &nivel);

        ListaGen *pL = atual;
        while (pL) {
            ListaGen *h = Head(pL);

            if (nivel == n && h && Atomo(h)) {
                free(h);
                pL->no.lista.cabeca = NULL;
            } else if (h && !Atomo(h)) {
                enqueue(&f, h);
                enqueueP(&fp, nivel + 1);
            }

            pL = Tail(pL);
        }
    }

    free(f);
    free(fp);
}

// ==========================
// Main
// ==========================
int main() {
    ListaGen *L = NULL;

    // Lista: (a b (c d) (x (f)))
    L = Cons(CriaT("a"),
        Cons(CriaT("b"),
        Cons(Cons(CriaT("c"),
                  Cons(CriaT("d"), NULL)),
        Cons(Cons(CriaT("x"),
                  Cons(Cons(CriaT("f"), NULL), NULL)),
        NULL))));

    printf("Antes: ");
    Exibir(L);
    printf("\n");

    exclui_nivel(&L, 2);

    printf("Depois: ");
    Exibir(L);
    printf("\n");

    Libera(L);
    return 0;
}
