#include <stdio.h>
int main(){
    int vet[3][4], vet1[3][4], vet2[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            vet2[i][j] = vet[i][j] + vet1[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ", vet2[i][j]);
        }
        printf("\n");
    }
    return 0;
}