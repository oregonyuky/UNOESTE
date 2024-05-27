#include <stdio.h>
#define M 3
int main(){
    int vet[M][M], vet1[M][M], vet2[M][M], vet3[M][M], soma[M][M],
    multi[M][M], quatro[M][M];
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            vet2[i][j] = vet1[j][i];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            vet3[i][j] = vet[j][i];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            soma[i][j] = vet[i][j] + vet2[i][j];
            multi[i][j] = vet1[i][j] * vet3[i][j];
            quatro[i][j] = vet2[i][j] + vet3[i][j]*4;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%d ", quatro[i][j]);
        }
        printf("\n");
    }
    return 0;
}