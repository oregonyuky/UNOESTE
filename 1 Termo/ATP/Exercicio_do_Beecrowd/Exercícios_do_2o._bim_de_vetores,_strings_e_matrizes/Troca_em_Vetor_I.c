#include <stdio.h>
int main(){
    int array[20];
    int a, i, j=0;
    for(i=0;i<20;i++){
        scanf("%d", &array[i]);
    }
    for(i=19;i>=0;i--){
        printf("N[%d] = %d\n", j, array[i]);
        j++;
    }
    return 0;
}
