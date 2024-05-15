#include <stdio.h>
#define TF 5
int main(){
    int numVoo[TF], lugDisp[TF], idem, voo, res
    for(int i=0;i<TF;i++){
        printf("Digite o numVoo:\n");
        scanf("%d", &numVoo[i]);
    }
    for(int i=0;i<TF;i++){
        printf("Digite o lugares disponiveis do numVoo %d\n", numVoo[i]);
        scanf("%d", &lugDisp[i]);
    }
    printf("Digite o identidade:\n");
    scanf("%d", &idem);
    while(idem!=9999){
        printf("Digite o numero de voo:\n");
        scanf("%d", &voo);
        for(int i=0;i<TF;i++){
            if(numVoo[i]==voo){
                lugDisp[i]--;
                res= lugDisp[i];
                goto label;
            }
            else{
                printf("numero invalido\n");
            }
        }
        label:
        printf("numero de vagas:%d\n", res);
        printf("Digite o identidade:\n");
        scanf("%d", &idem);
    }
}