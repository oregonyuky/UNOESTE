//a) Podemos obter as sequencias [3, 2, 5, 6, 4, 1] e [1, 5, 4, 6, 2, 3] utilizando um processo semelhante ao do
// anterior?
#include <stdio.h>
#include <stdlib.h>
#include "tadpilha.h"
int main(){
    int vetor[] = {2, 4, 3, 1};
    TpPilha p, p1;
    for(int i=4;i>=1;i--)
        push(p, i);
    bool flag=1;
    int n=3;
    while((!vazia(p.TOPO) || !vazia(p1.TOPO)) && flag && n){
        if(!vazia(p.TOPO) && elementoTopo(p) == vetor[n]){pop(p); n--;}
        else if(!vazia(p1.TOPO) && elementoTopo(p1) == vetor[n]){pop(p1);n--;}
        else if(!vazia(p.TOPO) && elementoTopo(p) != vetor[n]){push(p1, pop(p));}
        else flag = 0;

    }
    if(flag)printf("Deu certo\n");
    return 0;
}
