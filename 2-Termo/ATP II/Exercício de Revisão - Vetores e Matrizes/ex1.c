#include <stdio.h>
#include <stdlib.h>
#define REP(a, b) for(int i=0;i<(a);i++){for(int j=0;j<(b);j++)
#define C 3
#define L 3
int main(){
    int vet[L][C], um=0, zero=0, linha, coluna;
    REP(C, L){
        scanf("%d", &vet[i][j]);
    }
    }
    REP(C, L){
        vet[i][j]==1 ? um++ : zero++;
    }
    }
    printf("Estao ocupadas: %d\nNao estao ocupadas: %d\n", um, zero);

    REP(C, L){
        printf("%d ", vet[i][j]);
    }
    puts("");
    }
    printf("Digite a linha:\n", &linha);
    scanf("%d", &linha);
    printf("Digite a coluna:\n", &coluna);
    scanf("%d", &coluna);
    vet[linha][coluna]==1 ? puts("Esta ocupada") : puts("Nao esta ocupada");
    return 0;
}
