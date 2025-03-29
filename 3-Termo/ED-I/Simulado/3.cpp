#include <stdio.h>
#include <stdlib.h>
#include "tadpilhas.h"
char is_stack(TpPilha p, TpPilha pV1){
    TpPilha pAux;
    inicializar(pAux);
    char flag=1;
    while(!vazia(p) || !vazia(pAux) || !vazia(pV1) && flag){
        if(!vazia(p)){printf("   p: ");exibir(p);}
        printf("\n");
        if(!vazia(pAux)){printf("pAux: ");exibir(pAux);}
        printf("\n");
        if(!vazia(p) && elementoTopo(p) == elementoTopo(pV1)){
            pop(p);
            pop(pV1);
        }
        else if(!vazia(pAux) && elementoTopo(pAux) == elementoTopo(pV1)){
            pop(pAux);
            pop(pV1);
        }
        else if(!vazia(p) && elementoTopo(p) != elementoTopo(pV1)){
            push(pAux, elementoTopo(p));
            pop(p);
        }
        else flag = 0;
    }
    return flag;
}
int main(){
    TpPilha p, pV1, pV2;
    inicializar(p);
    inicializar(pV1);
    inicializar(pV2);
    int v1[] = {3, 2, 5, 6, 4, 1};
    int v2[] = {1, 5, 4, 6, 2, 3};
    int sizeV1 = sizeof(v1)/sizeof(int);
    int sizeV2 = sizeof(v2)/sizeof(int);
    for(int i=sizeV1-1;i>=0;i--){
        push(pV1, v1[i]);
        push(pV2, v2[i]);
        push(p, i+1);
    }
    printf("%s\n", (is_stack(p, pV1) ? "yes\n" : "no\n"));
    return 0;
}
