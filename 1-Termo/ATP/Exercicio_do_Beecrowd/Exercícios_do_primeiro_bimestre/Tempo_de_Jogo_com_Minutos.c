#include <stdio.h>
int horario(int, int, int ,int);
int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int result = horario(a, b, c, d);
    int result1, result2;
    result1 = result / 60;
    result2 = result % 60;
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", result1, result2);
    return 0;

}
int horario(int x, int y, int z, int v){
    if(x == y && x == z && x == v){
        return 24*60 - (x*60+y) + z*60+v ;
    }
    else if((x<z && ((x>12 && z>12) || (x<12 && z<=12) || (x<12 && z>=12)))||(x==z && v>y)){
        return (z*60 + v) - (x*60 + y);
    } 
    else if((x>z && ((x<=12 && z<12) || (x>12 && z<12) || (x>12 && z>=12)))||(x==z && v<y)){
        return (24*60 - (x*60+y) + z*60+v);
    }
    
}