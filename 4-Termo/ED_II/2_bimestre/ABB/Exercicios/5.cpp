#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio2.h>
#define K 7
typedef struct Tree{
    int info;
    struct Tree *esq;
    struct Tree *dir;
} Tree;
typedef struct tabela{
    int esq, info, dir;
} Tabela;
int gravar(FILE *file, int info){
    Tabela aux;
    aux.esq = 0;
    aux.dir = 0;
    aux.info = info;
    fseek(file, 0, SEEK_END);
    fwrite(&aux, sizeof(Tabela), 1, file);
    return ftell(file)/sizeof(Tabela) - 1;
}
void inserirArvoreABB(char arquivo[], int info){
    FILE *file = fopen(arquivo, "w+b");
    if(!file)return;
    Tabela tabela;
    bool e=1;
    int posA = 0, posF;
    while(e){
        fseek(file, posA, 1);
        fread(&tabela, sizeof(Tabela), 1, file);
        if(tabela.info > info){
            if(tabela.esq == 0){
                posF = gravar(file, info);
                tabela.esq = posF;
                fseek(file, posA, SEEK_SET);
                fwrite(&tabela, sizeof(Tabela), 1, file);
                e=0;
            }
            else posA = tabela.esq * sizeof(Tabela);
        }
        else if(tabela.info < info){
            if(tabela.dir == 0){
                posF = gravar(file, info);
                tabela.dir = posF;
                fseek(file, posA, SEEK_SET);
                fwrite(&tabela, sizeof(Tabela), 1, file);
                e=0;
            }
            else posA = tabela.dir * sizeof(Tabela);
        }
    }
}

