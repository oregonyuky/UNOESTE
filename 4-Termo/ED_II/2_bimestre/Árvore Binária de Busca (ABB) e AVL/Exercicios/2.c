#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *esq, *dir;
} Node;
void retornarPai(Node *head, int filho, Node **pai){
    if(head){
        if((head->esq && head->esq->info == filho) || (head->dir && head->dir->info == filho))*pai = head;
        retornarPai(head->esq, filho, pai);
        if(!*pai)
            retornarPai(head->dir, filho, pai);
    }
}
Node *create(int data){
    Node *nova = (Node*)malloc(sizeof(Node));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = data;
    return nova;
}
int main(){
    Node *node = create(0), *pai = NULL;
    node->esq = create(1);
    node->dir = create(2);
    node->esq->esq = create(3);
    node->esq->dir = create(4);
    node->esq->esq->esq = create(5);
    int nivel = 0, filho = 3;
    retornarPai(node, filho, &pai);
    printf("pai: %d\n", pai->info);
}