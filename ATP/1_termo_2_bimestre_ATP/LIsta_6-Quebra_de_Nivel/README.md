
<img src="https://github.com/oregonyuky/ATP/assets/152916454/4cdedb63-b06a-4d16-b141-5a31893ae6d3.png" width="410"/>  <img src="https://github.com/oregonyuky/ATP/assets/152916454/66eaedb2-a968-4275-ac4b-153afd22d15a.png" width="410"/>
## Ex1
```c
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
```
## Ex2
```c
#include <stdio.h>
int main(){
    int lab, aluno, num, micro, tempo, menor, ra, l=1, maior,
         maior_lab, menor_ra, mulheres, homens, total_aluno;
    char sexo;
    maior=0;
    total_aluno=0;
    homens=0;
    printf("Digite o numero do laboratorio:");
    scanf("%d", &lab);
    while(lab>0){
        aluno=0;
        mulheres=0;
        l=1;
        printf("Digite o Num.Micro:\n");
        scanf("%d", &num);
        while(num>0){
            printf("Digite o RA:\n");
            scanf("%d", &ra);
            printf("Digite o sexo:\n");
            scanf(" %c", &sexo);
            printf("Digite o tempo:\n");
            scanf("%d", &tempo);
            aluno++;
            if(l==1){
                menor = tempo;
                menor_ra = ra;
            }
            l=0;
            if(menor > tempo){
                menor = tempo;
                menor_ra = ra;
            }
            if(sexo == 'F')mulheres++;
            else homens++;
            printf("Digite o Num.micro:\n");
            scanf("%d", &num);
        }
        printf("Laboratorio %d o aluno com RA %d possui menos tempo com %d\n", lab, menor_ra, menor);
        printf("A porcentagem de mulheres em cada laboratorio: %.2f%%\n", (float)mulheres*100/aluno);
        if(maior < aluno){
            maior = aluno;
            maior_lab = lab;
        }
        total_aluno += aluno;
        printf("Digite o numero do laboratorio:");
        scanf("%d", &lab);
    }
    printf("Porcentagem de homens entre todos os laboratorios:%.2f%%\n", (float)homens*100/total_aluno);
    printf("laboratorio %d possui mais qtd de alunos: %d\n", maior_lab, maior);

}
```
## Ex3
```c
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
```

