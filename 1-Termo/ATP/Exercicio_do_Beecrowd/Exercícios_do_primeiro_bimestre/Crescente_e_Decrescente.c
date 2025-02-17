#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
    int a, b;
    int aux;
    while(true){
        scanf("%d %d", &a, &b);
        if(a == b)break;
        if(a>b){
            printf("Decrescente\n");
        }
        else if(b>a){
            printf("Crescente\n");
        }
    }
    return 0;

}