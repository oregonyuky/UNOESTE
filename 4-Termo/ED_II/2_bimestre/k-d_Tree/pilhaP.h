typedef struct kdtree{
    int ponto[K];
    struct kdtree *esq, *dir;
} KdTree;
typedef struct NoPilhaP {
    KdTree *k;               // dado armazenado
    struct NoPilhaP *prox;   // ponteiro para o próximo
} PilhaP;

// Inicializa pilha = NULL
void initP(PilhaP **p) {
    *p = NULL;
}

// Verifica se está vazia
int isEmptyP(PilhaP *p) {
    return p == NULL;
}

// Inserir no topo
void pushP(PilhaP **p, KdTree *valor) {
    PilhaP *novo = (PilhaP*)malloc(sizeof(PilhaP));
    novo->k = valor;
    novo->prox = *p;
    *p = novo;
}

// Remover do topo
void popP(PilhaP **p, KdTree **valor) {
    PilhaP *aux = *p;
    *valor = aux->k;
    *p = aux->prox;
    free(aux);
}

typedef struct NoPilha {
    int dado;
    struct NoPilha *prox;
} Pilha;

void init(Pilha **p) {
    *p = NULL;
}

int isEmpty(Pilha *p) {
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