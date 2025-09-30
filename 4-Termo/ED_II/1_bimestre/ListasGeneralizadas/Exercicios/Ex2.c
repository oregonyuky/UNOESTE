#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// ----------- LISTA GENERALIZADA -----------
//
typedef struct listagen {
    char terminal;  // 1 = átomo, 0 = lista
    union {
        char info[8]; // átomo (string)
        struct {
            struct listagen *cabeca;
            struct listagen *cauda;
        } lista;
    } no;
} ListaGen;

ListaGen* CriaT(char *s) {
    ListaGen *novo = (ListaGen*) malloc(sizeof(ListaGen));
    novo->terminal = 1;
    strcpy(novo->no.info, s);
    return novo;
}

ListaGen* Cons(ListaGen *h, ListaGen *t) {
    ListaGen *novo = (ListaGen*) malloc(sizeof(ListaGen));
    novo->terminal = 0;
    novo->no.lista.cabeca = h;
    novo->no.lista.cauda = t;
    return novo;
}

int Atomo(ListaGen *l) { return (l && l->terminal == 1); }
ListaGen* Head(ListaGen *l) { return (l && !Atomo(l)) ? l->no.lista.cabeca : NULL; }
ListaGen* Tail(ListaGen *l) { return (l && !Atomo(l)) ? l->no.lista.cauda : NULL; }
int Nula(ListaGen *l) { return (l == NULL); }

void Exibir(ListaGen *l) {
    if (!l) return;
    if (Atomo(l)) {
        printf("%s", l->no.info);
    } else {
        printf("(");
        ListaGen *aux = l;
        while (aux) {
            Exibir(Head(aux));
            if (Tail(aux)) printf(" ");
            aux = Tail(aux);
        }
        printf(")");
    }
}

//
// ----------- FILA DE LISTAGEN -----------
//
typedef struct nodoF {
    ListaGen *l;
    struct nodoF *prox;
} NodoF;

typedef struct {
    NodoF *ini, *fim;
} Fila;

void init(Fila **f) {
    *f = (Fila*) malloc(sizeof(Fila));
    (*f)->ini = (*f)->fim = NULL;
}
int isEmpty(Fila *f) { return f->ini == NULL; }

void enqueue(Fila **f, ListaGen *l) {
    NodoF *n = (NodoF*) malloc(sizeof(NodoF));
    n->l = l; n->prox = NULL;
    if ((*f)->fim) (*f)->fim->prox = n;
    else (*f)->ini = n;
    (*f)->fim = n;
}
void dequeue(Fila **f, ListaGen **l) {
    if (isEmpty(*f)) return;
    NodoF *n = (*f)->ini;
    *l = n->l;
    (*f)->ini = n->prox;
    if (!(*f)->ini) (*f)->fim = NULL;
    free(n);
}

//
// ----------- FILA DE INTEIROS -----------
//
typedef struct nodoFP {
    int valor;
    struct nodoFP *prox;
} NodoFP;

typedef struct {
    NodoFP *ini, *fim;
} FilaP;

void initP(FilaP **f) {
    *f = (FilaP*) malloc(sizeof(FilaP));
    (*f)->ini = (*f)->fim = NULL;
}
int isEmptyP(FilaP *f) { return f->ini == NULL; }

void enqueueP(FilaP **f, int v) {
    NodoFP *n = (NodoFP*) malloc(sizeof(NodoFP));
    n->valor = v; n->prox = NULL;
    if ((*f)->fim) (*f)->fim->prox = n;
    else (*f)->ini = n;
    (*f)->fim = n;
}
void dequeueP(FilaP **f, int *v) {
    if (isEmptyP(*f)) return;
    NodoFP *n = (*f)->ini;
    *v = n->valor;
    (*f)->ini = n->prox;
    if (!(*f)->ini) (*f)->fim = NULL;
    free(n);
}

//
// ----------- INSERE ORDENADO -----------
//
void insereLG(ListaGen **l, char info[8]) {
    ListaGen *ant = NULL, *aux = *l;
    char flag = 1;
    while (aux && flag) {
        if (Atomo(Head(aux)) && strcmp(info, Head(aux)->no.info) <= 0)
            flag = 0;
        else {
            ant = aux;
            aux = Tail(aux);
        }
    }
    if (!aux || strcmp(info, aux->no.info) != 0) {
        if (!ant)
            *l = Cons(CriaT(info), *l);
        else
            ant->no.lista.cauda = Cons(CriaT(info), aux);
    }
}
void insere(ListaGen **l, char info[8], int n) {
    Fila *f1, *f2;
    FilaP *fn1, *fn2;
    ListaGen *aux;
    int nivel;

    init(&f1); init(&f2);
    initP(&fn1); initP(&fn2);

    enqueue(&f1, *l);
    enqueue(&f2, *l);
    enqueueP(&fn1, 1);
    enqueueP(&fn2, 1);

    while (!isEmpty(f1)) {
        dequeue(&f1, &aux);
        dequeueP(&fn1, &nivel);

        while (aux) {
            if (!Nula(Head(aux)) && !Atomo(Head(aux))) {
                enqueue(&f1, Head(aux));
                enqueue(&f2, aux);
                enqueueP(&fn1, nivel + 1);
                enqueueP(&fn2, nivel + 1);
            }
            aux = Tail(aux);
        }

        while (!isEmpty(f2)) {
            dequeue(&f2, &aux);
            dequeueP(&fn2, &nivel);           
            if (nivel == n) {
                if (*l == aux)
                    insereLG(l, info);
                else
                    insereLG(&aux->no.lista.cabeca, info);
            }
        }
    }
}

//
// ----------- MAIN DE TESTE -----------
//
int main() {
    ListaGen *l = Cons(
        CriaT("x"),
        Cons(
            CriaT("y"),
            Cons(
                Cons(CriaT("a"), Cons(CriaT("b"), NULL)),
                NULL
            )
        )
    );

    printf("Antes:\n");
    Exibir(l);
    printf("\n");

    insere(&l, "c", 2);

    printf("Depois:\n");
    Exibir(l);
    printf("\n");

    return 0;
}
