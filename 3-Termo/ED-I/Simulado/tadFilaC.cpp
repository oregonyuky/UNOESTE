#include <stdio.h>
#include <stdlib.h>
#define MAXFILA 10
struct TpFilaC{
    int inicio, fim, cont;
    char FILA[MAXFILA];
};
void inicializar(TpFilaC &f){
    f.inicio = 0;
    f.fim = -1;
    f.cont = 0;
}
void inserir(TpFilaC &f, char elem){
    if(f.fim==MAXFILA-1)f.fim=-1;
    f.FILA[++f.fim] = elem;
    f.cont++;
}
char retirar(TpFilaC &f){
    char a = f.FILA[f.inicio];
    if(f.inicio==MAXFILA-1)f.inicio=0;
    else f.inicio++;
    f.cont--;
    return a;
}
char cheia(int cont){
    return cont == MAXFILA;
}
char vazia(int cont){
    return cont == 0;
}
char elementoInicio(TpFilaC f){
    return f.FILA[f.inicio];
}
char elementoFim(TpFilaC f){
    return f.FILA[f.fim];
}
void exibir(TpFilaC f){
    while(!vazia(f.cont)){
        printf("%c ", retirar(f));
    }
    printf("\n");
}
int main(){
    TpFilaC a;
    inicializar(a);
    inserir(a, '1');
    inserir(a, '2');
    inserir(a, '3');
    inserir(a, '4');
    
    exibir(a);

}
