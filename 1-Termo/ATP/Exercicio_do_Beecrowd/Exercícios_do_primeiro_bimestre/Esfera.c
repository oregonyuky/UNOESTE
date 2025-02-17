#include <stdio.h>
#define PI 3.14159
int main(){
    double a;
    scanf("%lf", &a);
    printf("VOLUME = %.3lf\n", 4/3.0*a*a*a*PI);
    return 0;
}