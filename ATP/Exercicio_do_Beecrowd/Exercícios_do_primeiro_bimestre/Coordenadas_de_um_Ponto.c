#include <stdio.h>
float cordenada(float, float);
int main(){
    float a, b;
    scanf("%f %f", &a, &b);
    int result = cordenada(a, b);
    if(result == 3){
        printf("Q1\n");
    }
    else if(result == 2){
        printf("Q4\n");
    }
    else if(result == 1){
        printf("Q2\n");
    }
    else if(result == 0){
        printf("Q3\n");
    }
    else if(result == -2){
        printf("Eixo Y\n");
    }
    else if(result == -3){
        printf("Eixo X\n");
    }
    else{
        printf("Origem\n");
    }
    return 0;

}
float cordenada(float x, float y){
    if(x>0 && y>0){
        return 3;
    }
    else if(x>0 && y<0){
        return 2;
    }
    else if(x<0 && y>0){
        return 1;
    }
    else if(x<0 && y<0){
        return 0;
    }
    else if(x == 0.0 && y!=0.0){
        return -2;
    }
    else if(x!=0.0 && y == 0.0){
        return -3;
    }
    else{
        return -1;
    }
}
