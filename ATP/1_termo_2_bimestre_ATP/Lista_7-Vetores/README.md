
<img src="https://github.com/oregonyuky/ATP/assets/152916454/6af9edb8-ea2b-4580-978a-b7dceddbef30.png" >

## Ex1
```c
#include <stdio.h>
int main(){
    int i, vet1[100], vet2[100], vet3[20];
    for(i=0;i<10;i++){
        scanf("%d", &vet1[i]);
    }
    for(i=10;i<20;i++){
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<20;i++){
        if(i<10)
            vet3[i] = vet1[i];
        else
            vet3[i] = vet2[i];
    }
    for(i=0;i<20;i++){
        printf("%d ", vet3[i]);
    }
    return 0;
}
```
## Ex2
```c
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
```
## Ex3
```c
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
```
## Ex4
```c
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
```
## Ex5
```c
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
```
## Ex6
```c
#include <stdio.h>
#define TF 10
int main(){
    int i;
    float vet[TF], vet2[TF], media[TF], media_turma, qtd, aprovados, reprovados;
    for(i=0;i<TF;i++){
        printf("Digite a nota da 1o. prova do aluno %d\n", i+1);
        scanf("%f", &vet[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite a nota da 2o. nota da prova do aluno %d\n", i+1);
        scanf("%f", &vet2[i]);
    }
    media_turma=0;
    qtd=0;
    aprovados=0;
    reprovados=0;
    for(i=0;i<TF;i++){
        media[i] = (vet[i]+vet2[i])/2.0;
        media_turma += media[i];
    }
    media_turma /= TF;
    for(i=0;i<TF;i++){
        if(media[i] < media_turma)qtd++;
        if(media[i] >= 7.0)aprovados++;
        if(media[i] < 7.0)reprovados++;
    }
    printf("\nMedia da turma: %.2f\n", media_turma);
    printf("Quantidade de alunos que obtiveram emdia menor que media geral: %.0f\n", qtd);
    printf("Quantidade de alunos aprovados, isto e, com media >= 7.0: %.0f\n", aprovados);
    printf("Quantidade de alunos reprovados, isto e, com media < 7.0: %.0f\n", reprovados);
    return 0;
}
```
## Ex7
```c
```
