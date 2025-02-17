#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], vet2[TF], j=0, pos=0, TLU=0;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n", i+1);
        scanf("%d", &vet[i]);
    }
    int a = TF-1;
    for(i=0;i<TF;i++){
        if(vet[i]<0){
            vet2[TLU] = vet[i];
            TLU++;
        }
        else{
            vet2[a] = vet[i];
            a--;
        }
    }

    for(i=0;i<TF;i++){
        printf("%d ", vet2[i]);
    }
    return 0;
}