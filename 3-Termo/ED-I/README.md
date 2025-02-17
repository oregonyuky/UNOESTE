# Arquivo Texto
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

struct TpDado
{
	int Codigo;
	char Nome[50];
	float Valor;	
};

void LeNomeArq(char Nome[70])
{
	printf("Digite o Nome/Caminho do Arquivo: \n");
	fflush(stdin);
	gets(Nome);
}

void VerifArquivo(char NomeArq[70])
{
	FILE *PtrArq = fopen(NomeArq, "r");
	if (PtrArq == NULL)
	{
		printf("Arquivo nao existe, deseja cria-lo (S/N)?");
		if (toupper(getche())=='S')
		{
			PtrArq = fopen(NomeArq, "w");
			fclose(PtrArq);
			printf("Arquivo criado com sucesso!\n");
		}
	}
	else
	{
		fclose(PtrArq);
		printf("Arquivo OK!\n");
	}
	Sleep(1000);
}

char Menu(void)
{
	clrscr();
	printf("\n### Arquivo Texto ###\n");
	printf("\n[A] Inserir Texto (CHAR)");
	printf("\n[B] Exibir Texto (CHAR)");
	printf("\n[C] Inserir Texto (STRING)");
	printf("\n[D] Exibir Texto (STRING)");
	printf("\n[E] Inserir Texto (FORM)");
	printf("\n[F] Exibir Texto (FORM)");
	printf("\n[ESC] Finalizar\n");
	printf("Opcao: ");
	return toupper(getche());
}

void GerarArqTxt(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	char caracter;
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	printf("Digite um Texto e pressione ESC para finalizar: \n");
	caracter = getche();
	while(caracter!=27)
	{
		if(caracter == 13)
		{
			fputc('\n', PtrTxt);
			printf("\n");
		}
		else	
			fputc(caracter, PtrTxt);
		caracter = getche();
	}
	fclose(PtrTxt);
}

void ExibirArqTxt(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	char caracter;
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	caracter = fgetc(PtrTxt);
	while(!feof(PtrTxt))
	{
		printf("%c", caracter);
		Sleep(50);
		caracter = fgetc(PtrTxt);
	}
	getch();
	fclose(PtrTxt);
}

void GerarArqTxtSTR(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	char linha[80];
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	printf("Digite um Texto e pressione ENTER em uma LINHA VAZIA para finalizar: \n\n");
	fflush(stdin);
	gets(linha);
	while(strcmp(linha, "\0")!=0)
	{
		fputs(linha, PtrTxt);
		fputs("\n", PtrTxt); // gravou caracter 13 e 10 na frente
	
		fflush(stdin);
		gets(linha);
	}
	fclose(PtrTxt);
}

void ExibirArqTxtSTR(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	char linha[80];
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	fgets(linha, 80, PtrTxt);
	while(!feof(PtrTxt))
	{
		printf("%s", linha);
		Sleep(50);
		fgets(linha, 80, PtrTxt);
	}
	getch();
	fclose(PtrTxt);
}

void GerarArqTxtFORM(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	TpDado Reg;
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	printf("Digite os dados e ZERO no Codigo para finalizar: \n");
	printf("\nCodigo: ");
	scanf("%d", &Reg.Codigo);
	while(Reg.Codigo > 0)
	{
		printf("Nome: ");
		fflush(stdin);
		gets(Reg.Nome);
		printf("Valor: R$ ");
		scanf("%f", &Reg.Valor);
		fprintf(PtrTxt, "%d \t %s \t %.2f\n", Reg.Codigo, Reg.Nome, Reg.Valor);
		printf("\nCodigo: ");
		scanf("%d", &Reg.Codigo);
	}
	fclose(PtrTxt);
}

void ExibirArqTxtFORM(char NomeArquivo[70])
{
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	TpDado Reg;
	float Total = 0;
	clrscr();
	printf("Arquivo: %s\n", NomeArquivo);
	fscanf(PtrTxt, "%d%s%f", &Reg.Codigo, &Reg.Nome, &Reg.Valor);
	while(!feof(PtrTxt))
	{
		printf("%d \t %s \t %.2f\n", Reg.Codigo, Reg.Nome, Reg.Valor);
		Total += Reg.Valor;
		Sleep(50);
		fscanf(PtrTxt, "%d%s%f", &Reg.Codigo, &Reg.Nome, &Reg.Valor);
	}
	printf("\nTotal: R$ %.2f\n", Total);
	getch();
	fclose(PtrTxt);
}

int main(void)
{
	char Arquivo[70], opcao;
	do
	{
		opcao = Menu();
		clrscr();
		switch(opcao)
		{
			case 'A':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				GerarArqTxt(Arquivo);
				break;
			
			case 'B':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				ExibirArqTxt(Arquivo);
				break;
				
			case 'C':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				GerarArqTxtSTR(Arquivo);
				break;
				
			case 'D':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				ExibirArqTxtSTR(Arquivo);
				break;
				
			case 'E':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				GerarArqTxtFORM(Arquivo);
				break;
				
			case 'F':
				LeNomeArq(Arquivo);
				VerifArquivo(Arquivo);
				ExibirArqTxtFORM(Arquivo);
				break;
		}
	}while(opcao!=27);
	
	return 0;
}
```