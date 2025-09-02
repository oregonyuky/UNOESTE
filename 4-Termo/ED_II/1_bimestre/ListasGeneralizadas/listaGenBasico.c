#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct reg_lista
{
	struct listagen *cabeca;
	struct listagen *cauda;
};
union info_lista
{
	char info[8];
	struct reg_lista lista;
};
struct listagen
{
	char terminal;
	union info_lista no;
};
typedef struct listagen ListaGen;
struct pilha{
	ListaGen *li;
	struct pilha *prox;
};
typedef struct pilha Pilha;
void init(Pilha **p){
	*p == NULL;
}
void push(Pilha **p, ListaGen *l){
	Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
	aux->li = l;
	aux->prox = *p;
	*p = aux;
}
char isEmpty(Pilha *p){
    return p==NULL;
}
void pop(Pilha **p, ListaGen **l){
	Pilha *aux;
	if(!isEmpty(*p)){
        *l = (*p)->li;
        aux = *p;
        *p = aux->prox;
        free(aux);
    }
}

ListaGen *CriaT(char *info)
{
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 1;
	strcpy(L->no.info, info);
	return L;
}
char Nula(ListaGen *L)
{
	return L==NULL;
}
char Atomo(ListaGen *L)
{
	return !Nula(L) && L->terminal;
}
ListaGen *Cons(ListaGen *H, ListaGen *T)
{
	if (Atomo(T))
	{
		printf("Cons: Segundo arqumento nao pode ser Atomo!");
		return NULL;
	}
	else
	{
		ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
		L->terminal = 0;
		L->no.lista.cabeca = H;
		L->no.lista.cauda = T;
		return L;
	}
}
ListaGen *Head(ListaGen *l){
	return l->no.lista.cabeca;
}
ListaGen *Tail(ListaGen *l){
	return l->no.lista.cauda;
}
void Exibir(ListaGen *l){
	if(Atomo(l))
		printf("%s", l->no.info);
	else{
		printf("[");
		while(!Nula(l)){
			Exibir(Head(l));
			l = Tail(l);
			if(!Nula(l))printf(",");
		}
		printf("]");
		
	}	
}
void ExibirAtomo(ListaGen *l){
	if(!Nula(l)){
		if(Atomo(l))
			printf("%s", l->no.info);
		else{
			ExibirAtomo(Head(l));
			ExibirAtomo(Tail(l));
		}
	}
}
void ExibirAtomoI(ListaGen *l){
	Pilha *p;
	init(&p);
	push(&p, l);
	while(!isEmpty(p)){
		if(!Nula(l)){
			pop(&p, &l);
			while(!Nula(l) && !Atomo(l)){
				push(&p, l);
				l = Head(l);
			}
			if(Atomo(l)){
				printf("%s", l->no.info);
				
			}
		}
		pop(&p, &l);
		l = Tail(l);
		if(!Nula(l))
			push(&p, l);
	}
}
void Destruir(ListaGen **l){
	if(!Nula(*l)){
		if(Atomo(*l)){
			free(*l);
		}
		else{
			Destruir(&(*l)->no.lista.cabeca);
			Destruir(&(*l)->no.lista.cauda);
			free(*l);
			*l = NULL;
		}
	}
}
void DestruirI(ListaGen **l){
	Pilha *p; ListaGen *aux;
	init(&p);
	push(&p, *l);
	while(!isEmpty(p))
	{
		if(!Nula(*l))
		{
			pop(&p, &*l);
			while(!Nula(*l) && !Atomo(*l)){
				push(&p, *l);
				*l = Head(*l);
			}
			if(Atomo(*l))
				free(*l);
		}
		pop(&p, &*l);
		aux = *l;
		*l = Tail(*l);
		free(aux);
		if(!Nula(*l))
			push(&p, *l);
	}
	*l = NULL;
}
int main(){
	//[a, [b, c]]
	ListaGen *L;
	L = Cons(CriaT("a"), Cons(Cons(CriaT("b"), Cons(CriaT("c"), NULL)), NULL));
	Exibir(L); puts("");
	ExibirAtomo(L); puts("");
	ExibirAtomoI(L); puts("");
	puts("liberar toda lista");
	DestruirI(&L);
	Exibir(L);
}
