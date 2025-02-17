#include <stdio.h>
#define TL 4
int main(){
    int i, vet[TL], vet2[TL], vUniao[2*TL], pos, TLU=0;
    for(i=0;i<TL;i++){
        printf("Digite o %do.vet1:\n",i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0;i<TL;i++){
        printf("Digite o %do.vet2:\n", i+1);
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<TL;i++){
        pos=0;
        while(pos<TLU && vet[i]!=vUniao[pos])
            pos++;
        if(pos==TLU){
            vUniao[TLU] = vet[i];
            TLU++;
        }
    }
    pos=0;
    for(i=0;i<TL;i++){
        pos=0;
        while(pos<TLU && vet2[i]!=vUniao[pos])
            pos++;
            if(pos==TLU){
                vUniao[TLU] = vet2[i];
                TLU++;
            }
    }
    for(i=0;i<TLU;i++){
        printf("%d ", vUniao[i]);
    }
    return 0;
}
