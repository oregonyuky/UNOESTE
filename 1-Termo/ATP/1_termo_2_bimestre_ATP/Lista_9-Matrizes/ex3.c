#include <stdio.h>
int main(){
	int vet[5][5], vendas[5]={0}, vendas2[5]={0}, total=0, semana[5]={0},k=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("Digite o dia %d:\n", k);
			scanf("%d", &vet[i][j]);
			vendas[i] += vet[i][j];
			k++;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++)
			semana[i] += vet[j][i];
	}
	for(int i=0;i<5;i++){
		printf("Total de vendas do mes do vendedor %d: %d\n", i+1, semana[i]);
		total+=semana[i];
	}
	for(int i=0;i<4;i++){
		printf("Total de vendas da semana %d: %d\n", i+1, vendas[i]);
	}
	printf("total de vendas do mes: %d\n", total);
	return 0;
}