typedef struct NoFila {
    int dado;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

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

void percorrerNivel(char arquivo[], int pos) {
    FILE *file = fopen(arquivo, "rb");
    if (!file) return;

    Tabela tabela;
    Fila f;
    init(&f);
    enqueue(&f, pos);

    while (!isEmpty(f)) {
        dequeue(&f, &pos);
        fseek(file, (pos - 1) * sizeof(Tabela), SEEK_SET);
        fread(&tabela, sizeof(Tabela), 1, file);

        printf("%d ", tabela.info);

        if (tabela.esq != 0) enqueue(&f, tabela.esq);
        if (tabela.dir != 0) enqueue(&f, tabela.dir);
    }

    fclose(file);
}
void preOrdemRecursivo(FILE *file, int pos){
    Tabela tabela;
    fseek(file, (pos)*sizeof(Tabela), SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    printf("%d ", tabela.info);
    if(tabela.esq!=0)preOrdemRecursivo(file, tabela.esq);
    if(tabela.dir!=0)preOrdemRecursivo(file, tabela.dir);
}
void inOrdemRecursivo(FILE *file, int pos){
    Tabela tabela;
    fseek(file, (pos)*sizeof(Tabela), SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    if(tabela.esq!=0)inOrdemRecursivo(file, tabela.esq);
    printf("%d ", tabela.info);
    if(tabela.dir!=0)inOrdemRecursivo(file, tabela.dir);
}
void posOrdemRecursivo(FILE *file, int pos){
    Tabela tabela;
    fseek(file, (pos)*sizeof(Tabela), SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    if(tabela.esq!=0)posOrdemRecursivo(file, tabela.esq);
    if(tabela.dir!=0)posOrdemRecursivo(file, tabela.dir);
    printf("%d ", tabela.info);
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

void preOrdemIterativo(FILE *file){
    Tabela tabela;
    Pilha *p;
    int pos=0;
    initP(&p);
    fseek(file, 0, SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    push(&p, tabela.info);
    while(!isEmptyP(p)){
        pop(&p, &pos);
        fseek(file, pos * sizeof(Tabela), SEEK_SET);
        fread(&tabela, sizeof(Tabela), 1, file);
        printf("%d ", tabela.info);
        if(tabela.dir)push(&p, tabela.dir);
        if(tabela.esq)push(&p, tabela.esq);
    }
}
void inOrdemIterativo(FILE *file){
    Tabela tabela, aux;
    Pilha *p;
    int pos=0;
    initP(&p);
    fseek(file, 0, SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    aux = tabela;
    push(&p, tabela.info);
    while(!isEmptyP(p)){
        pos = aux.info;
        while(pos){
            push(&p, pos);
            fseek(file, pos * sizeof(Tabela), SEEK_SET);
            fread(&aux, sizeof(Tabela), 1, file);
            pos = aux.esq;
        }
        pop(&p, &pos);
        fseek(file, pos * sizeof(Tabela), SEEK_SET);
        fread(&aux, sizeof(Tabela), 1, file);
        printf("%d ", tabela.info);
        if(tabela.dir)push(&p, tabela.dir);
        if(tabela.esq)push(&p, tabela.esq);
    }
}
void imprimir(char arquivo[]){
    FILE *file = fopen(arquivo, "rb");
    if(!file){
        perror("Deu erro");
        return;
    }
    Tabela tabela;
    while (fread(&tabela, sizeof(Tabela), 1, file) == 1){
        printf("(%d, %d, %d)\n", tabela.esq, tabela.info, tabela.dir);
    }
}
void exclusao(Tree *raiz, Tree *e, Tree*pai){
    if(!e->esq && !e->dir){
        if(pai->esq == e)
            pai->esq = NULL;
        else
            pai->dir = NULL;
        free(e);
    }
    else if(!e->esq || !e->dir){
        Tree *filho;
        if(e->esq)
            filho = e->esq;
        else
            filho = e->dir;
        if(pai->esq == e)
            pai->esq = filho;
        else
            pai->dir = filho;
        free(e);
    }
    else{
        Tree *aux = e->esq;
        Tree *paiAux = e;
        while(aux->dir){
            paiAux = aux;
            aux = aux->dir;
        }
        e->info = aux->info;
        exclusao(raiz, aux, paiAux);
    }
}

/*
void exibir(Tree *raiz, int x, int y, int dist){
    if(raiz){
        gotoxy(x, y);
        printf("%d ", raiz->info);
        if(raiz->esq){
            gotoxy(x - dist/2, y + 1);
            printf("/");
        }
        if(raiz->dir){
            gotoxy(x + dist/2, y + 1);
            printf("\\");
        }
        exibir(raiz->esq, x - dist, y + 2, dist / 2);
        exibir(raiz->dir, x + dist, y + 2, dist / 2);
    }
}
    */
Tree *create(int data) {
    Tree *nova = (Tree*)malloc(sizeof(Tree));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = data;
    return nova;
}
void CriarArvore(){
    Tree *node = create(40), *pai = NULL;
    node->esq = create(20);
    node->dir = create(42);
    node->esq->esq = create(10);
    node->esq->dir = create(35);
    node->esq->dir->esq = create(30);
    node->dir->dir = create(52);
    node->dir->dir->esq = create(50);
    //exibir(node, 40, 1, 16);

}
int main(){
    char arquivo[] = "arquivo.bat";
    char vet[K][3] = {{4, 10, 1}, {2, 12, 3}, {0, 11, 0}, {0, 14, 0}, {5, 8, 6}, {0, 6, 0}, {0, 9, 0}};
    Tabela tabela[K];
    for (int i = 0; i < K;i++){
        tabela[i].esq = vet[i][0];
        tabela[i].info = vet[i][1];
        tabela[i].dir = vet[i][2];
    }
    FILE *file = fopen(arquivo, "wb");
    fwrite(&tabela, sizeof(Tabela), K, file);
    if(!file){
        perror("Deu erro\n");
        return 0;
    }
    fclose(file);
    imprimir(arquivo);
    file = fopen(arquivo, "rb");
    if(!file){
        perror("Deu erro\n");
        return 0;
    }
    preOrdemRecursivo(file, 0); puts("");
    inOrdemRecursivo(file, 0); puts("");
    posOrdemRecursivo(file, 0); puts("");
    preOrdemIterativo(file); puts("");
    fclose(file);
}