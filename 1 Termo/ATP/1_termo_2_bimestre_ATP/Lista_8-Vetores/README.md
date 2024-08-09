![image](https://github.com/oregonyuky/ATP/assets/152916454/bedaa6fd-052b-441c-8c4b-86a4fb7a63be)

## Ex1
```c
#include <stdio.h>
#define TF 4
int main(){
    int vet[TF+1], TL=0, num, elem, pos=0, i;
    printf("Digite o %do.numero\n", TL+1);
    scanf("%d", &num);
    while(TL<TF && num>0){
        vet[TL]=num;
        TL++;
        if(TL<TF){
            printf("Digite o %do.numero:\n", TL+1);
            scanf("%d", &num);
        }
    }
    printf("Digite o elemento para inserir:\n");
    scanf("%d", &elem);
    pos=0;
    while(pos<TL && vet[pos]<elem)
        pos++;
    for(i=TL;i>pos;i--){
        vet[i]=vet[i-1];
    }
    vet[pos]=elem;
    TL++;
    for(i=0;i<TL;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
```
## Ex2
```c
#include <stdio.h>
#define TF 4
int main(){
    int vet1[TF], vet2[TF], vet3[TF*2], i, j, TL1=0, TL2=0, TL3=0, num, pos, num1;
    printf("Digite o %do.numero do vet1:\n", TL1+1);
    scanf("%d", &num);
    while(TL1<TF && num>0){
        pos=0;
        while(pos<TL1 && num>vet1[pos])
            pos++;
        for(i=TL1;i>pos;i--){
            vet1[i] = vet1[i-1];
        }
        vet1[pos] = num;
        TL1++;
        if(TL1<TF){
            printf("Digite o %do.numero do vet1:\n", TL1+1);
            scanf("%d", &num);
        }
    }
     pos=0;
    printf("Digite o %d.numero do vet2:\n", TL2+1);
    scanf("%d", &num1);
    while(TL2<TF && num1>0){
        pos=0;
        while(pos<TL2 && num1>vet2[pos])
            pos++;
        for(i=TL2;i>pos;i--){
            vet2[i] = vet2[i-1];
        }
        vet2[pos] = num1;
        TL2++;
        if(TL2<TF){
            printf("Digite o %d.numero do vet2:\n", TL2+1);
            scanf("%d", &num1);
        }
    }
    i=0;
    j=0;
    while(i<TL1 && j<TL2){
        if(vet1[i] < vet2[j]){
            vet3[TL3] = vet1[i];
            TL3++;
            i++;
        }
        else{
            vet3[TL3] = vet2[j];
            TL3++;
            j++;
        }
    }
    while(i<TL1){
        vet3[TL3] = vet1[i];
        TL3++;
        i++;
    }
    while(j<TL2){
        vet3[TL3] = vet2[j];
        TL3++;
        j++;
    }
    for(i=0;i<TL3;i++){
        printf("%d", vet3[i]);
    }
    return 0;
}
```
## Ex3
```c
#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], vet2[TF], j=0, pos=0, TLU=0;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n", i+1);
        scanf("%d", &vet[i]);
    }
    int a = TF-1;
    for(i=0;i<TF;i++){
        if(vet[i]<0){
            vet2[TLU] = vet[i];
            TLU++;
        }
        else{
            vet2[a] = vet[i];
            a--;
        }
    }

    for(i=0;i<TF;i++){
        printf("%d ", vet2[i]);
    }
    return 0;
}
```
## Ex4 
```c
#include <stdio.h>
#define TL 4
int main(){
    int i, vet[TL], vet2[TL], vUniao[2*TL], pos, TLU=0;
    for(i=0;i<TL;i++){
        printf("Digite o %do.vet1:\n",i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0;i<TL;i++){
        printf("Digite o %do.vet2:\n", i+1);
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<TL;i++){
        pos=0;
        while(pos<TLU && vet[i]!=vUniao[pos])
            pos++;
        if(pos==TLU){
            vUniao[TLU] = vet[i];
            TLU++;
        }
    }
    pos=0;
    for(i=0;i<TL;i++){
        pos=0;
        while(pos<TLU && vet2[i]!=vUniao[pos])
            pos++;
            if(pos==TLU){
                vUniao[TLU] = vet2[i];
                TLU++;
            }
    }
    for(i=0;i<TLU;i++){
        printf("%d ", vUniao[i]);
    }
    return 0;
}
```
## Ex5
```c
#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], elem;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n",i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o elemento:\n");
    scanf("%d", &elem);
    for(i=0;i<TF;i++){
        if(vet[i]==elem)vet[i] = vet[i+1];
    }
    for(i=0;i<TF-1;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
```
## Ex6
```c
#include <stdio.h>
#define TF 5
int main(){
    int a, elem, pos, vet[TF], i;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero:\n", i+1);
        scanf("%d", &vet[i]);
    }
    printf("Digite o elemento:\n");
    scanf("%d", &elem);
    printf("Digite a posicao:\n");
    scanf("%d", &pos);
    for(i=0;i<TF;i++){
        if(i==pos)vet[i] = elem;
    }
    for(i=0;i<TF;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
```
## Ex7 
```c
#include <stdio.h>
#define TF 5
int main(){
    int i, vet[TF], vet2[TF], pos, vIntersec[TF], TLI=0;
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero do vet:\n", i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0;i<TF;i++){
        printf("Digite o %do.numero do vet2:\n",i+1);
        scanf("%d", &vet2[i]);
    }
    for(i=0;i<TF;i++){
        pos=0;
        while(pos<TF && vet[i]!=vet2[pos])
            pos++;
        if(pos<TF){
            pos=0;
            while(pos<TLI && vet[i]!=vIntersec[pos])
                pos++;
            if(pos==TLI){
                vIntersec[TLI] = vet[i];
                TLI++;
            }
        }
        
    }
    for(i=0;i<TLI;i++){
        printf("%d ", vIntersec[i]);
    }
    return 0;
}
```


