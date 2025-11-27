typedef struct NoFila {
    int dado;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;
#define MAX 100

typedef struct fila {
    Tree* dados[MAX];
    int ini, fim;
} FILA;

void init(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int isEmpty(Fila f) {
    return f.inicio == NULL;
}

void enqueue(Fila *f, int valor) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->dado = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue(Fila *f, int *valor) {
    if (f->inicio == NULL)
        return 0;

    NoFila *aux = f->inicio;
    *valor = aux->dado;
    f->inicio = aux->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);
    return 1;
}
typedef struct NoPilha {
    int dado;
    struct NoPilha *prox;
} Pilha;

void initP(Pilha **p) {
    *p = NULL;
}

int isEmptyP(Pilha *p) {
    return p == NULL;
}

void push(Pilha **p, int valor) {
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox = *p;
    *p = novo;
}

void pop(Pilha **p, int *valor) {
    Pilha *aux = *p, *ant;
    *valor = aux->dado;
    *p = (*p)->prox;
    free(aux);
}

void initF(FILA **f) {
    *f = (FILA*) malloc(sizeof(FILA));
    (*f)->ini = 0;
    (*f)->fim = 0;
}

int isEmptyF(FILA *f) {
    return (f->ini == f->fim);
}

void enqueueF(FILA **f, Tree *x) {
    int prox = (((*f)->fim + 1) % MAX);

    // fila cheia
    if (prox == (*f)->ini) {
        printf("Fila cheia!\n");
        return;
    }

    (*f)->dados[(*f)->fim] = x;
    (*f)->fim = prox;
}

void dequeueF(FILA **f, Tree **no) {
    if (isEmptyF(*f)) {
        return;
    }
    Tree *x = (*f)->dados[(*f)->ini];
    (*f)->ini = (((*f)->ini + 1) % MAX);
    *no = x;
}

