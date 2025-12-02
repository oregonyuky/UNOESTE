#include <stdio.h>
#include "Fila.h"
void copia_ABB(Tree *raiz1, Tree **raiz2) {
    *raiz2 = NULL;
    
    if (raiz1 == NULL) {
        return;
    }
    
    Pilha p; // Estrutura TADPilha
    initP(&p);
    push(&p, raiz1);
    Tree *atual1; // Nó da arvore de origem (raiz1)
    while (!isEmpty(&p)) {
        pop(&p, &atual1);
        Tree *novo_no = criaNo(atual1->info); 
        if (*raiz2 == NULL) {
            *raiz2 = novo_no;
        } else {
            int conectado = 0; 
            Tree *curr2 = *raiz2;
            Tree *pai2 = NULL;
            while (curr2 != NULL && !conectado) {
                pai2 = curr2;
                
                if (novo_no->info < curr2->info) {
                    curr2 = curr2->esq;
                } else {
                    curr2 = curr2->dir;
                }
            }
            if (pai2 != NULL) {
                if (novo_no->info < pai2->info) {
                    pai2->esq = novo_no;
                } else {
                    pai2->dir = novo_no;
                }
                conectado = 1; // Nó conectado com sucesso
            }
        }
        if (atual1->dir != NULL) {
            Push(&p, atual1->dir);
        }
        if (atual1->esq != NULL) {
            Push(&p, atual1->esq);
        }
    }
}