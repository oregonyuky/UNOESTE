#include <stdio.h>
#define TF 4
int main(){
    int vet1[TF], vet2[TF], vet3[TF*2], i, j, TL1=0, TL2=0, TL3=0, num, pos, num1;
    printf("Digite o %do.numero do vet1:\n", TL1+1);
    scanf("%d", &num);
    while(TL1<TF && num>0){
        pos=0;
        while(pos<TL1 && num>vet1[pos])
            pos++;
        for(i=TL1;i>pos;i--){
            vet1[i] = vet1[i-1];
        }
        vet1[pos] = num;
        TL1++;
        if(TL1<TF){
            printf("Digite o %do.numero do vet1:\n", TL1+1);
            scanf("%d", &num);
        }
    }
     pos=0;
    printf("Digite o %d.numero do vet2:\n", TL2+1);
    scanf("%d", &num1);
    while(TL2<TF && num1>0){
        pos=0;
        while(pos<TL2 && num1>vet2[pos])
            pos++;
        for(i=TL2;i>pos;i--){
            vet2[i] = vet2[i-1];
        }
        vet2[pos] = num1;
        TL2++;
        if(TL2<TF){
            printf("Digite o %d.numero do vet2:\n", TL2+1);
            scanf("%d", &num1);
        }
    }
    i=0;
    j=0;
    while(i<TL1 && j<TL2){
        if(vet1[i] < vet2[j]){
            vet3[TL3] = vet1[i];
            TL3++;
            i++;
        }
        else{
            vet3[TL3] = vet2[j];
            TL3++;
            j++;
        }
    }
    while(i<TL1){
        vet3[TL3] = vet1[i];
        TL3++;
        i++;
    }
    while(j<TL2){
        vet3[TL3] = vet2[j];
        TL3++;
        j++;
    }
    for(i=0;i<TL3;i++){
        printf("%d", vet3[i]);
    }
    return 0;
}
