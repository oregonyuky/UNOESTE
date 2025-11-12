#include <stdio.h>
#include <stdlib.h>
//#include <conio2.h>
typedef struct Tree{
    int info;
    struct Tree *esq;
    struct Tree *dir;
} Tree;
typedef struct tabela{
    int esq, info, dir;
} Tabela;
void inserirArvoreABB(Tree **raiz, Tabela tabela){
    FILE *file = fopen("arquivo.bat", "rb");
    if(!file)return;
    fread(&tabela, sizeof(Tabela), 1, file);
    
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
Tree *create(int data) {
    Tree *nova = (Tree*)malloc(sizeof(Tree));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = data;
    return nova;
}

int main(){
    Tree *node = create(40), *pai = NULL;
    node->esq = create(20);
    node->dir = create(42);
    node->esq->esq = create(10);
    node->esq->dir = create(35);
    node->esq->dir->esq = create(30);
    node->dir->dir = create(52);
    node->dir->dir->esq = create(50);
    exibir(node, 40, 1, 16);
}