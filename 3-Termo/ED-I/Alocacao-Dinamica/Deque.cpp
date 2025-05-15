#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
struct TpPont{
	char nome[30];
	TpPont *prox, *ant;
};
struct TpDesc{
	TpPont *Inicio, *Fim;
};
void Inicializar(TpDesc &Desc){
	Desc.Inicio = Desc.Fim = NULL;
}
char DequeVazia(TpDesc Desc){
	return Desc.Inicio == NULL;
}

void InsInicio(TpDesc &Desc, char nome[30]){
	TpPont *p = new TpPont;
	strcpy(p->nome, nome);
	p->ant = NULL;
	p->prox = Desc.Inicio;
	if(Desc.Inicio!=NULL)
		Desc.Inicio->ant = p;
	else{
		Desc.Fim = p;
	}
	Desc.Inicio = p;
}

void InsFim(TpDesc &Desc, char nome[30]){
	TpPont *p = new TpPont;
	strcpy(p->nome, nome);
	p->ant = Desc.Fim;
	p->prox = NULL;
	if(Desc.Fim!=NULL)
		Desc.Fim->prox = p;
	else
		Desc.Inicio = p;
	Desc.Fim = p;
}
void ExcInicio(TpDesc &Desc, char nome[30]){
	if(Desc.Inicio==NULL)return;
	TpPont *p = Desc.Inicio;
	strcpy(nome, p->nome);
	Desc.Inicio = p->prox;
	if(Desc.Inicio!=NULL)
		Desc.Inicio->ant = NULL;
	else
		Desc.Fim = NULL;
	delete(p);
}

void ExcFim(TpDesc &Desc, char nome[30]){
	if(Desc.Inicio==NULL)return;
	TpPont *p = Desc.Fim;
	strcpy(nome, p->nome);
	Desc.Fim = p->ant;
	if(Desc.Fim!=NULL)
		Desc.Fim->prox = NULL;
	else
		Desc.Inicio = NULL;
	delete(p);
}

void Exibir(TpDesc Desc){
	TpPont *p = Desc.Inicio;
	while(p!=NULL){
		printf("- %s\n", p->nome);
		p = p->prox;
	}
}
void ElementoInicio(TpDesc Desc, char nome[30]){
	if(Desc.Inicio==NULL)return;
	strcpy(nome, Desc.Inicio->nome);
}
void ElementoFim(TpDesc Desc, char nome[30]){
	if(Desc.Fim==NULL)return;
	strcpy(nome, Desc.Fim->nome);
}
void ExibirContrario(TpDesc Desc){
	TpPont *p = Desc.Fim;
	if(p->ant==NULL)return;
	printf("- %s\n", p->nome);
	Desc.Fim =  p->ant;
	ExibirContrario(Desc);
}
void LiberarLista(TpDesc &Desc){
	TpPont *p = Desc.Inicio;
	while(p!=NULL){
		TpPont *aux = p;
		p = p->prox;
		delete(aux);
	}
	Desc.Inicio = NULL;
	Desc.Fim = NULL;
}
int main(){
	TpDesc Desc;
	Inicializar(Desc);
	InsInicio(Desc, "gabriel");
	InsInicio(Desc, "rozendo");
	InsInicio(Desc, "ian");
	InsInicio(Desc, "Jose");
	InsFim(Desc, "willian");
	InsFim(Desc, "eric");
	InsFim(Desc, "Castilho");
	
	Exibir(Desc);
	char buffer[30];
	ExcInicio(Desc, buffer);
	putchar('\n');
	Exibir(Desc);
	char buffer2[30];
	ExcFim(Desc, buffer2);
	putchar('\n');
	Exibir(Desc);
	putchar('\n');
	
	char buffer3[30];
	char buffer4[30];
	ElementoInicio(Desc, buffer3);
	printf("elementoInicio - %s\n", buffer3);
	ElementoFim(Desc, buffer4);
	printf("elementoFim - %s\n", buffer4);
	puts("");
		
	ExibirContrario(Desc);
	LiberarLista(Desc);
	Exibir(Desc);
	
	return 0;
}
