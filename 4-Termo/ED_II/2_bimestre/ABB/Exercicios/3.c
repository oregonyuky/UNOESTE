#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *esq, *dir;
} Node;

typedef struct pilha {
    Node *itens[100];
    int topo;
} Pilha;

void init(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, Node *n) {
    if (p->topo < 99) {
        p->itens[++(p->topo)] = n;
    }
}

Node *pop(Pilha *p) {
    if (!isEmpty(p)) {
        return p->itens[(p->topo)--];
    }
    return NULL;
}


void preOrdem(Node *head) {
    if (!head) return;

    Pilha p;
    init(&p);
    push(&p, head);

    while (!isEmpty(&p)) {
        Node *curr = pop(&p);
        printf("%d ", curr->info);

        if (curr->dir) push(&p, curr->dir);
        if (curr->esq) push(&p, curr->esq);
    }
}

void inOrdem(Node *head) {
    if (!head) return;

    Pilha p;
    init(&p);
    Node *curr = head;

    while (curr || !isEmpty(&p)) {
        while (curr) {
            push(&p, curr);
            curr = curr->esq;
        }

        curr = pop(&p);
        printf("%d ", curr->info);

        curr = curr->dir;
    }
}

void posOrdem(Node *head) {
    if (!head) return;

    Pilha p1, p2;
    init(&p1);
    init(&p2);
    push(&p1, head);

    while (!isEmpty(&p1)) {
        Node *curr = pop(&p1);
        push(&p2, curr);

        if (curr->esq) push(&p1, curr->esq);
        if (curr->dir) push(&p1, curr->dir);
    }

    while (!isEmpty(&p2)) {
        Node *curr = pop(&p2);
        printf("%d ", curr->info);
    }
}

Node *create(int data) {
    Node *nova = (Node*)malloc(sizeof(Node));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = data;
    return nova;
}

int main() {
    Node *node = create(40), *pai = NULL;
    node->esq = create(20);
    node->dir = create(42);
    node->esq->esq = create(10);
    node->esq->dir = create(35);
    node->esq->dir->esq = create(30);
    node->dir->dir = create(52);
    node->dir->dir->esq = create(50);

    printf("Pré-ordem: ");
    preOrdem(node);
    printf("\n");

    printf("In-ordem: ");
    inOrdem(node);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(node);
    printf("\n");

    free(node->esq->esq->esq);
    free(node->esq->esq);
    free(node->esq->dir);
    free(node->esq);
    free(node->dir);
    free(node);

    return 0;
}
