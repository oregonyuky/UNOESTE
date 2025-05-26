#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void Ex1(){
    double a, b, n, h, s, s1, s2, s3;
    double ar[6] = {0, 0.2, 0.4, 0.6, 0.8, 1};
    a = 0;
    b = 1;
    n = 5;
    h = (b-a)/n;
    s = s1 = s2 = s3 = 0.0;
    for(double i=0;i<1;i+=0.2){
        s += i*i;
    }
    for(double i=0.2;i<=1;i+=0.2)
        s1 += i*i;
    int j=0;
    for(int i=0;i<5;i++){
        ar[i] = (ar[i]+ar[i+1])/2;
        s2 += ar[i]*ar[i];
    }
    for(int i=1;i<5;i++){
        s3 += ar[i]*ar[i];
        s3 = trunc(s3*1000)/1000;
    }
    printf("referencia x0 = %.3lf\n", h*s);
    printf("referencia x1 = %.3lf\n", h*s1);
    printf("referencia media = %.3lf\n", h*s2);
    printf("trapezio = %.3lf\n", h*((0*0+1*1)/2 + s3));
}
double f(double x){
    return 1/(x*x);
}
void Ex3(){
    double a, b, c, h, arr[100], s=0, s1=0, s2=0, s3=0;
    int n;
    n = 10;
    a = 1;
    b = 2;
    h = (b-a)/n;
    int j=0;
    for(double i=a;i<=b;i+=h)
        arr[j++] = i;
    arr[n] = b;
    for(int i=0;i<=j;i++)printf("%.3lf ", arr[i]);
    for(int i=0;i<n;i++){
        s += 1/(arr[i]*arr[i]);
        s = trunc(s*1000)/1000;
    }
    for(int i=1;i<=n;i++){
        s1 += 1/(arr[i]*arr[i]);
    }
    for(int i=0;i<n;i++){
        s2 += 1/(pow((arr[i]+arr[i+1])/2, 2));
    }
    for(int i=1;i<n-1;i++){
        s3 += 1/(arr[i]*arr[i]);
    }
    double fx0 = 1/(arr[0]*arr[0]);
    double fxn = 1/(arr[n]*arr[n]);
    //simpson
    double pares=0, impares=0;
    for(int i=2;i<=n/2;i++){
        pares += f(arr[2*i-2]);
    }
    for(int i=1;i<n/2;i++){
        impares += f(arr[2*i-1]);
    }
    printf("referencia x0 = %.3lf\n", h*s);
    printf("referencia x1 = %.3lf\n", h*s1);
    printf("referencia media = %.3lf\n", h*s2);
    printf("trapezio = %.3lf\n", h*((fx0+fxn)/2 + s3));
    printf("Simpson = %.3lf\n", h/3*(fx0 + fxn + 2*pares + 4*impares));

}
int main(){
    Ex3();
}