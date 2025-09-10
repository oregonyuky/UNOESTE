#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tadListaGen.h"
void selecao_direta(ListaGen *l){
    for(ListaGen *i = l; i->no.lista.cauda; i = i->no.lista.cauda){
        ListaGen *aux = i;
        for(ListaGen *j = i->no.lista.cauda; j; j = j->no.lista.cauda){
            if(strcmp(j->no.info, aux->no.info)<0)
                aux = j;
        }
        if(aux != i){
            char str[100];
        	strcpy(str, aux->no.info);
            strcpy(aux->no.info, i->no.info);
            strcpy(i->no.info, str);
        }
    }
}
void OrdenaLG(ListaGen *l){
	Fila *f1, *f2;
	init(&f1); init(&f2);
	enqueue(&f1, l);
	enqueue(&f2, l);
	while(!isEmpty(f1)){
		dequeue(&f1, &l);
		while(!Nula(l)){
			if(!Nula(Head(l)) && !Atomo(Head(l))){
				enqueue(&f1, l);
				enqueue(&f2, l);
			}
			l = Tail(l);
		}
	}
	while(!isEmpty(f2)){
		dequeue(&f2, &l);
		selecao_direta(l);
	}
}
int main(){
    ListaGen *l;
    l = Cons(CriaT("c"), Cons(CriaT("b"), Cons(CriaT("a"), NULL)));
    selecao_direta(l);
    Exibir(l); // deve mostrar: a b c
}
