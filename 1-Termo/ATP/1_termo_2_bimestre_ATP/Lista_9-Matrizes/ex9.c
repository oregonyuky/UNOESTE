#include <stdio.h>
#define TF 3
int main(){
    int vet[TF][TF], vet1[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            vet[i][j] -= vet1[i][j];
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}