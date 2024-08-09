#include <stdio.h>
#include <string.h>
#define TFA 5
#define TFP 10
int main(){
	int vetNome[TFP][20], soma, somaC, sum, maior, menor;
	int matEst[TFA][TFP], l, c;
	float vetCusto[TFP];
	for(c=0;c<TFP;c++){
		printf("%do.numero:\n",c+1);
		fflush(stdin);
		gets(vetNome[c]);
		for(l=0;l<TFA;l++){
			printf("Estoque na Arm %d\n", l+1);
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
	for(l=0;l<TFA;l++){
		somaC=0;
		for(c=0;c<TFP;c++){
			soma+=matEst[l][c]*vetCusto[c];
		}
		printf("Custo do arm %d: %.2f\n", l+1, somaC);
	}
	menor = maior = matEst[0][0];
	for(i=0;i<TFA;i++){
		for(c=0;c<TFP;c++){
			if(matEst[l][c]<menor){
				menor = matEst[l][c];
			}
			if(matEst[l][c] > maior)
				maior = matEst[l][c];
		}
		for(l=0;l<TFA;l++){
			for(c=0;c<TFP;c++){
				if(matEst[l][c]==menor)
					printf("Produto %s Arm %d tem o menor estoque\n", vetNoome[c], l+1);
			}
		}
	}
	for(l=0;l<TFA;l++){
		for(c=0;c<TFP;c++){
			if(matEst[l][c]==maior)
				printf("prod %s Arm %d tem o maior estoque\n", vetNome[c], l+1);;
		}
	}
}
