#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXFILA 12
struct TpFila{
    int FILA[100]; // Capacidade da fila
    int fim, prioridade;
};
void inicializar(TpFila &q){
    q.fim = -1;
}
void inserir(TpFila &q, int value){
    q.FILA[++q.fim] = value;
} 
int retirar(TpFila &q){
    char elem = q.FILA[0];
    for(int i=0;i<q.fim;i++){
        q.FILA[i] = q.FILA[i+1];
    }
    q.fim--;
    return elem;
}
char vazia(int fim){
    return fim == -1;
}
void exibir(TpFila q) { 
    for(int i=0;i<q.fim;i++){
        printf("%d ", q.FILA[i]);
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

    TpFila runways[4];
    for (int i = 0; i < 4; i++) {
        inicializar(runways[i]); 
    }
    FILE* airportQueries = fopen("airport.txt", "r");
    int id, pista;
    while (fscanf(airportQueries, "%d,%d", &id, &pista) == 2) { 
        inserir(runways[pista - 1], id); 
    }
    fclose(airportQueries);
    puts("--- AEROPORTO ---");
    for (int i = 0; i < 4; i++) {
        printf("Pista %d:\n", i + 1);
        exibir(runways[i]); 
    }

    return 0;
}

