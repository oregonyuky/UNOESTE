#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idUsuario;
    char nome[50];
    char prioridade[50];
    int duracao;
    int tempoChegada;
} Transacao;

typedef struct Nodo {
    Transacao transacao;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *inicio, *fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = fila->fim = NULL;
}

int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, Transacao transacao) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->transacao = transacao;
    novo->prox = NULL;
    if (filaVazia(fila)) {
        fila->inicio = fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

Transacao desenfileirar(Fila *fila) {
    Nodo *temp = fila->inicio;
    Transacao transacao = temp->transacao;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return transacao;
}

void simulacao(const char *arquivoEntrada, int duracaoTotal) {
    FILE *Arq = fopen(arquivoEntrada, "r");
    if (!Arq) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    Fila fila;
    inicializarFila(&fila);
    Transacao transacaoAtual;
    int ocupado = 0;
    int tempo = 0, tempoEsperaTotal = 0, totalTransacoes = 0;
    char linha[100];
    
    while (tempo < duracaoTotal) {
        if (tempo % 3 == 0) {
            Transacao nova;
            if (fgets(linha, sizeof(linha), Arq)) {
                sscanf(linha, "%d %s %s %d", &nova.idUsuario, nova.nome, nova.prioridade, &nova.duracao);
                nova.tempoChegada = tempo;
                enfileirar(&fila, nova);
                printf("Tempo [%d]: Nova transacao %s (%s) do usuario %d adicionada\n", tempo, nova.nome, nova.prioridade, nova.idUsuario);
            }
        }

        if (!ocupado && !filaVazia(&fila)) {
            transacaoAtual = desenfileirar(&fila);
            ocupado = 1;
            tempoEsperaTotal += tempo - transacaoAtual.tempoChegada;
            totalTransacoes++;
            printf("Tempo [%d]: Iniciando transacao %s (%s) do usuario %d\n", tempo, transacaoAtual.nome, transacaoAtual.prioridade, transacaoAtual.idUsuario);
        }

        if (ocupado) {
            transacaoAtual.duracao--;
            if (transacaoAtual.duracao == 0) {
                ocupado = 0;
                printf("Tempo [%d]: Finalizando transacao %s (%s) do usuario %d\n", tempo, transacaoAtual.nome, transacaoAtual.prioridade, transacaoAtual.idUsuario);
            }
        }
        
        tempo++;
    }
    
    fclose(Arq);
    float mediaEspera = totalTransacoes > 0 ? (float)tempoEsperaTotal / totalTransacoes : 0;
    printf("Tempo medio de espera: %.2f unidades de tempo.\n", mediaEspera);
}

int main() {
    simulacao("entrada.txt", 50); // Nome do arquivo de entrada e duração total
    return 0;
}

