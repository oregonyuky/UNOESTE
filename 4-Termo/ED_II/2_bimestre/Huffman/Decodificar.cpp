#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TF 300

struct tree
{
    char simb;
    struct tree *dir;
    struct tree *esq;

};
typedef struct tree Tree;

struct tabela
{
	char palavra[30], codHuff[15],simbo;
};
typedef struct tabela Tabela;

struct bits
{
 unsigned char b7:1;
 unsigned char b6:1;
 unsigned char b5:1;
 unsigned char b4:1;
 unsigned char b3:1;
 unsigned char b2:1;
 unsigned char b1:1;
 unsigned char b0:1;
};
union byte
{
 struct bits bi;
 unsigned char num;
};

Tree* Caixa(char simb)
{
	Tree *nova;
	nova = (Tree*)malloc(sizeof(Tree));
	nova->esq = NULL;
	nova->dir = NULL;
	nova->simb = simb;
	
	return nova;
}

// 0 = esq
Tree* CriarArvore(Tree **no, char *NomeArq)
{
	FILE *Ptr = fopen(NomeArq,"rb");
	Tree *aux;
	Tabela tab;
	int i = 0;
	
	if(Ptr == NULL)
	{
		printf("\nErro\n");
	}
	else
	{
		fread(&tab,sizeof(Tabela),1,Ptr);
		while(!feof(Ptr))
		{
			i=0;
			aux = *no;
			while(tab.codHuff[i] != '\0')
			{
				if(tab.codHuff[i] < '1')
				{
					if(aux->esq == NULL)
					{
						aux->esq = Caixa('!');
					}
					aux = aux->esq;
				}
				else
				{
					if(aux->dir == NULL)
					{
						aux->dir = Caixa('!');
					}
					aux = aux->dir;
				}
				i++;
			}
			aux->simb = tab.simbo;
			
			fread(&tab,sizeof(Tabela),1,Ptr);
		}
		
		fclose(Ptr);
	}
}

void BuscaTabela(FILE *Ptr, char simb,char str[TF])
{
	Tabela tab;
	
	rewind(Ptr);
	fread(&tab,sizeof(Tabela),1,Ptr);
	while(!feof(Ptr) && tab.simbo != simb)
		  fread(&tab,sizeof(Tabela),1,Ptr);
	
	if(!feof(Ptr))
	{
		//printf("%s",tab.palavra);
		strcat(str,tab.palavra);
	}
	
	
}
void mostrar(byte B)
{
	printf("%d",B.bi.b0);
	printf("%d",B.bi.b1);
 	printf("%d",B.bi.b2);
	printf("%d",B.bi.b3);
	printf("%d",B.bi.b4);
	printf("%d",B.bi.b5);
	printf("%d",B.bi.b6);
	printf("%d",B.bi.b7);
}

void decodificar(char *frase, char *tabela, tree *noP)
{
	FILE *Ptr = fopen(frase,"rb");
	FILE *PtrTab = fopen(tabela,"rb");
	byte B;
	int b, bt=0;
	tree *no = noP;
	char str[TF];
	
	printf("Frase Decodificada: ");
	fread(&B,sizeof(byte),1,Ptr);
	while(!feof(Ptr) && no != NULL)
	{
		if(bt == 8)
		{
			bt = 0;
			fread(&B,sizeof(byte),1,Ptr);
		}
		if(!feof(Ptr))
		{
			if(bt == 0)
			{
				b = B.bi.b0;
			}
			else
			{
				if(bt == 1)
				{
					b = B.bi.b1;
				}
				else
				{
					if(bt == 2)
					{
						b = B.bi.b2;
					}
					else
					{
						if(bt == 3)
						{
							b = B.bi.b3;	
						}
						else
						{
							if(bt == 4)
							{
								b = B.bi.b4;
							}
							else
							{
								if(bt == 5)
								{
									b = B.bi.b5;
								}
								else
								{
									if(bt == 6)
									{
										b = B.bi.b6;
									}
									else
									{
										b = B.bi.b7;
									}
									
								}
							}
						}
					}
				}
			}
			bt++;
			
			if(b < 1)
				no = no->esq;
			else
				no = no->dir;
				
			if(no != NULL)
			{
				if(no->simb != '!')
				{
					BuscaTabela(PtrTab,no->simb,str);
					no = noP;
				}
			}
		}
	}
	fclose(Ptr);
	fclose(PtrTab);
	
	printf("%s",str);
	
}

void imprimirTabela(char *nome)
{
	FILE *PtrTab = fopen(nome,"rb");
	Tabela tab;
	
	fread(&tab,sizeof(Tabela),1,PtrTab);
	while(!feof(PtrTab))
	{
		printf("%d  ",tab.simbo);
		printf("%s      ",tab.palavra);
		printf("%s",tab.codHuff);
		printf("\n");
		fread(&tab,sizeof(Tabela),1,PtrTab);
	}
	fclose(PtrTab);
}

void imprimirFrase(char *nome)
{
	FILE *Ptr = fopen(nome,"rb");
	byte B;
	
	printf("\nFrase Codificada: ");
	
	fread(&B,sizeof(byte),1,Ptr);
	while(!feof(Ptr))
	{
		mostrar(B);
		fread(&B,sizeof(byte),1,Ptr);
	}
	fclose(Ptr);
	printf("\n");
}

int main()
{
	Tree *no = NULL;
	no = Caixa('!');
	
//	imprimirTabela("Tabela");
	imprimirFrase("fraseCodificada");
	CriarArvore(&no,"Tabela");
	decodificar("fraseCodificada","Tabela",no);
	
}
