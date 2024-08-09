#include <stdio.h>
#include <math.h>
int main(){
    int i;
    int a;
    scanf("%d", &a);
    for(i=1;i<=a;i++){
        int quadrado = pow(i, 2);
        int cubo = pow(i, 3);
        printf("%d %d %d\n", i, quadrado, cubo);
        printf("%d %d %d\n", i, quadrado+1, cubo+1);
    }
    return 0;
}