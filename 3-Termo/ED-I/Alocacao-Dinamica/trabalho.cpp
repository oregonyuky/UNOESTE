#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio2.h>

struct TpVeiculo{
	char id[20], cor[20], marca[10], prioridade;
	TpVeiculo *prox;
};
struct TpAtendente{
	TpVeiculo *Inicio, *Fim;
	TpAtendente *ant, *prox;
	char ID[30];
};
struct TpDescAtend{
	char info[30];
	int qtd;
	TpAtendente *Inicio, *Fim;

};
void Inicializar(TpDescAtend &Desc){
	Desc.Inicio = Desc.Fim = NULL;
}
char FilaVazia(TpDescAtend Desc){
	return Desc.qtd == 0;
}
TpAtendente *NovaCaixa(char ID[30]){
	TpAtendente *p = new TpAtendente;
	p->prox = NULL;
	p->ant = NULL;
	strcpy(p->ID, ID);
	return p;
}
void InserirID(TpDescAtend &Desc, char ID[30]){
	TpAtendente *NC, *p, *ant;
	NC = NovaCaixa(ID);
	if(Desc.qtd==0){
		Desc.Inicio = Desc.Fim = NC;
	}
	else if(strcmp(ID, Desc.Inicio->ID)<=0){
		NC->prox = Desc.Inicio;
		Desc.Inicio = NC;		
	}
	else if(strcmp(ID, Desc.Fim->ID)>=0){
		Desc.Fim->prox = NC;
		Desc.Fim = NC;
	}
	else{
		ant = Desc.Inicio;
		p = Desc.Inicio->prox;
		while(p!=NULL && strcmp(ID, p->ID)>=0){
			ant = p;
			p = p->prox;
		}
		ant->prox = NC;
		NC->prox = p;
	}
	Desc.qtd++;
}
void Exibir(TpDescAtend Desc){
	TpAtendente *p = Desc.Inicio;
	if(Desc.Inicio==NULL)printf("lista esta vazia\n");
	while(p!=NULL){
		printf("- %s\n", p->ID);
		p = p->prox;
	}
}
int main(){
	TpAtendente *p = NULL;
	TpDescAtend desc;
	Inicializar(desc);
	InserirID(desc, "gabriel");
	puts("a");
	Exibir(desc);
}
