#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *esq, *dir;
} Node;
void liberarArvore(Node **head){
    if(!*head)return;
    liberarArvore(&((*head)->esq));
    liberarArvore(&((*head)->dir));
    free(*head);
    *head = NULL;
}
Node *create(int data) {
    Node *nova = (Node*)malloc(sizeof(Node));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = data;
    return nova;
}
int main() {
    Node *node = create(0), *pai = NULL;
    node->esq = create(1);
    node->dir = create(2);
    node->esq->esq = create(3);
    node->esq->dir = create(4);
    node->esq->esq->esq = create(5);
    liberarArvore(&node);
    if(!node)printf("Liberado!!!\n");
}