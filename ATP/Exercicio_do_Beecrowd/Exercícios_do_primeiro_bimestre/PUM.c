#include <stdio.h>
int main(){
    int a;
    int k=1;
    scanf("%d", &a);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=3;j++){
            if(k%4==0)k++;
            printf("%d ", k);
            k++;
        }
        printf("PUM\n");
    }
}