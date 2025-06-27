#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item {
    char nome[30];
    float preco;
    struct Item *ant, *prox;
};

struct Cliente {
    char nome[30];
    float total;
    struct Item *InicioItem, *FimItem;
    struct Cliente *ant, *prox;
};

struct Caixa {
    char atendente[30];
    struct Cliente *InicioCli, *FimCli;
    struct Caixa *ant, *prox;
};

struct Descritor {
    struct Caixa *Inicio, *Fim;
    int qtd;
};

// ---------------------------- Funções Auxiliares ----------------------------

struct Caixa* novaCaixa(const char *nome) {
    struct Caixa *c = (struct Caixa*)malloc(sizeof(struct Caixa));
    strcpy(c->atendente, nome);
    c->InicioCli = c->FimCli = NULL;
    c->ant = c->prox = NULL;
    return c;
}

struct Cliente* novoCliente(const char *nome) {
    struct Cliente *cli = (struct Cliente*)malloc(sizeof(struct Cliente));
    strcpy(cli->nome, nome);
    cli->total = 0;
    cli->InicioItem = cli->FimItem = NULL;
    cli->ant = cli->prox = NULL;
    return cli;
}

struct Item* novoItem(const char *nome, float preco) {
    struct Item *item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(item->nome, nome);
    item->preco = preco;
    item->ant = item->prox = NULL;
    return item;
}

void inicializar(Descritor *d) {
    d->Inicio = d->Fim = NULL;
    d->qtd = 0;
}

// ---------------------- Inserção Ordenada de Caixa ----------------------

void inserirCaixa(Descritor *d, const char *nome) {
    struct Caixa *novo = novaCaixa(nome);
    if (d->qtd == 0) {
        d->Inicio = d->Fim = novo;
    } else if (strcmp(nome, d->Inicio->atendente) < 0) {
        novo->prox = d->Inicio;
        d->Inicio->ant = novo;
        d->Inicio = novo;
    } else if (strcmp(nome, d->Fim->atendente) > 0) {
        d->Fim->prox = novo;
        novo->ant = d->Fim;
        d->Fim = novo;
    } else {
        struct Caixa *p = d->Inicio;
        while (p && strcmp(p->atendente, nome) < 0)
            p = p->prox;
        novo->prox = p;
        novo->ant = p->ant;
        p->ant->prox = novo;
        p->ant = novo;
    }
    d->qtd++;
}

// ---------------------- Buscar Caixa ----------------------

struct Caixa* buscarCaixa(Descritor d, const char *nome) {
    struct Caixa *p = d.Inicio;
    while (p) {
        if (strcmp(p->atendente, nome) == 0)
            return p;
        p = p->prox;
    }
    return NULL;
}

// ---------------------- Inserir Cliente na Fila ----------------------

void inserirCliente(struct Caixa *c, const char *nomeCli) {
    struct Cliente *novo = novoCliente(nomeCli);
    if (!c->InicioCli) {
        c->InicioCli = c->FimCli = novo;
    } else {
        c->FimCli->prox = novo;
        novo->ant = c->FimCli;
        c->FimCli = novo;
    }
}

// ---------------------- Inserir Item no Cliente ----------------------

void inserirItem(struct Cliente *cli, const char *nomeItem, float preco) {
    struct Item *novo = novoItem(nomeItem, preco);
    if (!cli->InicioItem) {
        cli->InicioItem = cli->FimItem = novo;
    } else {
        cli->FimItem->prox = novo;
        novo->ant = cli->FimItem;
        cli->FimItem = novo;
    }
}

// ---------------------- Listar Itens Recursivamente ----------------------

float listarItens(struct Item *i) {
    if (!i) return 0;
    printf("  - %s (R$%.2f)\n", i->nome, i->preco);
    return i->preco + listarItens(i->prox);
}

// ---------------------- Finalizar Compra do Primeiro Cliente ----------------------

void finalizarCompra(struct Caixa *c) {
    if (!c || !c->InicioCli) return;
    struct Cliente *cli = c->InicioCli;
    printf("Finalizando compra de: %s\n", cli->nome);
    cli->total = listarItens(cli->InicioItem);
    printf("Total: R$%.2f\n", cli->total);

    // Libera os itens
    while (cli->InicioItem) {
        struct Item *tmp = cli->InicioItem;
        cli->InicioItem = cli->InicioItem->prox;
        free(tmp);
    }
}

// ---------------------- Fechar Caixa ----------------------

void fecharCaixa(Descritor *d, const char *nome) {
    struct Caixa *c = buscarCaixa(*d, nome);
    if (!c) return;

    printf("\nFechando caixa de %s:\n", c->atendente);
    struct Cliente *cli = c->InicioCli;
    while (cli) {
        printf("Cliente: %s - Total: R$%.2f\n", cli->nome, cli->total);
        struct Cliente *tmp = cli;
        cli = cli->prox;
        free(tmp);
    }

    if (c->ant) c->ant->prox = c->prox;
    else d->Inicio = c->prox;
    if (c->prox) c->prox->ant = c->ant;
    else d->Fim = c->ant;

    free(c);
    d->qtd--;
}

// ---------------------- Main ----------------------

int main() {
    Descritor d;
    inicializar(&d);

    inserirCaixa(&d, "Carlos");
    inserirCaixa(&d, "Amanda");
    inserirCaixa(&d, "Bruno");

    struct Caixa *caixaAmanda = buscarCaixa(d, "Amanda");
    inserirCliente(caixaAmanda, "Joao");

    struct Cliente *cli = caixaAmanda->InicioCli;
    inserirItem(cli, "Arroz", 20);
    inserirItem(cli, "Feijao", 10);
    inserirItem(cli, "Macarrao", 5);

    finalizarCompra(caixaAmanda);

    fecharCaixa(&d, "Amanda");

    return 0;
}

