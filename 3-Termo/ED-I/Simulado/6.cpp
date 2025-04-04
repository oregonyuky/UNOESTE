#include <stdio.h>
#include <unistd.h>

#define MAX 100
#define TEMPO 1

struct Tarefa {
    int id, pri, dur, restante, chegada;
    char nome[50];
};

struct Fila {
    Tarefa FILA[MAX];
    int ini, fim, tam;
};

void initFila(Fila &f) { f.ini = 0; f.fim = -1; f.tam = 0; }
int filaVazia(Fila f) { return f.tam == 0; }
int filaCheia(Fila f) { return f.tam == MAX; }

void inserir(Fila &f, Tarefa t) {
    if (filaCheia(f)) return;
    int pos = f.fim;
    while (pos >= f.ini && t.pri > f.FILA[pos].pri) {
        f.FILA[(pos + 1) % MAX] = f.FILA[pos];
        pos--;
    }
    f.FILA[(pos + 1) % MAX] = t;
    f.fim = (f.fim + 1) % MAX;
    f.tam++;
}

Tarefa remover(Fila *f) {
    Tarefa t = f->FILA[f->ini];
    f->ini = (f->ini + 1) % MAX;
    f->tam--;
    return t;
}

void simular(const char *arquivo) {
    FILE *arq = fopen(arquivo, "r");
    if (!arq) return;

    Fila fila;
    initFila(fila);
    int tempo = 0, proxChegada = 0, total = 0, esperaTotal = 0;
    int exec = 0, fimArq = 0;
    Tarefa atual = {0};

    while (!fimArq || !filaVazia(fila) || exec) {
        printf("\n[Tempo: %d] ", tempo);

        if (tempo == proxChegada && !fimArq) {
            Tarefa nova;
            if (fscanf(arq, "%d %49s %d %d", &nova.id, nova.nome, &nova.pri, &nova.dur) == 4) {
                nova.restante = nova.dur;
                nova.chegada = tempo;
                inserir(fila, nova);
                printf("Nova: %d (%s)", nova.id, nova.nome);
                proxChegada = tempo + 3;
            } else fimArq = 1;
        }

        if (!exec && !filaVazia(fila)) {
            atual = remover(&fila);
            exec = 1;
            esperaTotal += tempo - atual.chegada;
            total++;
            printf(" Iniciando: %d (%s), P%d, D%d", atual.id, atual.nome, atual.pri, atual.dur);
        }

        if (exec) {
            printf(" Executando: %d (%s) - %d/%d", atual.id, atual.nome, atual.dur - atual.restante + 1, atual.dur);
            atual.restante--;
            if (atual.restante == 0) { printf(" [Concluído]"); exec = 0; }
            else if (!filaVazia(fila) && fila.FILA[fila.ini].pri > atual.pri) {
                printf(" [Preemptado]"); inserir(fila, atual); exec = 0;
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

