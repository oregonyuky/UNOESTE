#include <stdio.h>
int main(){
    int i, j, soma, vet[9];
    for(i=1;i<=9;i++){
        scanf("%d", &vet[i]);
    }
    for(i=1;i<=9;i++){
        soma=0;
        for(j=1;j<=vet[i];j++){
            if(vet[i]%j==0)soma++;
        }
        if(soma==2){
            printf("O numero primo %d esta na posicao %d\n", vet[i], i);
        }
    }
    return 0;
}