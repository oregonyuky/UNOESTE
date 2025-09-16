#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nl 3
#define nc 3
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef struct matrizEsp{
    int lin, col, valor;
    struct matrizEsp *pc, *pl;
} MatEsp;
void inicializar(MatEsp *vetLin[], MatEsp *vetCol[]){
    for(int i=0;i<max(nl, nc);i++){
        if(i<nl)vetLin[i] = NULL;
        if(i<nc)vetCol[i] = NULL;
    }
}
void verificaOcupado(MatEsp *pLinha, int col, MatEsp **aux){
    while(pLinha && col > pLinha->col)pLinha = pLinha->pl;
    if(pLinha && pLinha->col==col)
        *aux = pLinha;
    else 
        *aux = NULL; 
}
void exibir(MatEsp *vetLin[]){
    MatEsp *aux;
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            verificaOcupado(vetLin[i], j, &aux);
            if(aux)printf("%d ", aux->valor);
            else printf("0 ");
        }
        puts("");
    }
}
void insere(MatEsp *vetLin[], MatEsp *vetCol[], int lin, int col, int valor){
    MatEsp *ant, *aux, *nova;
    if(lin>=0 && lin<nl && col>=0 && col<nc){
        verificaOcupado(vetLin[lin], col, &aux);
        if(aux)
            aux->valor = valor;
        else{
            nova = (MatEsp*)malloc(sizeof(MatEsp));
            nova->lin = lin;
            nova->col = col;
            nova->valor = valor;
            nova->pl = nova->pc = NULL;
            MatEsp *plinha = vetLin[lin], *ant=NULL;
            while(plinha && col > plinha->col){
                ant = plinha;
                plinha = plinha->pl;
            }
            if(!ant)vetLin[lin] = nova;
            else ant->pl = nova;
            nova->pl = plinha;
            MatEsp *pColuna = vetCol[col];
            while(pColuna && lin > pColuna->lin){
                ant = pColuna;
                pColuna = pColuna->pc;
            }
            if(!ant)vetCol[col] = nova;
            else ant->pc = nova;
            nova->pc = pColuna;
        }
    }
    else{
        puts("As coordenadas estao fora da matriz!");
    }
}
void soma(MatEsp *vetLinA[], MatEsp *vetLinB[], MatEsp *vetLinC[], MatEsp *vetColC[]){
    MatEsp *aux;
    int soma=0;
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            verificaOcupado(vetLinA[i], j, &aux);
            if(aux)soma = aux->valor;
            verificaOcupado(vetLinB[i], j, &aux);
            if(aux)soma += aux->valor;
            if(soma!=0)
            	insere(vetLinC, vetColC, i, j, soma);
        }
    }
}
int main(){
    MatEsp *vetLinA[3], *vetColA[3], *vetLinB[3], *vetColB[3], *vetLinC[3], *vetColC[3];
    inicializar(vetLinA, vetColA);
    inicializar(vetLinB, vetColB);
    inicializar(vetLinC, vetColC);
    int opA[3][3] = {{2, 3, 0}, {0, 4, 7}, {1, 0, 9}};
    int opB[3][3] = {{4, -3, 7}, {0, 3, 1}, {6, 5, 2}};
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            insere(vetLinA, vetColA, i, j, opA[i][j]);
            insere(vetLinB, vetColB, i, j, opB[i][j]);
        }
    }
    exibir(vetLinA);
    puts("");
    exibir(vetLinB);
    puts("");
    soma(vetLinA, vetLinB, vetLinC, vetColC);
    exibir(vetLinC);
}
