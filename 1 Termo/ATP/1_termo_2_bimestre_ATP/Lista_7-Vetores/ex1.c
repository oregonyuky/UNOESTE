#include <stdio.h>
int main(){
    int i, vet1[100], vet2[100], vet3[20];
    for(i=0;i<10;i++){
        scanf("%d", &vet1[i]);
    }
    for(i=10;i<20;i++){
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<20;i++){
        if(i<10)
            vet3[i] = vet1[i];
        else
            vet3[i] = vet2[i];
    }
    for(i=0;i<20;i++){
        printf("%d ", vet3[i]);
    }
    return 0;
}