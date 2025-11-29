#include <stdio.h>
#include <stdlib.h>
#include "filaPilha.h"
/********	ARVORE BINARIA DE BUSCA (ABB) 	*********/
//Nessa arvore o filho da esquerda é sempre menor que o pai 
//e o filho da direita é sempre maior.

/*******************************************************/

typedef struct no No;

struct no
{
	int info;
	No* esq;
	No* dir;
};
typedef No* Tree;

//void init(Tree* raiz)
//{
//	*raiz = NULL;
//}
Tree* criaArvore()
{
	Tree* raiz = (Tree*) malloc(sizeof(Tree));
	if(raiz != NULL)
		*raiz = NULL;
	return raiz;
}

void liberaNo(Tree no)
{
	if(no != NULL)
	{
		liberaNo(no->esq);
		liberaNo(no->dir);
		free(no);
		no = NULL;
	}
}
void liberaArvore(Tree* raiz)
{
	if(raiz != NULL)
	{
		liberaNo(*raiz);
		free(raiz);
		*raiz = NULL;
	}
}

char vazia(Tree raiz)
{
	return raiz == NULL;
}

int altArvore(Tree* raiz)
{
	int altesq, altdir;

	if(!vazia(*raiz))
	{
		altesq = altArvore( (&(*raiz)->esq) );
		altdir = altArvore( (&(*raiz)->dir) );

		return (altesq > altdir)? altesq+1 : altdir+1;
	}
	return 0;
}

int totFolhas(Tree* raiz)
{
	int totesq, totdir;
	if(!vazia(*raiz))
	{
		totesq = totFolhas( (&(*raiz)->esq) );
		totdir = totFolhas( (&(*raiz)->esq) );
		return totesq + totdir +1;
	}
	return 0;
}
//****** PERCORRIMENTO *************//
// Pré-Ordem: primeiro visito todos os filhos da direita e depois da esquerda
// Em-Ordem: é visitado o filho da esquerda a raiz e o filho da direita
// Pós-Ordem: filho da direita, filho da esquerda e raiz. Garante que visitarei todos os filhos de uma arvore antes de chegar nela.
//**********************************//

void preOrdem(Tree* raiz)
{
	if(!vazia(*raiz))
	{
		printf("%d\n", (*raiz)->info);
		preOrdem( &((*raiz)->esq) );
		preOrdem( &((*raiz)->dir) );
	}
}

void emOrdem(Tree* raiz)
{
	if(!vazia(*raiz))
	{
		preOrdem( &((*raiz)->esq) );
		printf("%d\n", (*raiz)->info);
		preOrdem( &((*raiz)->dir) );
	}
}

void emOrdemDecres(Tree* raiz)
{
	if(!vazia(*raiz))
	{
		preOrdem( &((*raiz)->dir) );
		printf("%d\n", (*raiz)->info);
		preOrdem( &((*raiz)->esq) );
	}
}

void posOrdem(Tree* raiz)
{
	if(!vazia(*raiz))
	{
		preOrdem( &((*raiz)->esq) );
		preOrdem( &((*raiz)->dir) );
		printf("%d\n", (*raiz)->info);		
	}
}
Tree CriaNo(int info)
{
	Tree no = (Tree) malloc(sizeof(No));
	no->info = info;
	no->esq  = NULL;
	no->dir  = NULL;
}
////////////////////////////////////////////////////////
char inserirABB(Tree* raiz, int valor)
{
	Tree no;
	Tree atual;
	Tree ant;
	if(vazia(*raiz))
	{
		*raiz = CriaNo(valor);
		return 1;
	}
	else
	{
		atual = *raiz;
		while(atual != NULL)
		{
			ant = atual;
			if(atual->info > valor)
				atual = atual->esq;
			else if(atual->info < valor)
				atual = atual->dir;
		}
		if(ant->info != valor)
		{				
			if(ant->info > valor)
				ant->esq = CriaNo(valor);
			else
				ant->dir = CriaNo(valor);
			return 1;
		}
	}
	return 0;
}
void inserirABBR(Tree* raiz, int valor)
{
	if(vazia(*raiz))
	{
		*raiz = CriaNo(valor);
	}
	else 	
		if(valor < (*raiz)->info)
			inserirABBR(&(*raiz)->esq, valor);
		else
			inserirABBR(&(*raiz)->dir, valor);
}
Tree removeFolha(Tree folha)
{
	Tree no1, no2;
	
	if(folha->esq == NULL)
	{
		no2 = folha->dir;
		free(folha);
		return no2;
	}
	no1 = folha;
	no2 = folha->esq;
	while(no2->dir != NULL)
	{
		no1 = no2;
		no2 = no2->dir;
	}
	if(no1 != folha)		//copia o filho mais a direita
	{
		no1->dir = no2->esq;	//para a posição do elemento que
		no2->esq = folha->esq;	//foi removido
	}
	no2->dir = folha->dir;
	free(folha);
	
	return no2;
}
Tree  consultaABB_I(Tree* raiz, int valor, Tree aux)
{
	if(raiz != NULL)
	{
		aux = *raiz;

		while(aux != NULL && aux->info == valor)
		{
			if(aux->info > valor)
				aux = aux->esq;
			else
				aux = aux->dir;
		}
	}
	return aux;
} 
Tree consultaABB_R(Tree* raiz, int valor, Tree aux)
{
	aux = *raiz;
	if(aux != NULL)
	{
		if(aux->info == valor)
				return aux;
		if(aux->info > valor)
			consultaABB_R(&(*raiz)->esq, valor, aux);
		else
			consultaABB_R(&(*raiz)->dir, valor, aux);

	}
	return NULL;
} 

