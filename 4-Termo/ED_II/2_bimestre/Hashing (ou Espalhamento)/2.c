#include <stdio.h>
#include <stdlib.h>

#define n 13

struct tpRegistro
{
	int numero;
	char nome[40];
	float salario;
	char status;
	int elo;
};

typedef struct tpRegistro Registro;

int hash(int numero)
{
	return numero % n;
}
void arqVazio(FILE* arq)
{
	Registro reg;
	int i;
	reg.numero = 0;
	reg.elo     = 0;
	for(i=0; i < n; i++)
		fwrite(&reg, sizeof(Registro), 1, arq);
}
void leReg(Registro* r)
{
	printf("TESTAR O TAMANHO Nome: "); fgets((*r).nome, sizeof((*r).nome), stdin);
	printf("Salario: "); scanf("%f", (*r).salario);
	(*r).status = 'T';
}
void buscaHash(FILE* arq, int numero, int* ender, char *achou)
{
	Registro aux;
	
	fseek(arq, sizeof(Registro)*(*ender), 0);
	fread(&aux, sizeof(Registro), 1, arq);
	while(aux.elo != 0 && aux.numero != numero)			//enquanto não encontrar o ultimo registro daquele indice ou um numero igual ao
	{													//que se pretende ser inserido.
		*ender = aux.elo;
		fseek(arq, sizeof(Registro)*(*ender), 0);
		fread(&aux, sizeof(Registro), 1, arq);		
	}
	if(aux.numero == numero)
		*achou = 1;
	else
		*achou = 0;
}
void insereHashArq()
{
	FILE* arq = fopen("arqivo.dat", "rb+");
	Registro reg, regDat;
	int ender = 0;
	char achou;
	
	if(arq == NULL)
		arqVazio(arq);
	printf("Numero: "); scanf("%d", &reg.numero); printf("\n");
	
	while(reg.numero > 0)
	{
		ender = hash(reg.numero);
		
		fseek(arq, sizeof(Registro)*ender, 0);
		fread(&regDat, sizeof(Registro), 1, arq);
		
		if(regDat.numero == 0) 						//local vazio
		{
			leReg(&reg);
			reg.status = 1;
			reg.elo    = 0;
			fseek(arq, ender * sizeof(Registro), 0);
			fwrite(&reg, sizeof(Registro), 1, arq);
		}
		else
		{
			buscaHash(arq, reg.numero, &ender, &achou);
			if(achou)
				printf("Numero ja existente!\n");
			else
			{
				leReg(&reg);
				reg.status = 1; reg.elo = 0;			
				fseek(arq, ender*sizeof(Registro), 0);
				fread(&regDat, sizeof(Registro), 1, arq);
				fseek(arq, 0, 2);
				regDat.elo = ftell(arq) / sizeof(Registro);
				fseek(arq, 0, 2);
				fwrite(&reg, sizeof(Registro), 1, arq);
			}
			printf("Numero: "); scanf("%d", &reg.numero); printf("\n");
		}
		fclose(arq);
	}
	
}
int main()
{
	insereArq();	
}

