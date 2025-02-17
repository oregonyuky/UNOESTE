#include <stdio.h>
int main(){
    int i, pares, impares, vet[6];
    pares=0;
    impares=0;
    for(i=0;i<6;i++){
        scanf("%d", &vet[i]);
        if(vet[i]%2==0)
            pares++;
        else
            impares++;
    }
    printf("A quantidade de numero pares: %d\n", pares);
    printf("A quantidade de numeros impares: %d\n", impares);
    return 0;
}