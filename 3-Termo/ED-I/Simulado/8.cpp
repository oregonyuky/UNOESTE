#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXFILA 12
struct TpElemento{
    int id;
    int prioridade;
};
struct TpFilaP{
    TpElemento FILA[MAXFILA]; // Capacidade da fila
    int fim;
};
void inicializar(TpFilaP &q){
    q.fim = -1;
}
void inserir(TpFilaP &q, TpElemento elem){
    q.FILA[++q.fim] = elem;
    int i = q.fim;
    while(i>0 && q.FILA[i].prioridade < q.FILA[i-1].prioridade){
        TpElemento aux = q.FILA[i];
        q.FILA[i] = q.FILA[i-1];
        q.FILA[i-1] = aux;
        i--;
    }
}
TpElemento retirar(TpFilaP &q){
    TpElemento elem = q.FILA[0];
    for(int i=0;i<q.fim;i++){
        q.FILA[i] = q.FILA[i+1];
    }
    q.fim--;
    return elem;
}
char vazia(int fim){
    return fim == -1;
}
void exibir(TpFilaP q) { 
    TpElemento R;
    int num=-1;
    while(!vazia(q.fim)){
        R = retirar(q);
        if(num != R.prioridade){
            printf("\nPista: %d\n", R.prioridade);
            num = R.prioridade;
        }
            printf("%d ", R.id);
    }
       printf("\n");
}

int main() {
    srand(time(NULL));
    FILE* airportFile = fopen("airport.txt", "w");
    for (int i = 0; i < 10; i++) {
        int pista = rand() % 4 + 1; 
        fprintf(airportFile, "%d,%d\n", i + 1, pista); 
    }
    fclose(airportFile);

    TpFilaP runways;
    inicializar(runways); 
    FILE* airportQueries = fopen("airport.txt", "r");
    TpElemento R;
    while (fscanf(airportQueries, "%d,%d", &R.id, &R.prioridade) != EOF) { 
        inserir(runways, R);
    }
    fclose(airportQueries);
    puts("--- AEROPORTO ---");
    exibir(runways);

    return 0;
}


