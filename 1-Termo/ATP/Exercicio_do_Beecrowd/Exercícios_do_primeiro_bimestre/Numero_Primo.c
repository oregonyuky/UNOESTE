#include <stdio.h>
#include <stdbool.h>
bool primo(int x){
	int i;
	if(x<=1){
		return false;
	}
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int a, b;
	scanf("%d", &a);
	while(a!=0){
		a--;
		scanf("%d", &b);
		if(primo(b))printf("%d eh primo\n", b);
		else{
			printf("%d nao eh primo\n", b);
		}
		
	}
	return 0;
}