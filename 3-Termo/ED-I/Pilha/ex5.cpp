#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include "tadpilha.h"
int main(){
    TpPilha P, P1;
    char op;
    do{
        Inicializar(P);
        Inicializar(P1);
        printf("\nVetor: ");
        for(int i=0;i<10;i++){
            scanf(" %c", &P.PILHA[i]);
            P.TOPO=i;
        }
        Exibir(P);
        op = toupper(getch());
    }while(op!='N');
}
