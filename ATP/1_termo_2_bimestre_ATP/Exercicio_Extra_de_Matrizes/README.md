## Ex 1
```c
#include <stdio.h>
int main(){
    int ma[100][100],linha,numCid,codCid[100],somaDist,flag=0,maior,menor,me_linha,ma_linha;
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            scanf("%d", &ma[i][j]);
            ma[j][i] = ma[i][j];
            ma[i][i] = 0;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ", ma[i][j]);
        }
        printf("\n");
    }

    printf("digite o numero da linha:\n");
    scanf("%d", &linha);
    while(linha!=9999){
        somaDist=0;
        printf("digite numero da cidade percorrida:\n");
        scanf("%d", &numCid);
        for(int i=0;i<numCid;i++){
            printf("digite o codigo da cidade:\n");
            scanf("%d", &codCid[i]);
        }
        for(int i=0;i<numCid-1;i++){
            somaDist += ma[codCid[i]][codCid[i+1]];
        }
        printf("a distancia percorida eh %d\n", somaDist);
        if(flag==0){
            menor = maior = somaDist;
            me_linha = ma_linha = linha;
        }
        flag=1;
        if(menor>somaDist){
            menor = somaDist;
            me_linha = linha;
        }
        if(maior<somaDist){
            maior = somaDist;
            ma_linha = linha;
        }
        printf("digite o numero da linha:\n");
        scanf("%d", &linha);
    }
    printf("maior linha foi %d\n", maior);
    printf("menor linha foi %d\n", menor);
    return 0;
}
```
## Ex 2
```c
#include <stdio.h>
#define T 6
void letra_a(){
    int soma=0, k=0, vet[T][T], flag=0, menor;
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            if(i+j>=T-1){
                if(flag==0){
                    menor = vet[i][j];
                }
                flag=1;
                if(menor>vet[i][j])menor = vet[i][j];
                soma+=vet[i][j];
                k++;
            }
        }
    }
    printf("menor elemento: %d\n", menor);
    printf("media: %.2f\n", (float)soma/k);
}
void letra_b(){
    int vet[100][100], menor, flag=0, soma=0, k=0;
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            if(j>i && j<T/2 && i<T/2-1){
                soma+=vet[i][j];
                k++;
            }
            else if(i+j<T-1 && j>=T/2 && i<T/2-1){
                soma+=vet[i][j];
                k++;
            }
            if(i+j>=T && i>T/2 && j<T/2){
                soma+=vet[i][j];
                k++;
            }
            else if(i>j && j>=T/2 && i>T/2){
                soma+=vet[i][j];
                k++;
            }
        }
    }
        
    
    printf("%d\n", soma);
    printf("media: %.2f\n", (float)soma/k);
}
int main(){
    letra_b();
    return 0;
}
```
## Ex 3
```c
#include <stdio.h>
#define LINHAS 5
#define COLUNAS 7
int main() {
    int matriz[LINHAS][COLUNAS] = {
        {1, 2, 3, 4, 5, 6, 7},
        {2, 3, 4, 5, 6, 7, 8},
        {13, 14, 15, 10, 15, 14, 13},
        {4, 5, 6, 7, 8, 9, 10},
        {5, 6, 7, 8, 9, 10, 11}
    };
    int i, j, k;
    int ponto_de_sela_encontrado = 0;
    printf("A matriz fornecida é:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nPontos de sela:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            int elemento = matriz[i][j];
            int menor_na_linha = 1;
            int maior_na_coluna = 1;
            for (k = 0; k < COLUNAS; k++) {
                if (matriz[i][k] < elemento) {
                    menor_na_linha = 0;
                    break;
                }
            }
            for (k = 0; k < LINHAS; k++) {
                if (matriz[k][j] > elemento) {
                    maior_na_coluna = 0;
                    break;
                }
            }
            if (menor_na_linha && maior_na_coluna) {
                printf("Ponto de sela encontrado em (%d, %d): %d\n", i, j, elemento);
                ponto_de_sela_encontrado = 1;
            }
        }
    }
    if (!ponto_de_sela_encontrado) {
        printf("Nenhum ponto de sela encontrado na matriz.\n");
    }
    return 0;
}
```
## Ex 4
```c
#include <stdio.h>
#define TF 18
int main ()
{
	int TL,l,c,i,matriz[TF][TF];
	printf("Digite o tamanho da matriz\n");
	scanf("%d",&TL);
	
	i=1;
	for(l=0;l<TL-1;l++)
	{
		for(c=l;c<TL-l;c++)
		{
			matriz[c][l]=i;
			matriz[l][c]=i;
			matriz[TL-1-l][c]=i;
			matriz[c][TL-1-l]=i;
		}
		i++;
	}
	
	for(i=0;i<TL;i++)
	{
		for(l=0;l<TL;l++)
		{
			printf(" %d ",matriz[i][l]);
		}
		printf("\n");	
	}
	
	return 0;
}
```