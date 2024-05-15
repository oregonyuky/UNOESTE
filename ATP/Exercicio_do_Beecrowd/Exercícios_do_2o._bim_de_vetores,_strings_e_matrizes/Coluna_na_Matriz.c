#include <stdio.h>
#define max 12
int main(){
    int a, b, c, d, e;
    float soma=0, soma1=0, numero[max][max], soma2=0;
    char letra;
    scanf("%d", &a);
    scanf(" %c", &letra);
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            scanf("%f", &numero[i][j]);
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            soma+=numero[i][j];
        }
    }
    if(letra=='S'){
        for(int j=0;j<max;j++){
            soma1+=numero[j][a];
        }
        printf("%.1f\n", soma1);
    } else if(letra=='M'){
        for(int j=0;j<max;j++){
            soma2+=numero[j][a];
        }
        printf("%.1f\n", soma2/max);
    }
    return 0;
}
