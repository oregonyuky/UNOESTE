#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct reg_list{
    struct listaGen *cabeca;
    struct listaGen *cauda;
} lista;
union info_lista{
    char info[8];
    struct reg_list lista;
};
typedef struct listaGen{
    char terminal;
    union info_lista no;
} ListaGen;
typedef struct fila{
    ListaGen *l;
    struct fila *prox;
} Fila;
ListaGen *Head(ListaGen *l){
	return l->no.lista.cabeca;
}
ListaGen *Tail(ListaGen *l){
	return l->no.lista.cauda;
}
ListaGen *Cons(ListaGen *h, ListaGen *t){
    ListaGen *aux = (ListaGen*)malloc(sizeof(ListaGen));
    aux->terminal = 0;
    aux->no.lista.cabeca = h;
    aux->no.lista.cauda = t;
    return aux;
}
ListaGen *CriaT(char *str){
    ListaGen *aux = (ListaGen*)malloc(sizeof(ListaGen));
    aux->terminal = 1;
    strcpy(aux->no.info, str);
    return aux;
}
void init(Fila **f){
    *f = NULL;
}
void enqueue(Fila **f, ListaGen *l){
    Fila *aux = (Fila*)malloc(sizeof(Fila));
    aux->l = l;
    aux->prox = NULL; 
    if(!*f)
        *f = aux;
    else{
        Fila *aux1 = *f;
        while(aux1->prox)aux1 = aux1->prox;
        aux1->prox = aux;
    }
}
void dequeue(Fila **f, ListaGen **l){
    Fila *aux = *f;
    *f = (*f)->prox;
    *l = aux->l;
    free(aux);
}
char isEmpty(Fila *f){
    return f == NULL;
}
char Nula(ListaGen *l){
    return l == NULL;
}
char Atomo(ListaGen *l){
	return !Nula(l) && l->terminal;
}
void selecao_direta(ListaGen *l){
    for(ListaGen *i = l; i; i = i->no.lista.cauda){
        ListaGen *aux = i, *aux1;
        for(ListaGen *j = i->no.lista.cauda; j; j = j->no.lista.cauda){
            if(strcmp(j->no.info, aux->no.info)<0)
                strcpy(aux->no.info, j->no.info);
        }
        if(strcmp(aux->no.info, i->no.info)!=0){
        	strcpy(aux1->no.info, aux->no.info);
            strcpy(aux->no.info, i->no.info);
            strcpy(i->no.info, aux1->no.info);
        }
    }
}
void Exibir(ListaGen *l){
	if(!Nula(l)){
	    if(Atomo(l)){
	        printf("%s", l->no.info);
	    }; 
	    Exibir(Head(l));
	    Exibir(Tail(l));
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
	l = Cons(CriaT("c"), Cons(Cons(CriaT("a"), Cons(CriaT("b"), NULL)), NULL));
    Exibir(l);
}