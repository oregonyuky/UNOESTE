#include <stdio.h>
#define TF 5
int main(){
    int numVoo[TF], lugDisp[TF], idem, voo, res, bo, i, pos;
    for(i=0;i<TF;i++){
        printf("Digite o numVoo:\n");
        scanf("%d", &numVoo[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite o lugares disponiveis do numVoo %d\n", numVoo[i]);
        scanf("%d", &lugDisp[i]);
    }
    printf("Digite o identidade:\n");
    scanf("%d", &idem);
    while(idem!=9999){
		pos=0;
        printf("Digite o numero de voo:\n");
        scanf("%d", &voo);
			while(pos<TF && numVoo[pos]!=voo)
				pos++;
			if(pos==TF)
				printf("Nao foi encontrado\n");
			else{
				lugDisp[pos]--;
				printf("numero de vagas:%d\n", lugDisp[pos]);
			}
        printf("Digite o identidade:\n");
        scanf("%d", &idem);
    }
    return 0;
}
