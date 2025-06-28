#include <stdio.h>
#include <stdlib.h>
void exemplo1(){
    int num;
    int *p;
    num = 10;
    p = &num;
    printf("Endereco de p: %p\n", (void *)p);
    printf("Conteudo de p: %d\n", *p);
}
void exemplo2(){
    int *p, *v;
    float *m;
    v = (int *)malloc(sizeof(int));
    m = new float();
    *v = 150;
    *m = 5.5;
    printf("%d \n", *v);
    p = v;
    printf("%d\n", *p);
    float *s;
    s = (float *)malloc(sizeof(float));
    s = m;
    printf("%.1f\n", *s);
}
int main(){
    exemplo1();
    exemplo2();
}
