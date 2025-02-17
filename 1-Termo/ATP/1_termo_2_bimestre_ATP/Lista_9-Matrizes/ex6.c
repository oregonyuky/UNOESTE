#include <stdio.h>
#define TF 3
int main(){
    int vet[TF][TF], maior, menor, pos[TF], posl[TF], k=0;
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    maior = menor = vet[0][0];
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            if(maior < vet[i][j]){
                maior = vet[i][j];
                
            }
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<TF;j++){
            if(vet[i][j]==maior){
                pos[k] = i;
                posl[k] = j;
                k++;
            }
        }
    }
    printf("maior numero eh %d\n", maior);
    for(int i=0;i<k;i++)
        printf("na linha[%d] coluna[%d]\n", pos[i], posl[i]);
    return 0;
}