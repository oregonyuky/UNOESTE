#include <stdio.h>
int main(){
    size_t a, b;
    while(scanf("%u %u", &a, &b)!=EOF){
        printf("%u\n", (a^b));
    }
    return 0;
}
