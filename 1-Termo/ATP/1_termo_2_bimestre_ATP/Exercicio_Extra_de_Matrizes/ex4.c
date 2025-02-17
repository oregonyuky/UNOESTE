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
