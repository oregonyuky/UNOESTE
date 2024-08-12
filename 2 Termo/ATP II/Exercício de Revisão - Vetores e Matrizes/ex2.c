#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define TFC 30
#define TFP 10

int main(void)
{
	char vCliente[TFC][15], nome[15], vProduto[TFP][15], descricao[15];
	int TLC=0, TLP=0, posC, posP, i;
	
	char opcao;
	do
	{
		system("cls");
		printf("### M E N U ###\n");
		printf("[A] Cadastrar Clientes\n");
		printf("[B] Listar Clientes\n");
		printf("[C] Cadastrar Produtos\n");
		printf("[D] Listar Produtos\n");
		printf("[E] Vender Produtos\n");
		printf("[F] Listar Vendas Realizadas\n");
		printf("Pressione [Esc] para Sair\n");
		opcao = toupper(getch());
		switch(opcao)
		{
			case 'A': 
				system("cls");
				printf("### Cadastro de Clientes ###\n");
				printf("Nome do %do. Cliente:\n", TLC+1);
				gets(nome);
				while(TLC<TFC && strcmp(nome, "\0")!=0)
				{
					//buscar nome no vCliente (busca Exaustiva)
					posC = 0;
					while(posC<TLC && strcmp(vCliente[posC], nome)!=0)
						pos++;
						
					if(posC==TLC) //nao achou, insere!
					{
						//inserir o nome
						strcpy(vCliente[TLC], nome);
						TLC++;
					}
					else
						printf("Cliente ja cadastrado!\n");A
					
					if(TLC<TFC)
					{
						printf("Nome do %do. Cliente:\n", TLC+1);
						gets(nome);
					}
				}
				
				if(TLC==TFC)
					printf("Nao tem espaco para cadastrar mais Clientes!\n");
				
				printf("Fim de Cadastro de Clientes. Pressione [ENTER] para continuar\n");			
				getch();
				break;
			case 'B':
				system("cls");
				printf("### Relatorio de Clientes ###\n");
				for(i=0; i<TLC; i++)
				{
					printf("%d - %s\n",i, vCliente[i]);
				}
				printf("Pressione [ENTER] para continuar\n");
				getch();	
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				printf("### Venda de Produdos ###\n");
				printf("Nome do Cliente:\n");
				gets(nome);
				//busca nome no vCliente (busca Exaustiva)
				posC = 0;
				while(posC<TLC && strcmp(vCliente[posC], nome)!=0)
					posC++;
					
				if(posC<TLC) //achou o Cliente
				{
					printf("Descricao do Produto:\n");
					gets(descricao);
					//busca descricao no vProduto (busca Exaustiva)
					posP = 0;
					while(posP<TLP && strcmp(vProduto[posP], descricao)!=0)
						posp++;	
				
					if(posp<TLP) //achou o Produto
					{
						printf("Qunantidade:\n");
						scanf("%d",&quantidade);
						if(quantidade<=vEstoque[pos])
						{
							mVenda[TLV][0] = posC;
							mVenda[TLV][1] = pocP;
							mVenda[TLV][2] = quantidade;
							TLV++;
						}
						else
						{
							printf("Nao ha quantidade suficiente em Estoque!\n");
							printf("Existem %d unidades em Estoque\n",vEstoque[pos]);
						}
					}
					else
						printf("Produto nao encontrado!\n");
				}
				else
					printf("Cliente nao encontrado!\n");
				
				
				break;	
			
		}
		
	}while(opcao != 27);
	
	
	
}
