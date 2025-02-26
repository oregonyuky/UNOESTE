#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include "tadpilha.h"
int main(){
    TpPilha P1, P2;
    char op, aux[30];
    do{
        printf("\nString: ");
        fflush(stdin);
        gets(aux);
        int tl = strlen(aux);
        for(int i=0;i<tl/2;i++){
            Push(P1, aux[i]);
            Push(P2, aux[tl-i-1]);
        }
        int qtd=0;
        while(!Vazia(P1.TOPO)){
            if(P1.PILHA[P1.TOPO]==P2.PILHA[P2.TOPO])qtd++;
        }
        if(qtd<tl/2)
            printf("%s nao eh palindromo\n", aux);
        else
            printf("%s eh palindromo\n", aux);
        printf("Deseja continuar? <s/n>\n");
        op=toupper(getch());
    }while(op!='N');
}
