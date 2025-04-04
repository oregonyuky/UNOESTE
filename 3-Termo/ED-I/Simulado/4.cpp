#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX 100
#define TEMPO 1

struct Tarefa{
    int id, pri, dur, restante, chegada;
    char nome[50];
};

struct Fila{
    Tarefa itens[MAX];
    int ini, fim, tam;
};

void initFila(Fila &f) { f.ini = 0; f.fim = -1; f.tam = 0; }
bool filaVazia(Fila f) { return f.tam == 0; }
bool filaCheia(Fila f) { return f.tam == MAX; }

void inserir(Fila &f, Tarefa t) {
    if (filaCheia(f)) return;
    int pos = f.fim;
    while (pos >= f.ini && t.pri > f.itens[pos].pri) {
        f.itens[(pos + 1) % MAX] = f.itens[pos];
        pos--;
    }
    f.itens[(pos + 1) % MAX] = t;
    f.fim = (f.fim + 1) % MAX;
    f.tam++;
}

Tarefa remover(Fila *f) {
    Tarefa t = f.itens[f.ini];
    f.ini = (f.ini + 1) % MAX;
    f.tam--;
    return t;
}

void simular(const char *arquivo) {
    FILE *arq = fopen(arquivo, "r");
    if (!arq) return;

    Fila fila;
    initFila(&fila);
    int tempo = 0, proxChegada = 0, total = 0, esperaTotal = 0;
    bool exec = false, fimArq = false;
    Tarefa atual = {0};

    while (!fimArq || !filaVazia(&fila) || exec) {
        printf("\n[Tempo: %d] ", tempo);

        if (tempo == proxChegada && !fimArq) {
            Tarefa nova;
            if (fscanf(arq, "%d %49s %d %d", &nova.id, nova.nome, &nova.pri, &nova.dur) == 4) {
                nova.restante = nova.dur;
                nova.chegada = tempo;
                inserir(&fila, nova);
                printf("Nova: %d (%s)", nova.id, nova.nome);
                proxChegada = tempo + 3;
            } else fimArq = true;
        }

        if (!exec && !filaVazia(&fila)) {
            atual = remover(&fila);
            exec = true;
            esperaTotal += tempo - atual.chegada;
            total++;
            printf(" Iniciando: %d (%s), P%d, D%d", atual.id, atual.nome, atual.pri, atual.dur);
        }

        if (exec) {
            printf(" Executando: %d (%s) - %d/%d", atual.id, atual.nome, atual.dur - atual.restante + 1, atual.dur);
            atual.restante--;
            if (atual.restante == 0) { printf(" [Concluído]"); exec = false; }
            else if (!filaVazia(&fila) && fila.itens[fila.ini].pri > atual.pri) {
                printf(" [Preemptado]"); inserir(&fila, atual); exec = false;
            }
        }

        sleep(TEMPO);
        tempo++;
    }

    printf("\n\n=== RELATÓRIO ===\n");
    printf("Tempo total: %d unidades\n", tempo);
    printf("Processados: %d\n", total);
    if (total) printf("Espera média: %.2f unidades\n", (double)esperaTotal / total);
    fclose(arq);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo>", argv[0]);
        return 1;
    }
    simular(argv[1]);
    return 0;
}

