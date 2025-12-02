#define K 2
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
      if (*p == NULL) {
        printf("Erro: A pilha está vazia!\n");
        return;  // Não faz nada se a pilha estiver vazia
    }

    Pilha *aux = *p;
    *valor = aux->dado;
    *p = (*p)->prox;
    free(aux);
}
#define K 2  // Número de dimensões
#define TF 6  // Número total de pontos na árvore

// Definindo a estrutura da fila
typedef struct NoFila {
    KdTree *node;  // Ponteiro para o nó da árvore
    struct NoFila *prox;  // Ponteiro para o próximo nó na fila
} Fila;

// Função para inicializar a fila
void initF(Fila **f) {
    *f = NULL;  // Fila começa vazia
}

// Função para verificar se a fila está vazia
int isEmptyF(Fila *f) {
    return f == NULL;  // Retorna 1 se a fila estiver vazia, 0 caso contrário
}

// Função para adicionar um nó na fila (enqueue)
void enqueue(Fila **f, KdTree *node) {
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->node = node;
    novo->prox = NULL;  // Novo nó não aponta para nenhum outro nó

    if (*f == NULL) {
        *f = novo;  // Se a fila estiver vazia, o novo nó é a fila
    } else {
        Fila *temp = *f;
        while (temp->prox != NULL) {
            temp = temp->prox;  // Vai até o final da fila
        }
        temp->prox = novo;  // Adiciona o novo nó no final da fila
    }
}

// Função para remover um nó da fila (dequeue)
void dequeue(Fila **f, KdTree **node) {
    if (isEmptyF(*f)) {
        *node = NULL;  // Se a fila estiver vazia, retorna NULL
        return;
    }

    Fila *temp = *f;
    *node = temp->node;  // Armazena o nó removido
    *f = temp->prox;  // Atualiza a fila removendo o nó
    free(temp);  // Libera a memória do nó removido
}