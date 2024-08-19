#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define TFC 30
#define TFP 10
#define TFV 500

int main(void)
{
	char vCliente[TFC][15], nome[15], vProduto[TFP][15], descricao[15];
	int vEstoque[TFP], quantidade, mVenda[TFV][3];
	int TLC=0, TLP=0, TLV=0, posC, posP, i, cod;
	float vPreco[TFP], total, total_venda;
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
						posC++;
						
					if(posC==TLC) //nao achou, insere!
					{
						//inserir o nome
						strcpy(vCliente[TLC], nome);
						TLC++;
					}
					else
						printf("Cliente ja cadastrado!\n");
					
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
				system("cls");
				printf("### Cadastro de Produtos ###\n");
				printf("Descricao do %d. Produto:\n", TLP+1);
				gets(descricao);
				while(TLP<TFP && strcmp(descricao, "\0")!=0)
				{
					//busca descricao no vProduto (Busca Exaustiva)
					posP = 0;
					while(posP<TLP && strcmp(vProduto[posP], descricao)!=0)
						posP++;
						
					if(posP==TLP) //nao achou, insere!
					{
						strcpy(vProduto[TLP], descricao);
						printf("Preco do Produto:\n");
						scanf("%f",&vPreco[TLP]);
						printf("Estoque:\n");
						scanf("%d",&vEstoque[TLP]);
						TLP++;
					}
					else //Produto ja esta cadastrado
					{
						printf("Quantidade:\n");
						scanf("%d", &quantidade);
						vEstoque[posP] = vEstoque[posP] + quantidade;
					}
					
					if(TLP<TFP)
					{
						printf("Descricao do %d. Produto:\n", TLP+1);
						getchar();
						gets(descricao);
					}
				}
				if(TLP == TFP)
					printf("Nao tem mais espaco para cadastrar Produtos!\n");
				
				printf("Fim de Cadastro de Produtos! Pressione [ENTER] para continuar\n");	
				getch();
				break;
			case 'D':
				system("cls");
				printf("### Relatorio de Produtos ###\n");
				for(i=0; i<TLP; i++)
				{
					printf("%d - %s - %.2f - %d\n",i, vProduto[i], vPreco[i], vEstoque[i]);
				}
				printf("Pressione [ENTER] para continuar\n");
				getch();	
				break;
			case 'E':
				printf("### Venda de Produdos ###\n");
				do
				{
					total_venda = 0;
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
						while(strcmp(descricao, "\0")!=0)
						{
							//busca descricao no vProduto (busca Exaustiva)
							posP = 0;
							while(posP<TLP && strcmp(vProduto[posP], descricao)!=0)
								posP++;	
							
							if(posP<TLP) //achou o Produto
							{
								printf("Quantidade:\n");
								scanf("%d",&quantidade);
								if(quantidade<=vEstoque[posP])
								{
									mVenda[TLV][0] = posC;
									mVenda[TLV][1] = posP;
									mVenda[TLV][2] = quantidade;
									vEstoque[posP] = vEstoque[posP] - quantidade;
									total_venda = total_venda + quantidade * vPreco[posP];
									TLV++;
								}
								else
								{
									printf("Nao ha quantidade suficiente em Estoque!\n");
									printf("Existem %d unidades em Estoque\n",vEstoque[posP]);
								}
							}
							else
								printf("Produto nao encontrado!\n");
							
							printf("Descricao do Produto:\n");
							getchar();
							gets(descricao);
						}
					}
					else
						printf("Cliente nao encontrado!\n");
				
				
					printf("Total da Venda = %.2f\n", total_venda);
				
					printf("Deseja realizar uma nova venda S/N?\n");
					opcao = toupper(getch());
				}while(opcao == 'S');
			
				break;	
				
			case 'F':
				printf("### Relatorio de Vendas ###\n");
				cod = -1;
				total_venda = 0;
				for(i=0; i<TLV; i++)
				{
					if (cod != mVenda[i][0])
					{
						//Cliente: 2 - Zigfrida
						printf("Cliente: %d - %s\n", mVenda[i][0], vCliente[mVenda[i][0]]);
						cod = mVenda[i][0];
					}
					
					total = vPreco[mVenda[i][1]] * mVenda[i][2];
					total_venda = total_venda + total;
					printf("Produto: %d - %s\tPreco: %.2f\tQuantidade: %d\tTotal: %.2f\n", 
					       mVenda[i][1], vProduto[mVenda[i][1]], vPreco[mVenda[i][1]], mVenda[i][2], total);
					
					if(i+1 == TLV || mVenda[i+1][0]!=cod) //a proxima linha nao existe OU   diferente da atual
					{
						printf("Total da Venda: %.2f\n", total_venda);
						total_venda = 0;
					}
				}
				
				printf("Pressione [ENTER] para continuar\n");
				getch();
				
		}
		
	}while(opcao != 27);
	
	
	
}
