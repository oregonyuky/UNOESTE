#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no
{
	int info, alt;
	No* esq;
	No* dir;
};
typedef No* ArvAVL;

ArvAVL* criaArvore()
{
	ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
	if(raiz != NULL)
		*raiz = NULL;
	return raiz;
}

void liberaNo(ArvAVL no)
{
	if(no != NULL)
	{
		liberaNo(no->esq);
		liberaNo(no->dir);
		free(no);
		no = NULL;
	}
}
void liberaArvore(ArvAVL* raiz)
{
	if(raiz != NULL)
	{
		liberaNo(*raiz);
		free(raiz);
		*raiz = NULL;
	}
}

char vazia(ArvAVL* raiz)
{
	return *raiz == NULL;
}

int maior(int x, int y) {return (x>y)? x : y;}

int getAlt(ArvAVL folha)
{
	if(no == NULL)
		return -1;
	return no->alt;
}

int fatorBalanceamento(ArvAVL folha) {return labs(getAlt(no->esq) - getAlt(no->dir));}

int altArvore(ArvAVL* raiz)
{
	int altesq, altdir;

	if(!vazia(raiz))
	{
		altesq = altArvore( (&(*raiz)->esq) );
		altdir = altArvore( (&(*raiz)->dir) );

		return (altesq > altdir)? altesq+1 : altdir+1;
	}
	return 0;
}

int totFolhas(ArvAVL* raiz)
{
	int totesq, totdir;
	if(!vazia(raiz))
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

void preOrdem(ArvAVL* raiz)
{
	if(!vazia(raiz))
	{
		printf("%d\n", (*raiz)->info);
		preOrdem( &((*raiz)->esq) );
		preOrdem( &((*raiz)->dir) );
	}
}

void emOrdem(ArvAVL* raiz)
{
	if(!vazia(raiz))
	{
		preOrdem( &((*raiz)->esq) );
		printf("%d\n", (*raiz)->info);
		preOrdem( &((*raiz)->dir) );
	}
}

void posOrdem(ArvAVL* raiz)
{
	if(!vazia(raiz))
	{
		preOrdem( &((*raiz)->esq) );
		preOrdem( &((*raiz)->dir) );
		printf("%d\n", (*raiz)->info);		
	}
}
char consultaI(ArvAVL* raiz, int valor)
{
	ArvAVL aux;
	if(raiz != NULL)
	{
		aux = *raiz;

		while(aux != NULL)
		{
			if(aux->info == valor)
				return 1;
			if(aux->info > valor)
				aux = aux->esq;
			else
				aux = aux->dir;
		}
	}
	return 0;
} 
// INTERATIVO

void pre_ordem (ArvBin raiz)
{
	Pilha *p;
	init(&p);
	push(&p, raiz);
	while(!isEmpty(p))
	{
		if(!Nula(raiz))
		{
			Pop(&p, &raiz);
			while(raiz != NULL)
			{
				printf("%d ", raiz->info);
				push(&p, raiz);
				raiz = raiz->esq;
			}
		}
		pop(&p, &raiz);
		raiz = raiz->dir;
		if(!Nula(raiz))
			push(&p, raiz);
	}
}

void pre_ordem2(ArvBin raiz)
{
	Pilha *p;
	init(&p);
	while(raiz != NULL)
	{
		printf("%d", raiz->info);
		
		if(raiz -> dir != NULL)
			push(&p, raiz->dir);
		if(raiz -> esq != NULL)
			push(&p, raiz->esq);
		//if(!isEmpty(p))
		pop(&p, &raiz);
		//else
			//raiz = NULL;
	}
}
char consultaR(ArvAVL* raiz, int valor)
{
	if(raiz != NULL)
	{
		if(*raiz != NULL)`
		{
			if((*raiz)->info == valor)
					return 1;

			if((*raiz)->info > valor)
				consultaR(&(*raiz)->esq, valor);
			else
				consultaR(&(*raiz)->dir, valor);
		}
	}
	return 0;
} 
// ROTAÇÕES
// LL
// RR
// RL
// LR
//Formas de saber qual balanceamento usar apartir do Fator de Balanceamento:
// Se A = +2 e B = +1 >>>> LL (Rotação para Esquerda)
// Se A = -2 e B = -1 >>>> RR (Rotação para Direita)
// Se A = +2 e B = -1 >>>> LR (Rotação para Esquerda Direita)
// Se A = -2 e B = +1 >>>> RL (Rotação para Direita Esquerda)
void rotacaoLL(ArvBin* raiz)
{
	ArvBin q, *temp;
	q = (*raiz)->dir;
	temp = q->esq;
	q->esq = *raiz;
	(*p)->dir = temp;
	*raiz = q;
}
void rotacaoRR(ArvBin* raiz)
{
	ArvBin q, *temp;
	q = (*raiz)->esq;
	temp = q->dir;
	q->dir = *raiz;
	raiz->esq = temp;
	*raiz = q;
}

void rotacaoLR(ArvBin* p)
{
	rotacaoLL(p);
	rotacaoRR(p);
}

void rotacaoLR(ArvBin* p)
{
	rotacaoRR(p);
	rotacaoLL(p);
}

void insereAVL(ArvBin* raiz, int info, int* rot)
{
	int fb, fbf;
	if(vazia(*raiz))
	{
		*raiz = CriaNo(info);
		*rot = 0;
	}
	else
		if(info > (*raiz)->info)
			insereAVL(&(*raiz)->dir, info, &rot);
		else
			insereAVL(&(*raiz)->esq, info, &(*rot));
	if(!*rot)
	{
		fb = fatorBalanceamento((*raiz)->dir);
		if ( fb == 2 || fb == -2)
		{
			*rot = 1;
			if(fb == 2)
			{
				fbf = fatorBalanceamento((*raiz)->dir) - fatorBalanceamento((*raiz)->esq);
				if(fb_filho == 1) //(2) (1)
					rotacaoLL(&*raiz);
				else	//(2)(-1)
				{
					rotacaoRR(&(*raiz)->dir);
					rotacaoLL(&*raiz);
				}
			}
			else	//-2
			{
				fbf = fatorBalanceamento((*raiz)->dir) - fatorBalanceamento((*raiz)->esq);
				if(fbf == -1) //(-2)(-1)
					rotacaoRR(&*raiz);
				else
				{
					rotacaoLL(&(*raiz)->esq);
					rotacaoRR(&*raiz);
				}
			}
		}
	}
}
//exclusão, olha o caminho inverso ao qual exclui e verifico se foi desbalanceado.

int main()
{
	ArvAVL* raiz = criaArvore();
}

