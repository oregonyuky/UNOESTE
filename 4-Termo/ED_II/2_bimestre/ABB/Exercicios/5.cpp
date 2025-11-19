#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio2.h>
#include "filaPilha.h"
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
    return ftell(file)/sizeof(Tabela)-1;
}
void inserirArvoreABB(FILE *file, int info){
    Tabela tabela;
    bool e=1;
    int posA = 0, posF;
    
    while(e){
        fseek(file, posA * sizeof(Tabela), 0);
        fread(&tabela, sizeof(Tabela), 1, file);
        if(tabela.info > info){
            if(tabela.esq == 0){
                tabela.esq = gravar(file, info);
                fseek(file, posA * sizeof(Tabela), SEEK_SET);
                fwrite(&tabela, sizeof(Tabela), 1, file);
                e=0;
            }
            else posA = tabela.esq;
        }
        else if(tabela.info < info){
            if(tabela.dir == 0){
                tabela.dir = gravar(file, info);
                fseek(file, posA * sizeof(Tabela), SEEK_SET);
                fwrite(&tabela, sizeof(Tabela), 1, file);
                e=0;
            }
            else posA = tabela.dir;
        }
    }
}

void percorrerNivel(FILE *file) {
    Tabela tabela;
    int pos;
    Fila f;
    init(&f);
    enqueue(&f, 0);
    while (!isEmpty(f)) {
        dequeue(&f, &pos);
        fseek(file, pos * sizeof(Tabela), SEEK_SET);
        fread(&tabela, sizeof(Tabela), 1, file);
        printf("%d ", tabela.info);
        if (tabela.esq) enqueue(&f, tabela.esq);
        if (tabela.dir) enqueue(&f, tabela.dir);
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

void preOrdemIterativo(FILE *file){
    Tabela tabela;
    Pilha *p;
    int pos=0;
    initP(&p);
    fseek(file, 0, SEEK_SET);
    fread(&tabela, sizeof(Tabela), 1, file);
    printf("%d ", tabela.info);
    push(&p, tabela.dir);
    push(&p, tabela.esq);
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
    push(&p, 0);
    push(&p, tabela.esq);
    while(!isEmptyP(p)){
        pop(&p, &pos);
        while(pos){
            push(&p, pos);
            fseek(file, pos * sizeof(Tabela), SEEK_SET);
            fread(&aux, sizeof(Tabela), 1, file);
            pos = aux.esq;
        }
        if(!isEmptyP(p)){
            pop(&p, &pos);
            fseek(file, pos * sizeof(Tabela), SEEK_SET);
            fread(&aux, sizeof(Tabela), 1, file);
            printf("%d ", aux.info);
            push(&p, aux.dir);
        }
    }
}
void posOrdemIterativo(FILE *file){
    Tabela tabela;
    Pilha *p1, *p2; int pos=0;
    initP(&p1);
    initP(&p2);
    push(&p1, 0);
    while(!isEmptyP(p1)){
        pop(&p1, &pos);
        push(&p2, pos);
        fseek(file, pos * sizeof(Tabela), SEEK_SET);
        fread(&tabela, sizeof(Tabela), 1, file);
        if(tabela.esq)push(&p1, tabela.esq);
        if(tabela.dir)push(&p1, tabela.dir);
    }
    while(!isEmptyP(p2)){
        pop(&p2, &pos);
        fseek(file, pos * sizeof(Tabela), SEEK_SET);
        fread(&tabela, sizeof(Tabela), 1, file);
        printf("%d ", tabela.info);
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
void exclusao(Tree **raiz, Tree *e, Tree*pai){
    if(!e->esq && !e->dir){
        if(pai->esq == e)pai->esq = NULL;
        else pai->dir = NULL;
        free(e);
    }
    else if(!e->esq || !e->dir){
        Tree *filho;
        if(e->esq)filho = e->esq;
        else filho = e->dir;
        if(pai->esq == e)pai->esq = filho;
        else pai->dir = filho;
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
void exclusaoIterativo(Tree **raiz, Tree *e, Tree*pai){
    if(!e->esq && !e->dir){
        if(pai->esq == e)pai->esq = NULL;
        else pai->dir = NULL;
        free(e);
    }
    else if(!e->esq || !e->dir){
        Tree *filho;
        if(e->esq)filho = e->esq;
        else filho = e->dir;
        if(pai->esq == e)pai->esq = filho;
        else pai->dir = filho;
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
        if(aux->esq){
            paiAux->dir = aux->esq;
            free(aux);
        }else{
            paiAux->dir = NULL;
            free(aux);
        }
    }
}
Tabela BuscaPreOrdem(FILE *file, int info){
    Tabela T, aux;
    Pilha *p;
    char flag=1;
    fseek(file, 0, 0);
    fread(&T, sizeof(Tabela), 1, file);
    initP(&p);
    push(&p, T.dir);
    push(&p, T.esq);
    while(!isEmptyP(p) && flag){
        pop(&p, &pos);
        fseek(file, pos * sizeof(Tabela), 0);
        fread(&T, sizeof(Tabela), 1, file);
        if(T.info == info){aux = T; flag=0;}
        else{
            if(T.dir)push(&p, T.dir);
            if(T.esq)push(&p, T.esq);
        }
    }
    if(!flag)return aux;
    return NULL;
}
int BuscaIndex(FILE *file, int pai){
    Tabela T;
    int pos=0;
    rewind(file);
    while(fread(&T, sizeof(Tabela), 1, file)==1 && flag){
        if(T.info == info)flag=0;
        else pos++;
    }
    return pos;
}
void exclusaoBinario(FILE *file, int filho, int pai){
    Tabela e = BuscaPreOrdem(file, filho);
    Tabela p = BuscaPreOrdem(file, pai);
    if(!e.esq && !e.dir){
        fseek(file, p.esq * sizeof(Tabela), 0);
        fread(&T, sizeof(Tabela), 1, file);
        if(T.info == filho){
            fseek(file, BuscaIndex(file, pai) * sizeof(Tabela), 0);
            fread(&T, sizeof(Tabela), 1, file);
            T.esq = 0;
            fseek(file, BuscaIndex(file, pai) * sizeof(Tabela), 0);
            fwrite(&T, sizeof(Tabela), 1, file);
        }
        fseek(file, p.dir * sizeof(Tabela), 0);
        fread(&T, sizeof(Tabela), 1, file);
        if(T.info == filho){
            fseek(file, BuscaIndex(file, pai) * sizeof(Tabela), 0);
            fread(&T, sizeof(Tabela), 1, file);
            T.dir = 0;
            fseek(file, BuscaIndex(file, pai) * sizeof(Tabela), 0);
            fwrite(&T, sizeof(Tabela), 1, file);
        }
        int pos = BuscaIndex(file, filho);
        fseek(file, 0, 2);
        int posFinal = ftell(file)/sizeof(Tabela) - 1;
        int k=0;
        for(int i=pos;i<posFinal-1;i++){
            T[i] = T[i+1];
            ++k;
        }
        rewind(file);
        fwrite(file, sizeof(Tabela), K-1, file);
    }

}
void exclusaoTabela(FILE *file, int filho, int pai){
    Tabela t;
    fseek(file, pos * sizeof(Tabela), 0);
    fread(&t, sizeof(Tabela), 1, file);
    (!t.esq && !t.dir){

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
void CriarArvore(Tree **node){
    (*node) = create(40), 
    (*node)->esq = create(20);
    (*node)->dir = create(42);
    (*node)->esq->esq = create(10);
    (*node)->esq->dir = create(35);
    (*node)->esq->dir->dir = create(36);
    
    (*node)->dir->dir = create(52);
    (*node)->dir->dir->esq = create(50);
    
    (*node)->esq->esq->esq = create(7);
    (*node)->esq->esq->esq->esq = create(6);

    (*node)->esq->esq->dir = create(12);
    (*node)->esq->esq->dir->esq = create(11);
    (*node)->esq->esq->dir->dir = create(13);

    //exibir(node, 40, 1, 16);

}
void printarinOrder(Tree *raiz){
    if(raiz){
        printarinOrder(raiz->esq);
        printf("%d ", raiz->info);
        printarinOrder(raiz->dir);
    }
}
void imprimirFile(FILE *file){
	Tabela tabela;
    while (fread(&tabela, sizeof(Tabela), 1, file) == 1){
        printf("(%d, %d, %d)\n", tabela.esq, tabela.info, tabela.dir);
    }
}
void teste(){
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
        return ;
    }
    fclose(file);
    imprimir(arquivo);
    file = fopen(arquivo, "rb");
    if(!file){
        perror("Deu erro\n");
        return ;
    }
    printf("pre: ");preOrdemRecursivo(file, 0); puts("");
    printf("in: ");inOrdemRecursivo(file, 0); puts("");
    printf("pos: ");posOrdemRecursivo(file, 0); puts("");
    printf("preI: ");preOrdemIterativo(file); puts("");
    printf("inI: ");inOrdemIterativo(file); puts("");
    printf("posI: ");posOrdemIterativo(file); puts("");
    printf("PercorrerNivel: "); percorrerNivel(file); puts("");
    fclose(file);

    file = fopen(arquivo, "w+b");
    fwrite(&tabela, sizeof(Tabela), K, file);
    if(!file){
        perror("Deu erro\n");
        return ;
    }
    inserirArvoreABB(file, 5); puts("");
    rewind(file);
    imprimirFile(file);
    fclose(file);
}
void printarAposExclusao(){
	Tree *raiz = NULL;
    CriarArvore(&raiz);
    Tree *pai = raiz; //40
    Tree *e = raiz->esq; //20
    exclusaoIterativo(&raiz, e, pai);
    exibir(raiz, 80, 5, 20);
}
int main(){
	teste();
}
