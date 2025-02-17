 #include <stdio.h>
 int main(){
    int ma[3][3], maior=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &ma[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            maior = (maior < ma[i][j]) ? ma[i][j] : maior;
        }
    }
    printf("maior numero eh %d\n", maior);
    return 0;
 }