void consultaBurra(Tree raiz, int info, Tree* aux)
{
	*aux = NULL;
	if(!vazia(raiz))
	{
		if(info == raiz -> info)
			*aux = raiz;
		else
		{
			consultaBurra((raiz)->esq, info, &*aux);
			if(*aux == NULL)
				consultaBurra((raiz)->dir, info, &*aux);
		}
	}
}
void consultaBurraI(Tree raiz, int info, Tree* aux)
{
	while(raiz != NULL && info != raiz->info)
	{
		if(info < raiz->info)
			raiz = raiz->esq;
		else
			raiz = raiz->dir;
	}
	*aux = raiz;
}
/*
	- Verificar qual o nivel de um dado nó, usando pre-ordem e busca ABB
	- Retornar o pai de um nó
	- Exibir a arvore no formato de arvore (80/25)
	- Pre-Ordem, In-Ordem e Pos-ordem interativo
*/
Tree encontrarPai(Tree raiz, int folha)
{
	Tree ant = raiz;
	while(raiz != NULL && folha != raiz->info)
	{
		ant = raiz;
		if(folha < raiz->info)
			raiz = raiz->esq;
		else
			raiz = raiz->dir;
	}
	
	return ant;
}
/*
	1. e é folha
		1.1 e != pai
			1.1.1 lado direito e->info
			1.1.2 lado esquerdo e->info < pai->info
		1.2 e == pai
	2. e tem 1 filho
	2.1. e != pai
		2.1.1. e->info > pai->info
			2.1.1.1 e->esq != NULL
			2.1.1.2 e->dir != NULL
		2.1.2. e->info < pai->info
			2.1.2.1 e->esq != NULL
			2.1.2.2 e->dir != NULL
	2.2 e == pai
		2.2.1. e->esq != NULL
		2.2.2. e->dir != NULL
*/
/*
	30
20		40
*/

void exclusao(Tree *raiz, Tree e, Tree pai, char lado)
{
    Tree sub, paisub;
    if (e->esq == NULL && e->dir == NULL)
    {
        if (e != pai)
        {
            if (e->info > pai->info)
                pai->dir = NULL;
            else
                pai->esq = NULL;
        }
        else
            *raiz = NULL;

        free(e);
        return;
    }
    if ((e->esq == NULL && e->dir != NULL) ||
        (e->esq != NULL && e->dir == NULL))
    {
        Tree filho = (e->esq != NULL) ? e->esq : e->dir;
        if (e != pai)
        {
            if (e->info > pai->info)
                pai->dir = filho;
            else
                pai->esq = filho;
        }
        else
            *raiz = filho;
        free(e);
        return;
    }
    if (lado == 'd')  
    {
        sub = e->dir;
        paisub = e;
        while (sub->esq != NULL)
        {
            paisub = sub;
            sub = sub->esq;
        }
    }
    else  // lado == 'e'
    {
        sub = e->esq;
        paisub = e;
        while (sub->dir != NULL)
        {
            paisub = sub;
            sub = sub->dir;
        }
    }
    e->info = sub->info;
    exclusao(raiz, sub, paisub, lado);
}

