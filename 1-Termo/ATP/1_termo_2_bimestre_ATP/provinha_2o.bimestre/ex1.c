#include <stdio.h>
#define TF 30
int main()
{
	int vetprod[TF], vetestoque[TF], vetprodSE[TF], pos, i, cod, prod, TLP=0, TLZ=0, op, qtd;
	float vetpreco[TF];
	printf("1-Cadastrar um produto\n2-Realizar uma venda\n0-Sair\n");
	scanf("%d", &op);
	while (op!=0)
	{
		if (op==1)
		{
			if (TLP<TF)
			{
				printf("Codigo do produto:\n");
				scanf("%d", &cod);
				pos=0;
				while (pos<TLP && cod > vetprod[pos])
					pos++;
				if (pos == TLP || cod!=vetprod[pos])
				{
					for (i=TLP; i>pos; i--)
					{
						vetprod[i] = vetprod[i-1];
						vetpreco[i] = vetpreco[i-1];
						vetestoque[i] = vetestoque[i-1];
					}
					vetprod[pos] = cod;
					printf("Preco:\n");
					scanf("%f", &vetpreco[pos]);
					printf("Estoque:\n");
					scanf("%d", &vetestoque[pos]);
					TLP++;
				}
				else
					printf("Codigo produto ja existe\n");
			}
			else
				printf("Sem espaco\n");
		}
		else if (op==2)
		{
			printf("Codigo para venda:\n");
			scanf("%d", &cod);
			pos=0;
			while (pos<TLP && cod!=vetprod[pos])
				pos++;
			if (pos<TLP)
			{
				printf("Quantidade:\n");
				scanf("%d", &qtd);
				if (qtd<=vetestoque[pos])
				{
					vetestoque[pos] = vetestoque[pos] - qtd;
					if (vetestoque[pos]==0)
					{
						if (TLZ<TF)
						{
							vetprodSE[TLZ] = cod;
							TLZ++;
						}
						for (i=pos; i<TLP-1; i++)
						{
							vetprod[i] = vetprod[i+1];
							vetpreco[i] = vetpreco[i+1];
							vetestoque[i] = vetestoque[i+1];
						}
						TLP--;
					}
				}
				else
					printf("Nao tem quantidade suficiente\n");
			}
			else
				printf("Codigo nao encontrado\n");
		}
		printf("1-Cadastrar um produto\n2-Realizar uma venda\n0-Sair\n");
		scanf("%d", &op);
	}
	for (i=0; i<TLP; i++)
		printf("Prod=%d, Preco=%.2f, Estoque=%d\n", vetprod[i], vetpreco[i], vetestoque[i]);
	for (i=0; i<TLZ; i++)
		printf("Prod=%d\n", vetprodSE[i]);
	return 0;
}