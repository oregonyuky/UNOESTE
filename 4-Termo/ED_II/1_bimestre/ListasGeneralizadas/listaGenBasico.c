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
int main(){
	//[a, [b, c]]
	ListaGen *L;
	L = Cons(CriaT("a"), Cons(Cons(CriaT("b"), Cons(CriaT("c"), NULL)), NULL));
	Exibir(L);
}
