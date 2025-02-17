#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    int NF, cod, qtd, maior_qtd, cod_maior, menor_qtd=INT_MAX, cod_menor, cod_menorp, cod_maiorp, cod_menorNF;
    float total_vendas=0, preco_u, total, total_NF, menor_preco=FLT_MAX, maior_preco=0, menorNF= FLT_MAX;
    printf("Nota fiscal:\n");
    scanf("%d", &NF);
    while (NF>0)
    {
        total_NF=0;
        maior_qtd=0;
        printf("Codigo produto:\n");
        scanf("%d", &cod);
        while(cod>0)
        {
            printf("Quantidade:\n");
            scanf("%d", &qtd);
            printf("Preco unitario:\n");
            scanf("%f",&preco_u);
            total = qtd*preco_u;
            printf("Total: %.2f\n", total);
            total_NF+=total;
            if (qtd>maior_qtd)
            {
            	maior_qtd=qtd;
            	cod_maior=cod;
            }
            if (qtd<menor_qtd)
            {
            	menor_qtd=qtd;
            	cod_menor=cod;
            }
            if (preco_u<menor_preco)
            {
            	menor_preco=preco_u;
            	cod_menorp=cod;
            }
            if (preco_u>maior_preco)
            {
            	maior_preco=preco_u;
            	cod_maiorp = cod;
            }
            if (total_NF < menorNF)
            {
            	menorNF = total_NF;
            	cod_menorNF = NF;
            	
            }
            printf("Codigo produto:\n");
            scanf("%d", &cod);
            
        }
        printf("Total de vendas dessa nota fiscal:%.2f\n", total_NF);
        total_vendas+=total_NF;
        printf("O codigo %d tem a maior quantidade vendida em cada nota fiscal com %d unidades\n", cod_maior, maior_qtd);
        printf("O produto %d tem o menor preco com %.2f\n", cod_menorp, menor_preco);
        printf("Nota fiscal:\n");
        scanf("%d", &NF);
        
    }
    printf("Total vendas: %.2f\n", total_vendas);
    printf("O produto %d tem a menor quantidade vendida entre todas as notas fiscais com %d unidades\n", cod_menor, menor_qtd);
    printf("O produto %d tem o maior preco entre todas as notas fiscais com %.2f\n", cod_maiorp, maior_preco);
    printf("A nota fiscal que obteve a menor nota foi %d\n", cod_menorNF);
    return 0;
}