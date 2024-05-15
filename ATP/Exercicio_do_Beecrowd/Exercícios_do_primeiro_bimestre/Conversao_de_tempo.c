#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    if(a>=3600){
        printf("%d:%d:%d\n", a/(60*60), (a%(60*60))/60 , (a%60)%60);
    } else 
        printf("%d:%d:%d\n", a/(60*60), a/60, a%60 );
    return 0;
}