#include <stdio.h>
#include <math.h>
#define TF 5
int main(){
    int a[TF], vet[TF][TF], aux, k=0, b[TF]; 
    for(int i=0;i<TF;i++){
        printf("digite o elemento %d:\n",i+1);
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                vet[i][j] = a[i]+5;
            }
            if(j==1){
                aux=1;
                while(a[i]>0){
                    aux*=a[i];
                    a[i]--;
                }
                vet[i][j] = aux;
            }
            if(j==2){
                vet[i][j] = b[i]*b[i];
            }
        }
    }
    for(int i=0;i<TF;i++){
        for(int j=0;j<3;j++){
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }
    return 0;
}