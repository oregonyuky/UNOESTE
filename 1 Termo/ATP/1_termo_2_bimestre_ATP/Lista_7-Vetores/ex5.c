#include <stdio.h>
#define TF 10
int main(){
    int i, soma, vet[TF], vet2[TF];
    for(i=0;i<TF;i++){
        printf("digite a quantidade de pecas do vendedor %d\n", i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0;i<TF;i++){
        printf("digite o preco de cada peca do vendedor %d\n" ,i+1);
        scanf("%d", &vet2[i]);
    }
    soma=0;
    for(i=0;i<TF;i++){
        soma += vet[i];
    }
    printf("\nquantidade de pecas vendidas por todos os vendedores:%d\n", soma);
    for(i=0;i<TF;i++){
        printf("valor tota da venda do vendedor %d foi R$ %d\n", i+1, vet[i]*vet2[i]);
    }
    return 0;
}