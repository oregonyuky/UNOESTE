#include <stdio.h>
#define TF 3
int main(){
    int aux[TF][TF], vet[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            aux[i][j]=1;
            while(vet[i][j]>0){
                aux[i][j] *= vet[i][j];
                vet[i][j]--;
            }
        }
    }
    printf("\n");
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
    return 0;
}