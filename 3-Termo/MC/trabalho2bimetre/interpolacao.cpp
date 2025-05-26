#include <stdio.h>
#include <math.h>
#define e 2.71828
double trunc3(double x){
	return floor(x*1000)/1000;
}
double L0(double x, double x0, double x1, double x2){
	return (x-x1)*(x-x2)/((x0-x1)*(x0-x2));
}
double L1(double x, double x0, double x1, double x2){
	return (x-x0)*(x-x2)/((x1-x0)*(x1-x2));
}
double L2(double x, double x0, double x1, double x2){
	return (x-x0)*(x-x1)/((x2-x0)*(x2-x1));
}
double fex(double x){
	return pow(e, x);
}
void ex1(){
	double x0, x1, x2, fx, x;
	x0 = 2.8;
	x1 = 3.0;
	x2 = 3.2;
	x = 3.1;
	// f(x) = a + ax0 + ax1�2 + ax2�3
	fx = trunc(L0(x, x0, x1, x2)*fex(x0)) + trunc3(L1(x, x0, x1, x2)*fex(x1)) + trunc3(L2(x, x0, x1, x2)*fex(x2));
	printf("e(%.1lf) = %.3lf\n", x, trunc(fx*(int)1e3)/1e3);
}
void ex2(){
	double x, x0, x1, y0, y1, y;
	y = 0.23;
	x0 = 0.3;
	x1 = 0.35;
	y0 = 0.22;
	y1 = 0.25;
	x = x0 + (y-y0)/(y1-y0)*(x1-x0);
	printf("x = %.3lf\n", trunc(x*(int)1e3)/1e3);
}
int main(){
	ex1();
	ex2();
}
