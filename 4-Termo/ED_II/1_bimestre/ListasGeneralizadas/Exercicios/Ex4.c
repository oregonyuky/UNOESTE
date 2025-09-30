
#include <stdio.h>
#include <stdlib.h>

typedef enum { ATOMO, LISTA } TipoNo;

typedef struct listaGen {
    TipoNo tipo;
    union {
        char atomo;
        struct {
            struct listaGen *cabeca;
            struct listaGen *cauda;
        } lista;
    } no;
} ListaGen;

// ===== Estrutura da fila =====
typedef struct NoFila {
    ListaGen **ptr;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *ini, *fim;
} Fila;

void initFila(Fila *f) {
    f->ini = f->fim = NULL;
}

int filaVazia(Fila *f) {
    return f->ini == NULL;
}

void enqueue(Fila *f, ListaGen **ptr) {
    NoFila *novo = malloc(sizeof(NoFila));
    novo->ptr = ptr;
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo;
    else f->ini = novo;
    f->fim = novo;
}

ListaGen** dequeue(Fila *f) {
    if (filaVazia(f)) return NULL;
    NoFila *rem = f->ini;
    ListaGen **ptr = rem->ptr;
    f->ini = rem->prox;
    if (!f->ini) f->fim = NULL;
    free(rem);
    return ptr;
}

// ===== Criação de nós =====
ListaGen* criaAtomo(char valor) {
    ListaGen* novo = malloc(sizeof(ListaGen));
    novo->tipo = ATOMO;
    novo->no.atomo = valor;
    return novo;
}

ListaGen* criaLista(ListaGen* cabeca, ListaGen* cauda) {
    ListaGen* novo = malloc(sizeof(ListaGen));
    novo->tipo = LISTA;
    novo->no.lista.cabeca = cabeca;
    novo->no.lista.cauda = cauda;
    return novo;
}

// ===== Algoritmo principal com FILA =====
void excluiNulos(ListaGen **L) {
    if (!L || !*L) return;

    Fila f;
    initFila(&f);

    enqueue(&f, L);

    while (!filaVazia(&f)) {
        ListaGen **pp = dequeue(&f);
        ListaGen *p = *pp, *ant = NULL;

        while (p) {
            if (p->tipo == LISTA && p->no.lista.cabeca == NULL) {
                // remover nó inválido
                ListaGen *rem = p;
                if (ant == NULL) {
                    *pp = p->no.lista.cauda;
                    p = *pp;
                } else {
                    ant->no.lista.cauda = p->no.lista.cauda;
                    p = p->no.lista.cauda;
                }
                free(rem);
            } else {
                // se for sublista não nula, enfileira a cabeca
                if (p->tipo == LISTA && p->no.lista.cabeca)
                    enqueue(&f, &p->no.lista.cabeca);
                ant = p;
                p = p->no.lista.cauda;
            }
        }
    }
}

// ===== Impressão =====
void imprime(ListaGen* l) {
    if (!l) return;
    if (l->tipo == ATOMO) {
        printf("%c ", l->no.atomo);
    } else {
        printf("(");
        imprime(l->no.lista.cabeca);
        printf(")");
        imprime(l->no.lista.cauda);
    }
}

// ===== Exemplo =====
int main() {
    ListaGen* a = criaAtomo('a');
    ListaGen* b = criaAtomo('b');

    ListaGen* lista_b = criaLista(b, NULL);        
    ListaGen* no4 = criaLista(lista_b, NULL);      

    ListaGen* no3 = criaLista(NULL, no4);          // <- nó vazio
    ListaGen* lista_a = criaLista(a, NULL);        
    ListaGen* no2 = criaLista(lista_a, no3);       

    ListaGen* no1 = criaLista(NULL, no2);          // <- nó vazio
    ListaGen* L = no1;

    printf("Antes: ");
    imprime(L);
    printf("\n");

    excluiNulos(&L);

    printf("Depois: ");
    imprime(L);
    printf("\n");

    return 0;
}
