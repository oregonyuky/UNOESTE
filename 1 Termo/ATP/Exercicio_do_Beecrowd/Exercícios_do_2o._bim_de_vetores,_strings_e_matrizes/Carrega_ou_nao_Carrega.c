#include <stdio.h>
#include <math.h>
#define max(a, b) (a)<(b) ? (b) : (a)
#define min(a, b) (a)>(b) ? (b) : (a)
#define ll long long
int main(){
    ll n1, n2, ma, me, sta[33], stb[33], so,i;
    while(scanf("%lld %lld", &n1, &n2)!=EOF){
        so=0;
        i=0;
        ma = max(n1, n2);
        me = min(n1, n2);
        while(ma!=0){
            sta[i] = ma%2;
            stb[i] = me%2;
            ma/=2;
            me/=2;
            i++;
        }
        for(int k=0;k<i;k++){
            if((sta[k]==0 && stb[k]==1) || (sta[k]==1 && stb[k]==0))
                so+=pow(2, k);
        }
        printf("%lld\n", so);
    }
    return 0;
}
