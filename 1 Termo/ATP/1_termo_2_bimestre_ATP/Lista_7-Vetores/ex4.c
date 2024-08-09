#include <stdio.h>
int main(){
    int i, vet[12], leitura=1, maior, menor;
    for(i=0;i<12;i++){
        printf("digite a temperatura do mes %d\n", i+1);
        scanf("%d", &vet[i]);
    }
    maior = vet[0];
    menor = vet[0];
    for(i=0;i<12;i++){
        if(maior < vet[i])maior = vet[i];
        if(menor > vet[i])menor = vet[i];
    }
    printf("A maior temperatura do ano foi %d\n", maior);
    printf("A menor temperatura do ano foi %d\n", menor);
    return 0;
}