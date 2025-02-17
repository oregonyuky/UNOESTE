#include <stdio.h>
#define T 6
void letra_a(){
    int soma=0, k=0, vet[T][T], flag=0, menor;
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            if(i+j>=T-1){
                if(flag==0){
                    menor = vet[i][j];
                }
                flag=1;
                if(menor>vet[i][j])menor = vet[i][j];
                soma+=vet[i][j];
                k++;
            }
        }
    }
    printf("menor elemento: %d\n", menor);
    printf("media: %.2f\n", (float)soma/k);
}
void letra_b(){
    int vet[100][100], menor, flag=0, soma=0, k=0;
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            scanf("%d", &vet[i][j]);
        }
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            if(j>i && j<T/2 && i<T/2-1){
                soma+=vet[i][j];
                k++;
            }
            else if(i+j<T-1 && j>=T/2 && i<T/2-1){
                soma+=vet[i][j];
                k++;
            }
            if(i+j>=T && i>T/2 && j<T/2){
                soma+=vet[i][j];
                k++;
            }
            else if(i>j && j>=T/2 && i>T/2){
                soma+=vet[i][j];
                k++;
            }
        }
    }
        
    
    printf("%d\n", soma);
    printf("media: %.2f\n", (float)soma/k);
}
int main(){
    letra_b();
    return 0;
}