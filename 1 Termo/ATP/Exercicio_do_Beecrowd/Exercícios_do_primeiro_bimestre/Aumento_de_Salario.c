#include <stdio.h>
typedef struct salario{
    float porcentagem1;
    float porcentagem2;
    float porcentagem3;
    float porcentagem4;
    float porcentagem5;
}status;
int main(){
    status record;
    record.porcentagem1 = 15.0;
    record.porcentagem2 = 12.0;
    record.porcentagem3 = 10.0;
    record.porcentagem4 = 7.0;
    record.porcentagem5 = 4.0;
    float a;
    float b = 100.0;
    scanf("%f", &a);
    float result, result1;
    if(a>=0 && a<=400){
        result = a*record.porcentagem1/b;
        result1 = result+a;
    }
    else if(a>400 && a<=800){
        result = a*record.porcentagem2/b;
        result1 = result+a;
    }
    else if(a>800 && a<=1200){
        result = a*record.porcentagem3/b;
        result1 = result+a;
    }
    else if(a>1200 && a<=2000){
        result = a*record.porcentagem4/b;
        result1 = result+a;
    }
    else if(a>2000){
        result = a*record.porcentagem5/b;
        result1 = result+a;
    }
    printf("Novo salario: %.2f\n", result1);
    printf("Reajuste ganho: %.2f\n", result);
    printf("Em percentual: %.0f %%\n", result*b/a);
    return 0;
}