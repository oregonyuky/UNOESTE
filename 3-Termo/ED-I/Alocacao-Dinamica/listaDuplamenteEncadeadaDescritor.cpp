#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TpSubPont{
    char v;
    TpSubPont *ant, *prox;
};
struct TpPont{
    char v;
    TpSubPont *Inicio, *Fim;
    TpPont *ant, *prox;
};
struct TpDesc{
    TpPont *Inicio, *Fim;
    int qtd;
};
TpPont *novaCaixa(int v){
    TpPont *aux = new TpPont;
    aux->v = v;
    aux->Inicio = aux->Fim = NULL; // ? adicionado
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}
void Inicializar(TpDesc &d){
    d.Inicio = d.Fim = NULL;
    d.qtd = 0;
}
void InserirTpPont(TpDesc &d, int v){
    TpPont *aux = novaCaixa(v);
    if (d.qtd == 0) {
        d.Inicio = d.Fim = aux;
    }
    else if (v < d.Inicio->v) {
        aux->prox = d.Inicio;
        d.Inicio->ant = aux;
        d.Inicio = aux;
    }
    else if (v > d.Fim->v) {
        d.Fim->prox = aux;
        aux->ant = d.Fim;
        d.Fim = aux;
    }
    else {
        TpPont *p = d.Inicio;
        while (p != NULL && p->v < v)
            p = p->prox;
        aux->prox = p;
        aux->ant = p->ant;
        p->ant->prox = aux;
        p->ant = aux;
    }
    d.qtd++;
}

void InserirFimTpSubPont(TpDesc &d, int v){
    TpPont *p = d.Inicio;
    TpSubPont *nc = new TpSubPont;
    nc->v = v;
    nc->ant = NULL;
    nc->prox = NULL;
    if(p->Inicio == NULL){
        p->Inicio = p->Fim = nc;
    }else{
        p->Fim->prox = nc;
        nc->ant = p->Fim;
        p->Fim = nc;
    }

}
void Exibir(TpDesc d){
    TpPont *p = d.Inicio;
    while(p){
        printf("- %d\n", p->v);
        p = p->prox;
    }
}
void ExibirSub(TpDesc d){
    if (d.Inicio == NULL) {
        printf("Lista de caixas vazia.\n");
        return;
    }
    TpSubPont *p = d.Inicio->Inicio;
    printf("Sublista da caixa %d:\n", d.Inicio->v);
    while(p){
        printf("  - %d\n", p->v);
        p = p->prox;
    }
}
int main(){
    TpDesc d;
    Inicializar(d);
    
    InserirTpPont(d, 5);   // cria uma caixa com valor 5
    InserirTpPont(d, 2);   // cria uma caixa com valor 2 (será a nova primeira)
    InserirTpPont(d, 8);   // caixa com valor 8

    // Inserir subelementos na primeira caixa (valor 2)
    InserirFimTpSubPont(d, 10);
    InserirFimTpSubPont(d, 20);

    // Exibir lista principal
    printf("Lista principal:\n");
    Exibir(d);

    // Exibir sublista da primeira caixa
    printf("\nSublista da primeira caixa:\n");
    ExibirSub(d);
}
