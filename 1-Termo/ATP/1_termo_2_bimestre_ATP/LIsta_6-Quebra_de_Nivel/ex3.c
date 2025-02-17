#include <stdio.h>
int main()
{
	int soma=0, qtd, cod, maior_qtd, leitura=1;
	float preco_u, total_parcial, menor_preco, maior_parcial=0;
	char cor, maior_cor, menor_cor, maior_cor_parcial;
	printf("Digite o codigo da roupa: \n");
	scanf("%d", &cod);
	while (cod>0)
	{
		total_parcial=0;
		soma=0;
		maior_qtd=0;
		printf("Digite a cor da roupa: \n");
		fflush(stdin);
		scanf("%c", &cor);
		while (cor!='\n')
		{
			printf("Digite a quantidade de roupas: \n");
			scanf("%d", &qtd);
			printf("Digite o preco unitario: \n");
			scanf("%f", &preco_u);
			total_parcial=preco_u*qtd;
			printf("O total parcial e %.2f \n", total_parcial);
			soma+=qtd;
			if (qtd>maior_qtd)
			{
				maior_qtd=qtd;
				maior_cor=cor;
			}
			if (leitura==1)
			{
				menor_preco=preco_u;
				menor_cor=cor;
			}
			else if (preco_u<menor_preco)
			{
				menor_preco=preco_u;
				menor_cor=cor;
			}
			if (total_parcial>maior_parcial)
			{
				maior_parcial=total_parcial;
				maior_cor_parcial=cor;
			}
			printf("Digite a cor da roupa: \n");
			fflush(stdin);
			scanf("%c", &cor);
		}
		printf("A quantidade desses tipos de roupas e %d \n", soma);
		printf("A cor que obteve a maior quantidade vendida em cada tipo de roupa e %c \n", maior_cor);
		printf("A cor do menor preco unitario em cada tipo de roupa e %c \n", menor_cor);
		printf("Digite o codigo da roupa: \n");
		scanf("%d", &cod);
	}
	printf("O tipo de roupa que obteve um maior total foi %c \n", maior_cor_parcial);
	return 0;
}