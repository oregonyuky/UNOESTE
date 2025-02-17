#include <stdio.h>
#include <math.h>
int main(){
    float a;
    scanf("%f", &a);
    float result=0;
    if(a<=2000){
        printf("Isento\n");
    }
    else if(a>2000 && a<=3000){
        result = (a - 2000)*0.08;
        printf("R$ %.2f\n", result);
    }
    else if(a>3000 && a<=4500){
        result = 1000*0.08 + (a-3000)*0.18;
        printf("R$ %.2f\n", result);
    }
    else if(a>4500){
        result = 1000*0.08 + 1500*0.18 + (a-4500)*0.28; 
        printf("R$ %.2f\n", result);
    }
    return 0;
}