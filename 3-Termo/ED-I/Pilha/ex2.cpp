#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include "tadpilha.h"
void Exclusao(){
    tpPilha p1, p2;
    inicializar(p1);
    inicializar(p2);
    char Elem;
    puts("digite a pilha 1:");
    Elem = getche();
    while(!cheia(p1.topo)){
        push(p1, Elem);
        Elem = getche();
    }
    char num;
    puts("digite o numero: ");
    scanf("%c", &num);
    while(!vazia(p1.topo)){
        if(p1.pilha[p1.topo]!=num)
            push(p2, pop(p1));
        else
            pop(p1);
    }
    exibir(p2);
}
