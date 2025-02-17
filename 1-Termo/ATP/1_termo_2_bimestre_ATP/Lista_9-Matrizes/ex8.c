#include <stdio.h>
int main(){
    int n, m, k, l, vet[100][100], vet1[100][100];
    printf("digite o n:\n");
    scanf("%d", &n);
    printf("digite o m:\n");
    scanf("%d", &m);
    printf("digite o k:\n");
    scanf("%d", &k);
    printf("digite o l:\n");
    scanf("%d", &l);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            scanf("%d", &vet1[i][j]);
        }
    }
    if(n==k && m==l){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vet[i][j] *= vet1[i][j];
            }
        }
        printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ", vet[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("nao da para multiplicar\n");
    return 0;
}