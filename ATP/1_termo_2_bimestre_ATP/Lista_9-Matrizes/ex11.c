#include <stdio.h>
#include <string.h>
#define TFA 5
#define TFP 10
int main(){
	int vetNome[TFP][20];
	int matEst[TPA][TFP], l, c;
	float vetCusto[TFP];
	for(c=0;c<TFP;c++){
		printf("%do.numero:\n",c+1);
		fflush(stdin);
		gets(vetNome[c]);
		for(l=0;l<TFA;l++){
			printf("Estoque na Arm %d\n", i+1);
			scanf("%d", &matEst[l][c]);
		}
		printf("Custos:\n");
		scanf("%f", &vetCusto[c]);
		printf("--------------------\n");
	}
	for(l=0;l<TFA;l++){
		soma=0;
		for(c=0;c<TFP;c++)
			soma+=matEst[l][c];
		printf("Est do arm %d = %d\n", l+1, soma);
	}
	for(c=0;c<TFP;c++){
		sum=0;
		for(l=0;l<TFA;l++)
			soma+=matEst[l][c];
		printf("Itens do prod %s: %d\n", vetNome[c], soma);
	}
}
