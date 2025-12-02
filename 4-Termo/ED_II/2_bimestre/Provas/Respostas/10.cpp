#include <string.h>
#include "Fila10.h"
typedef struct dados{
    int codigo;
    char nome[50];
    char endereco[50];
    char bairro[50];
    char estado[50];
    char cidade[50];
} Dados;
typedef struct estados{
    char estado[50];
    estados *prox;
    Cidades *prim;
} Estados;
void jaInserir(){
    FILE *file = fopen("dados.dat", "wb");
    if(!file)perror("Deu erro");
    Dados d[9] = {
        {1011, "Ana", "Rua Ribeiro de Barros, 200", "Centro", "Sao Paulo", "Presidente Prudente"},  // [0]
        {1255, "Carlos", "Rua das Palmeiras, 150", "Cohab", "Sao Paulo", "Presidente Prudente"},  // [1]
        {1144, "Patricia", "Rua dos Patos, 33", "Centro", "Sao Paulo", "Pirapozinho"},         // [2]
        {1335, "Rita", "Rua dos Lagos, 60", "Vila Jequitibas", "Sao Paulo", "Presidente Prudente"}, // [3]
        {2266, "Fabio", "Rua Antonia, 10", "Via Maria", "Sao Paulo", "Assis"},                // [4]
        {2299, "Clebio", "Rua dos Lagos, 55", "Bairro Cedro", "Parana", "Apucarana"},         // [5]
        {7766, "Adriana", "Rua Presidente, 45", "Vila Jesus", "Parana", "Guaraci"},           // [6]
        {1879, "Lucilla", "Av. Sao Paulo, 88", "Centro", "Sao Paulo", "Assis"},               // [7]
        {8879, "Juacema", "Rua XV de Novembro, 99", "Bairro das Mamonas", "Parana", "Apucarana"} // [8]
    };
    fwrite(d, sizeof(Dados), 9, file);
    fclose(file);
}
Estados *cria(char estado[50]){
    Estados *e = (Estados*)malloc(sizeof(Estados));
    strcpy(e->estado, estado);
    e->prim = NULL;
    e->prox = NULL;
    return e;
}
void criarEstado(Estados **e, char estado[50]){
    // Se lista vazia
    if(!*e) {
        *e = cria(estado);
        return;
    }
    Estados *aux = *e;
    Estados *ant = NULL;
    while(aux && strcmp(aux->estado, estado) < 0){
        ant = aux;
        aux = aux->prox;
    }
    if(aux && strcmp(aux->estado, estado) == 0){
        return;
    }
    Estados *novo = cria(estado);
    if(!ant){
        novo->prox = *e;
        *e = novo;
    }
    else{
        novo->prox = aux;
        ant->prox = novo;
    }
}
Estados *busca(Estados *e, char estado[50]){
    Estados *aux = e;
    while(aux){
        if(strcmp(aux->estado, estado) == 0){
            return aux;  // Encontrou, retorna o nó
        }
        aux = aux->prox;
    }
    return NULL;  // Não encontrou
}
void construirDinamica(Estados **e){
    FILE *file = fopen("dados.dat", "rb");
    if(!file)perror("Deu erro");
    Dados d;
    int contador=0;
    while(fread(&d, sizeof(Dados), 1, file)==1){
        Estados *existente = busca(*e, d.estado);
        if(!existente) {
            criarEstado(&*e, d.estado);
        }
        contador++;
    }
    fclose(file);
}
Cidades *criaAVL(char cidade[50]){
    Cidades *c = (Cidades*)malloc(sizeof(Cidades));
    strcpy(c->cidade, cidade);
    c->esq = c->dir = NULL;
    c->prim = NULL;
    return c;
}
void altura(Cidades *c, int *alt){
    if(c){
        int he = 0, hd = 0;
        altura(c->esq, &he);
        altura(c->dir, &hd);
        int maior = he;
        if(hd > he)maior = hd;
        *alt = maior + 1;
    }
}
void rotacaoLL(Cidades **c){
    Cidades *p = *c;
    Cidades *q = p->dir;
    p->dir = q->esq;
    q->esq = p;
    *c = q;
}
void rotacaoRR(Cidades **c){
    Cidades *p = *c;
    Cidades *q = p->esq;
    p->esq = q->dir;
    q->dir = p;
    *c = q;
}
void inserirAVLIterativo(Cidades **c, char cidade[50]){
    PilhaP *p = NULL;
    initPP(&p);
    if (!*c) {
        *c = criaAVL(cidade);
        free(p);
        return;
    }
    Cidades *at = *c;
    Cidades *pai = NULL;
    while (at){
        pushPP(&p, at);
        if (strcmp(cidade, at->cidade) == 0){
            free(p);
            return;                 // CIDADE JÁ EXISTE → NÃO FAZ NADA
        }
        pai = at;
        if (strcmp(cidade, at->cidade) < 0)
            at = at->esq;
        else
            at = at->dir;
    }
    Cidades *novo = criaAVL(cidade);
    if (strcmp(cidade, pai->cidade) < 0)
        pai->esq = novo;
    else
        pai->dir = novo;

    int fez_rotacao = 0;
    while (!isEmptyPP(p) && !fez_rotacao) {
        popPP(&p, &at);

        int h_dir = 0, h_esq = 0;
        if(at->dir)altura(at->dir, &h_dir);
        if(at->esq)altura(at->esq, &h_esq);
        int fb = h_dir - h_esq;

        if (fb == 2 || fb == -2) {
            fez_rotacao = 1;

            if (fb == 2) {
                int fd = 0, fe = 0;
                if(at->dir->dir)altura(at->dir->dir, &fd);
                if(at->dir->esq)altura(at->dir->esq, &fe);
                int fbf = fd - fe;
                if (fbf==1)
                    rotacaoLL(&at);
                else {
                    rotacaoRR(&at->dir);
                    rotacaoLL(&at);
                }
            } else {
                int fd = 0, fe = 0;
                if(at->esq->dir)altura(at->esq->dir, &fd);
                if(at->esq->esq)altura(at->esq->esq, &fe);
                int fbf = fd - fe;
                if (fbf==1)
                    rotacaoRR(&at);
                else {
                    rotacaoLL(&at->esq);
                    rotacaoRR(&at);
                }
            }
        }

        if (!isEmptyPP(p)) {
            Cidades *pai_atual;
            popPP(&p, &pai_atual);
            if (pai_atual->esq == at) pai_atual->esq = at;
            else pai_atual->dir = at;
            pushPP(&p, pai_atual);
        } else {
            *c = at;
        }
    }
    free(p);
}
void construirAVLIterativo(Estados **e){
    FILE *file = fopen("dados.dat", "r+b");
    Dados d;
    while(fread(&d, sizeof(Dados), 1, file)==1){
        Estados *ee = busca(*e, d.estado);
        if(ee)
            inserirAVLIterativo(&ee->prim, d.cidade);
    }
    fclose(file);
}
void imprimirAVL(Cidades *fu){
    PilhaP *p;
    Cidades *aux, *curr = fu;
    initPP(&p);
    pushPP(&p, fu);
    while(curr || !isEmptyPP(p)){
        while(curr){
            pushPP(&p, curr);
            curr = curr->esq;
        }
        popPP(&p, &curr);
        printf("%s ", curr->cidade);
        curr = curr->dir;
    }
}
void imprimirEstado(Estados *e){
    Estados *aux = e;
    while(aux){
        printf("%s - ", aux->estado);
        Cidades *c = aux->prim;
        if(c)
            imprimirAVL(c);
        puts("");
        aux = aux->prox;
    }
}
int main(){
    jaInserir();
    Estados *e = NULL;
    construirDinamica(&e);
    construirAVLIterativo(&e);
    imprimirEstado(e);
}
