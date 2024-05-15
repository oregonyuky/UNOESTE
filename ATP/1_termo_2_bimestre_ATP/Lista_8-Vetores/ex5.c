#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], elem;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n",i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o elemento:\n");
    scanf("%d", &elem);
    for(i=0;i<TF;i++){
        if(vet[i]==elem)vet[i] = vet[i+1];
    }
    for(i=0;i<TF-1;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

