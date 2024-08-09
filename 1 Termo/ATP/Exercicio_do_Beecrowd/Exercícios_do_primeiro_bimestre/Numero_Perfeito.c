#include <stdio.h>
#include <string.h>
int main(){
	int a, b, i, k, condicao;
	int soma=0;
	scanf("%d", &condicao);
	while(condicao != 0){
		condicao--;
		scanf("%d", &b);
		for(k=1;k<b;k++){
			if(b%k==0){
				soma+=k;
			}
		}	
		if(soma==b){
			printf("%d eh perfeito\n", b);
			soma=0;
		} else {
			printf("%d nao eh perfeito\n", b);
			soma=0;
		}
	}
	return 0;
}