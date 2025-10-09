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
Node *create()
int main(){
    Node *node = NULL;
    node->esq = 
}