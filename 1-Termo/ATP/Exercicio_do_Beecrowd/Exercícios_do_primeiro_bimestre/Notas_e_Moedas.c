#include <stdio.h>
int main(){
    double n;
    scanf("%lf", &n);
    int nu = n*100;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", nu/10000);
    nu%=10000;
    printf("%d nota(s) de R$ 50.00\n", nu/5000);
    nu%=5000;
    printf("%d nota(s) de R$ 20.00\n", nu/2000);
    nu%=2000;
    printf("%d nota(s) de R$ 10.00\n", nu/1000);
    nu%=1000;
    printf("%d nota(s) de R$ 5.00\n", nu/500);
    nu%=500;
    printf("%d nota(s) de R$ 2.00\n", nu/200);
    nu%=200;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", nu/100);
    nu%=100;
    printf("%d moeda(s) de R$ 0.50\n", nu/50);
    nu%=50;
    printf("%d moeda(s) de R$ 0.25\n", nu/25);
    nu%=25;
    printf("%d moeda(s) de R$ 0.10\n", nu/10);
    nu%=10;
    printf("%d moeda(s) de R$ 0.05\n", nu/5);
    nu%=5;
    printf("%d moeda(s) de R$ 0.01\n", nu);
    return 0;
}