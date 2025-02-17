#include <stdio.h>
#include <math.h>
double fibonaci(double x){
    return (pow((1+sqrt(5))/2.0, x)-pow((1-sqrt(5))/2.0, x))/sqrt(5);
}
int main(){
    double a;
    int b;
    scanf("%d", &b);
    while(b!=0){
        b--;
        scanf("%lf", &a);
        printf("Fib(%.0lf) = %.0lf\n",a ,fibonaci(a));
    }
        return 0;

}
