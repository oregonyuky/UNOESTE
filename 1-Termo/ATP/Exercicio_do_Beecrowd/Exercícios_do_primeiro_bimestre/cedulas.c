#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    int notade100 = a / 100;
    int notade50 = (a % 100) / 50;
    int notade20 = ((a % 100) % 50) / 20;
    int notade10 = (((a % 100) % 50) % 20) / 10;
    int notade5 = ((((a % 100) % 50) % 20) % 10) / 5;
    int notade2 = (((((a % 100) % 50) % 20) % 10) % 5) / 2;
    int notade1 = (((((a % 100) % 50) % 20) % 10) % 5) % 2;
    printf("%d\n", a);
    printf("%d nota(s) de R$ 100,00\n", notade100);
    printf("%d nota(s) de R$ 50,00\n", notade50);
    printf("%d nota(s) de R$ 20,00\n", notade20);
    printf("%d nota(s) de R$ 10,00\n", notade10);
    printf("%d nota(s) de R$ 5,00\n", notade5);
    printf("%d nota(s) de R$ 2,00\n", notade2);
    printf("%d nota(s) de R$ 1,00\n", notade1);
    return 0;
}