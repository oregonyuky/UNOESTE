#include <stdio.h>
#include <string.h>
#define MAXPILHA 10

struct TpDados {
    char nome[30];
    int prioridade;
};

struct TpPilha {
    int topo;
    TpDados PILHA[MAXPILHA];
};

void inicializar(TpPilha &p) {
    p.topo = -1;
}

void push(TpPilha &p, TpDados elem) {
    p.PILHA[++p.topo] = elem;
}

TpDados pop(TpPilha &p) {
    return p.PILHA[p.topo--];
}

bool vazia(TpPilha p) {
    return p.topo == -1;
}

TpDados elementoTopo(TpPilha p) {
    return p.PILHA[p.topo];
}

struct TpFilaP {
    TpPilha p1;
    TpPilha p2;
};

void inicializarFilaP(TpFilaP &f) {
    inicializar(f.p1);
    inicializar(f.p2);
}

void inserirFilaP(TpFilaP &f, TpDados elem) {
    while (!vazia(f.p1) && elementoTopo(f.p1).prioridade > elem.prioridade) {
        push(f.p2, pop(f.p1));
    }
    push(f.p1, elem);
    while (!vazia(f.p2)) {
        push(f.p1, pop(f.p2));
    }
}
TpDados popFilaP(TpFilaP &f) {
    return pop(f.p1);
}

TpDados elementoInicio(TpFilaP f){
    return elementoTopo(f.p1);
}

TpDados elementoFim(TpFilaP f){
    while(!vazia(f.p1)){
        push(f.p2, pop(f.p1));
    }
    return elementoTopo(f.p2);
}
int main() {
    TpFilaP fila;
    inicializarFilaP(fila);

    TpDados pessoa1 = {"Ana", 1};
    TpDados pessoa2 = {"Bruno", 0};
    TpDados pessoa3 = {"Carlos", 2};
    TpDados pessoa4 = {"Diana", 1};

    inserirFilaP(fila, pessoa1);
    inserirFilaP(fila, pessoa2);
    inserirFilaP(fila, pessoa3);
    inserirFilaP(fila, pessoa4);

    TpDados d = elementoInicio(fila);
    TpDados u = elementoFim(fila);
    printf("\nelemento inicio: %s (Prioridade %d)\n", d.nome, d.prioridade);
    printf("elemento fim: %s (Prioridade %d)\n\n", u.nome, u.prioridade);

    printf("Removendo da fila de prioridade:\n");
    while (!vazia(fila.p1)) {
        TpDados removido = popFilaP(fila);
        printf("%s (Prioridade %d)\n", removido.nome, removido.prioridade);
    }
    return 0;
}
