#include <stdio.h>
#define TF 5
int main(){
    int a, elem, pos, vet[TF], i;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n", i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o elemento:\n");
    scanf("%d", &elem);
    printf("Digite a posicao:\n");
    scanf("%d", &pos);
    for(i=0;i<TF;i++){
        if(i==pos)vet[i] = elem;
    }
    for(i=0;i<TF;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
