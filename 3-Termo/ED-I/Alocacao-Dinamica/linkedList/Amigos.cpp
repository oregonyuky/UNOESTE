#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TpPont {
    char nome[30];
    TpPont *ant, *prox;
};
TpPont *NovaCaixa(char nome[30]) {
    TpPont *p = new TpPont;
    strcpy(p->nome, nome);
    p->prox = NULL;
    p->ant = NULL;
    return p;
}
TpPont *InserirFim(TpPont *lista, char nome[30]) {
    TpPont *NC = NovaCaixa(nome);
    if (lista == NULL) {
        return NC;
    } else {
        TpPont *aux = lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = NC;
        NC->ant = aux;
        return lista;
    }
}
TpPont *Buscar(TpPont *lista, char nome[30]) {
    while (lista != NULL && strcmp(lista->nome, nome) != 0)
        lista = lista->prox;
    return lista;
}
TpPont *InserirAntes(TpPont *lista, TpPont *destino, TpPont *novos) {
    if (destino == NULL) return lista;
    TpPont *ultimo = novos;
    while (ultimo->prox != NULL)
        ultimo = ultimo->prox;
    if (destino->ant == NULL) {
        ultimo->prox = destino;
        destino->ant = ultimo;
        return novos;
    } else {
        TpPont *anterior = destino->ant;
        anterior->prox = novos;
        novos->ant = anterior;
        ultimo->prox = destino;
        destino->ant = ultimo;
        return lista;
    }
}
TpPont *JuntarNoFim(TpPont *lista, TpPont *novos) {
    if (lista == NULL) return novos;
    if (novos == NULL) return lista;
    TpPont *aux = lista;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novos;
    novos->ant = aux;
    return lista;
}
void Exibir(TpPont *lista) {
    while (lista != NULL) {
        printf("%s", lista->nome);
        if (lista->prox != NULL) printf(" ");
        lista = lista->prox;
    }
    printf("\n");
}
int main() {
    TpPont *lista = NULL, *novos = NULL;
    char nome[30], alvo[30];

    // Leitura da primeira lista
    while (scanf("%s", nome) == 1) {
        if (getchar() == '\n') {
            lista = InserirFim(lista, nome);
            break;
        }
        lista = InserirFim(lista, nome);
    }
    while (scanf("%s", nome) == 1) {
        if (getchar() == '\n') {
            novos = InserirFim(novos, nome);
            break;
        }
        novos = InserirFim(novos, nome);
    }
    scanf("%s", alvo);
    if (strcmp(alvo, "nao") == 0) {
        lista = JuntarNoFim(lista, novos);
    } else {
        TpPont *onde = Buscar(lista, alvo);
        lista = InserirAntes(lista, onde, novos);
    }
    Exibir(lista);
    return 0;
}