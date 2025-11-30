#include <stdlib.h>
typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Fila {
    No *ini;
    No *fim;
} Fila;
Fila *initF() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
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

