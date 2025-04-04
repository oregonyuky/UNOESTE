#ifndef TADFILAPRIORIDADE_H
#define TADFILAPRIORIDADE_H

#define MAXFILA 10

struct tpCham { 
    int prioridade;
    char id[40];
    char nome[40];
    int duracao;
    int tempoC;
};

struct tpFilaP {
    int FIM;
    tpCham FILA[MAXFILA];
};

void inicializar(tpFilaP &F);
void inserir(tpFilaP &F, tpCham elem);
tpCham retirar(tpFilaP &F);
bool vazia(int FIM);
bool cheia(int FIM);
tpCham elemInicio(tpFilaP F);
tpCham elemFim(tpFilaP F);
void exibir(tpFilaP F);

void inicializar(tpFilaP &F) {
    F.FIM = -1;	
}

void inserir(tpFilaP &F, tpCham elem) {
    if(cheia(F.FIM)) return;
    
    int pos = F.FIM + 1;
    // Find the correct position based on priority (higher priority first)
    while(pos > 0 && elem.prioridade > F.FILA[pos-1].prioridade) {
        F.FILA[pos] = F.FILA[pos-1];
        pos--;
    }
    F.FILA[pos] = elem;
    F.FIM++;
}

tpCham retirar(tpFilaP &F) {
    if(vazia(F.FIM)) {
        tpCham vazio = {0};
        return vazio;
    }
    
    tpCham retirado = F.FILA[0];
    for(int i = 0; i < F.FIM; i++) {
        F.FILA[i] = F.FILA[i+1];
    }
    F.FIM--;
    return retirado;
}

bool vazia(int FIM) {
    return FIM == -1;
}

bool cheia(int FIM) {
    return FIM == MAXFILA-1;
}

tpCham elemInicio(tpFilaP F) {
    if(vazia(F.FIM)) {
        tpCham vazio = {0};
        return vazio;
    }
    return F.FILA[0];
}

tpCham elemFim(tpFilaP F) {
    if(vazia(F.FIM)) {
        tpCham vazio = {0};
        return vazio;
    }
    return F.FILA[F.FIM];
}

void exibir(tpFilaP F) {
    while(!vazia(F.FIM)) {
        tpCham aux = retirar(F);
        printf("Prioridade: %d, ID: %s, Nome: %s, Duração: %d, Tempo Chegada: %d\n", 
               aux.prioridade, aux.id, aux.nome, aux.duracao, aux.tempoC);
    }
}

#endif
