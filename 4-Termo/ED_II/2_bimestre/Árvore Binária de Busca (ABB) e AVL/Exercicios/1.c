#include <stdio.h>
typedef struct node{
    int data;
    struct node *esq, *dir;
} Node;
void retornarProfundidade(Node *head, int info, int n, int *nivel){
    if(head){
        if(head->info == info)*nivel = n;
        else{
            retornarProfundidade(head->esq, info, n+1, &*nivel);
            if(*nivel==0)
                retornarProfundidade(head->dir, info, n+1, &*nivel);
        }
    }
}
Node *create(int data){
    Node *nova = (Node*)malloc(sizeof(Node));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->data = data;
    return nova;
}
int main(){
    Node *node = NULL;
    node->esq = create(1);
    node->dir = create(2);
    node->esq->esq = create(3);
    node->esq->dir = create(4);
    node->esq->esq->esq = create(5);
    int nivel = 0;
    retornarProfundidade(node, 4, 0, &nivel);
    printf("profundidade: %d\n", nivel);
}