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
