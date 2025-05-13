#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TpPont{
	char nome[20];
	TpPont *ant, *prox;
};
TpPont *NovaCaixa(char nome[20]){
	TpPont *Caixa = new TpPont;
	Caixa->prox = NULL;
	strcpy(Caixa->nome, nome);
	Caixa->ant = NULL;
	return Caixa;
}
TpPont *InsOrdenado(TpPont *lista){
	TpPont *NC, *aux;
	char AuxNome[20];
	printf("Nome: ");fflush(stdin);
	gets(AuxNome);
	//fgets(AuxNome, sizeof(AuxNome), stdin);
	//AuxNome[strcspn(AuxNome, "\n")]='\0';
	while(strcmp(AuxNome, "\0")!=0){
		NC = NovaCaixa(AuxNome);
		if(lista==NULL){
			lista = NC;
		}
		else if(stricmp(AuxNome, lista->nome)<=0){
			NC->prox = lista;
			lista->ant = NC;
			lista = NC;
		}
		else{
			aux = lista;
			while(aux->prox!=NULL && stricmp(AuxNome, aux->nome)>0)
				aux = aux->prox;
			if(stricmp(AuxNome, aux->nome)>0){
				NC->ant = aux;
				aux->prox = NC;
			}
			else{
				NC->prox = aux;
				NC->ant = aux->ant;
				aux->ant->prox = NC;
				aux->ant = NC;
			}
		}
		printf("Nome: ");fflush(stdin);
		gets(AuxNome);
		//fgets(AuxNome, sizeof(AuxNome), stdin);
		//AuxNome[strcspn(AuxNome, "\n")]='\0';
	}
	return lista;
}
void Exibir(TpPont *P){
	while(P!=NULL){
		printf("Nome: %s\n", P->nome);
		P = P->prox;
	}
}
int main(){
	TpPont *P = NULL;
	P = InsOrdenado(P);
	Exibir(P);
	return 0;
}
