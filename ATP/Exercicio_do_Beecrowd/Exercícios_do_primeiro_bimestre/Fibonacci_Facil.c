#include <stdio.h>
#include <math.h>
int main(){
    int a;
    scanf("%d", &a);
    for(int i=0;i<a;i++){
        printf("%.0lf", (pow((1+sqrt(5))/2.0, i) - pow((1-sqrt(5))/2.0, i))/sqrt(5));
        if(i<a-1){
            printf(" ");
        } else {
            printf("\n");
        }

    }
    return 0;
}