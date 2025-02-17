#include <stdio.h>
#define TF 4
int main(){
    int vet[TF+1], TL=0, num, elem, pos=0, i;
    printf("Digite o %do.numero\n", TL+1);
    scanf("%d", &num);
    while(TL<TF && num>0){
        vet[TL]=num;
        TL++;
        if(TL<TF){
            printf("Digite o %do.numero:\n", TL+1);
            scanf("%d", &num);
        }
    }
    printf("Digite o elemento para inserir:\n");
    scanf("%d", &elem);
    pos=0;
    while(pos<TL && vet[pos]<elem)
        pos++;
    for(i=TL;i>pos;i--){
        vet[i]=vet[i-1];
    }
    vet[pos]=elem;
    TL++;
    for(i=0;i<TL;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}