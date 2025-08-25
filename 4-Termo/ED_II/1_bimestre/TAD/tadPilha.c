#include <stdio.h>
#include <stdlib.h>
struct pilha{
    int info;
    struct pilha *prox;
};
typedef struct pilha Pilha;
void init(Pilha **p){
    *p = NULL;
}
void push(Pilha **p, int x){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova->info = x;
    nova->prox = *p;
    *p = nova;
}
char isEmpty(Pilha *p){
    return p==NULL;
}
int top(Pilha *p){
    if(!isEmpty(p))return p->info;
    return -1;
}
void pop(Pilha **p, int *x){
    Pilha *aux;
    if(!isEmpty(*p)){
        *x = (*p)->info;
        aux = *p;
        *p = aux->prox;
        free(aux);
    }
    else{
        *x = -1;
    }
}
void exibir(Pilha *p){
    Pilha *aux = p;
    while(aux){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
int main(){
    Pilha *p;
    init(&p);
    printf("Lista original: ");
    push(&p, 10);
    push(&p, 11);
    push(&p, 12);
    exibir(p);puts("");
    int x;
    pop(&p, &x);
    printf("Lista apos pop: ");
    exibir(p);
    printf(" x: %d", x);
    printf("\nTop: %d\n", top(p));
}