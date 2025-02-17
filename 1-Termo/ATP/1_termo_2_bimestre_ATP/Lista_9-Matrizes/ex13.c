#include <stdio.h>
int main(){
    int junho[5][5], julho[5][5], agosto[5][5], produto[5]={0}, soma[5]={0};
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &junho[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &julho[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &agosto[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        printf("loja %d:\n",i+1);
        for(int j=0;j<5;j++){
            printf("Produto %d: %d estoques\n", j+1, junho[j][i]+julho[j][i]+agosto[j][i]);
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            produto[i] += junho[i][j]+julho[i][j]+agosto[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            soma[i] += junho[j][i]+julho[j][i]+agosto[j][i];
        }
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("Total vendido de produto %d: %d estoques\n", i+1, produto[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("Total vendido de loja %d: %d estoques\n",i+1, soma[i]);
    }
    return 0;
}