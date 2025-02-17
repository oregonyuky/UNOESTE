#include <stdio.h>
#define n 3
#define m 3
int main(){
    float vet[n][m], vet1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%f", &vet[i][j]);
            vet1[i][j] = vet[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vet[i][j] /= vet1[i][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.2f ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}