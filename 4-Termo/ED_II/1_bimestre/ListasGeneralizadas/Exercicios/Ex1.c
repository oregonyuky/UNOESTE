#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tadListaGen.h"
// devolve uma string para comparar nós (átomos e sublistas)
char* chave(ListaGen *l) {
    static char buffer[100]; // cuidado: sobrescrito a cada chamada
    if (Atomo(l)) {
        return l->no.info;
    } else {
        ListaGen *h = Head(l);
        if (h && Atomo(h))
            return h->no.info;
        else
            return "~"; // sublista vazia ou sem átomo -> joga pro fim
    }
}

void selecao_direta(ListaGen *l){
    for (ListaGen *i = l; i->no.lista.cauda; i = i->no.lista.cauda) {
        ListaGen *aux = i;
        for (ListaGen *j = i->no.lista.cauda; j; j = j->no.lista.cauda) {
            if (strcmp(chave(j), chave(aux)) < 0)
                aux = j;
        }
        if (aux != i) {
            // troca profunda de nós (átomo ou sublista)
            ListaGen temp = *i;
            *i = *aux;
            *aux = temp;

            // mas repara: as trocas também trocam os encadeamentos,
            // então precisamos restaurar os ponteiros "cauda"
            ListaGen *tmp = i->no.lista.cauda;
            i->no.lista.cauda = aux->no.lista.cauda;
            aux->no.lista.cauda = tmp;
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
				enqueue(&f1, Head(l));
				enqueue(&f2, Head(l));
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
    ListaGen *l, *ll;
	l = Cons(CriaT("c"), Cons(Cons(CriaT("a"), Cons(CriaT("b"), NULL)), NULL));
	ll = Cons(
    CriaT("x"),
    Cons(
        CriaT("a"),
        Cons(
            Cons(
                CriaT("c"),
                Cons(CriaT("d"), NULL)
            ),
            Cons(
                Cons(
                    CriaT("e"),
                    Cons(
                        CriaT("a"),
                        Cons(
                            Cons(CriaT("f"), NULL),
							NULL
                        )
                    )
                ),
                Cons(CriaT("b"), NULL)
            )
        )
    )
);
OrdenaLG(ll);
Exibir(ll); 
}
