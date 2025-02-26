#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include "tadpilha.h"

int main()
{
	tpPilha p1, p2, p3;
	char elem;
	inicializar(p3);
	inicializar(p1);
	inicializar(p2);
	printf("Elementos da pilha 1: \n");
	fflush(stdin);
	elem = getch();
	while(!cheia(p1.topo) && elem!='n'){
		push(p1, elem);
		elem = getch();
	}
	
	printf("Elementos da pilha 2: \n");
	fflush(stdin);
	elem = getch();
	while(!cheia(p2.topo) && elem!='n'){
		push(p2, elem);
		elem = getch();
	}

	while(!vazia(p2.topo)){
		push(p3, pop(p2));
	}
	while(!cheia(p1.topo) && !vazia(p3.topo)){
		push(p1, pop(p3));
	}
	clrscr();
	exibir(p1);
	getch();
	return 0;
}
