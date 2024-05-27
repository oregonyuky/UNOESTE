#include <stdio.h>
#define TF 5
int main(){
    int soma=0, vet[TF][TF];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
            if(i==j)soma+=vet[i][j];
        }
    }
    printf("A soma do elemento da diagonal %d\n", soma);
    return 0;
}