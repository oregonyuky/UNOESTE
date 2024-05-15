#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], vet2[TF], pos, vIntersec[TF], TLI=0;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero do vet:\n", i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero do vet2:\n",i+1);
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<TF;i++){
        pos=0;
        while(pos<TF && vet[i]!=vet2[pos])
            pos++;
        if(pos<TF){
            pos=0;
            while(pos<TLI && vet[i]!=vIntersec[pos])
                pos++;
            if(pos==TLI){
                vIntersec[TLI] = vet[i];
                TLI++;
            }
        }
        
    }
    for(i=0;i<TLI;i++){
        printf("%d ", vIntersec[i]);
    }
    return 0;
}
