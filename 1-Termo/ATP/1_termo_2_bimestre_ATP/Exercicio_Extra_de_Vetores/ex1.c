#include <stdio.h>
#define TF 11
int main(){
    int vetCPF[TF], i, a=10, b=11, soma=0, res, res1;
    for(i=0;i<TF;i++){
        scanf("%d", &vetCPF[i]);
    }
    for(i=0;i<9;i++){
        soma += vetCPF[i]*a;
        a--;
    }
    res = 11 - (soma%11);
    if(res==10 || res==11)res=0;
    soma=0;
    for(i=0;i<10;i++){
        soma += vetCPF[i]*b;
        b--;
    }
    res1 = 11 - (soma%11);
    if(res1==10 || res1==11)res1=0;
    if(vetCPF[9]==res && vetCPF[10]==res1)
        printf("CPF correto\n");
    else
        printf("CPF incorreto\n");
    return 0;
}