char removeABB(Tree* raiz, int valor)
{
	Tree atual = *raiz;
	Tree ant = NULL;
	if(raiz != NULL)
	{
		if(!vazia(*raiz))
		{
			while(atual != NULL)
			{
				if(atual->info == valor)
				{
					if(atual == *raiz)
						*raiz = removeFolha(atual);
					else if(ant->dir == atual)
						ant->dir = removeFolha(atual);
					else
						ant->esq = removeFolha(atual);
					return 1;			
				}
			
				ant = atual;
				if(atual->info > valor)
					atual = atual->esq;
				else
					atual = atual->dir;
			}
		}

	}

	return 0;
}
/*
Balanceamento
*/

int qntNo(Tree folha) //contar a quantidade nos
{
	if(folha != NULL)return qntNo(folha->esq) + qntNo(folha->dir) + 1;
	return 0;
}

void balanceamento(Tree **raiz)
{
	int qd, qe, fb, aux;
	Tree r = *raiz, *e, *pai;
	FILA *f;
	initF(&f);
	enqueueF(&f, *raiz);
	while(!isEmptyF(f))
	{
		dequeueF(&f, &r);
		do
		{
			qd = qntNo(r->dir);
			qe = qntNo(r->esq);
			fb = qd - qe;

			busca(r, r->info, &e, &pai);
			if(r->esq == NULL)
				r= r->dir;
			else
				if(r->dir == NULL)
					r = r->esq;
			if(fb > 0)
				exclusao(&*raiz, e, pai, 'd');
			else
				exclusao(&*raiz, e, pai, 'e');
			insere(&*r, aux);
		}while(abs(fb) > 1);
	
		if(r->esq != NULL)
			enqueueF(&f, r->esq);
		else if(r->dir != NULL)
			enqueueF(&f, r->dir);
	}
}
/////////////////////////////////////////////
void quantNo(Tree raiz, int *count)
{
	*count = 0;
	Pilha *p;
	initP(&p);

	if(!vazia(raiz)){
		push(&p, raiz);
		(*count)++;
		while(!isEmptyP(p))
		{
			pop(&p,&raiz);
			if(raiz->dir!=NULL)
			{
				push(&p,raiz->dir);
				(*count)++;
			}
			if(raiz->esq!=NULL)
			{
				(*count)++;
				push(&p,raiz->esq);
			}
		}

	}
}

void buscaNo(Tree raiz, int infopai, Tree *pai, Tree *e)
{
	Pilha *p;
	char sair = 0;
	initP(&p);

	push(&p,raiz);
	*pai = raiz;
	*e = raiz;
	while(!isEmptyP(p) && infopai != (*e)->info && !sair)
	{
		pop(&p,&raiz);
		*pai = raiz;

		if(raiz->dir!=NULL){
			*e = raiz->dir;
			push(&p,raiz->dir);
		}
		if(raiz->esq!=NULL){
			*e = raiz->esq;
			push(&p,raiz->esq);
		}
		
		if((*e)->info == infopai)
			sair = 1;
	}
}

void balanceamento(Tree **raiz)
{
	Tree r, *e, *pai, *aux;
	int qd, qe, fb, auxi;
	
	Fila *f;
	initF(&f);
	enqueueF(&f, *raiz);
	while(!isEmptyF(f))
	{
		dequeueF(&f, &r);
		do
		{
			qd = qe = 0;
			quantNo(r->dir, &qd); // preordem
			quantNo(r->esq, &qe);
			fb = qd - qe;
			if(abs(fb) > 1)
			{
				auxi = r->info;
				buscaNo(*raiz, auxi, &e, &pai);
				
				if(r->esq == NULL)r = r->dir;
				else if(r->dir == NULL)r = r->esq;
				
				if(fb > 0)
					exclusao(&*raiz, e, pai, 'd');
				else
					exclusao(&*raiz, e, pai, 'e');
				
				insereR(&*raiz, auxi);
			}
		}while(abs(fb) > 1);
	}
}
int main()
{
	Tree* raiz;
	Tree aux;
	raiz = criaArvore();
	inserirABB(raiz, 100);
	inserirABB(raiz, 60);
	inserirABB(raiz, 120);
	inserirABB(raiz, 50);
	inserirABB(raiz, 80);
	inserirABB(raiz, 110);
	inserirABB(raiz, 130);
	inserirABB(raiz, 70);
	inserirABB(raiz, 90);
	preOrdem(raiz);
	aux = encontrarPai(*raiz, 80);
	printf("%d\n", aux->info);
}

