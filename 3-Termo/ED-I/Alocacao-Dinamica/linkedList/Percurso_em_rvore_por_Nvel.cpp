#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
struct TpPont{
    int v;
    TpPont *direita, *esquerda;
};
TpPont *novaCaixa(int v){
    TpPont *aux = new TpPont;
    aux->v = v;
    aux->direita = NULL;
    aux->esquerda = NULL;
    return aux;
}
void Inserir(TpPont *p, int v){
    if(v > p->v) {
        if(p->direita) Inserir(p->direita, v);
        else p->direita = novaCaixa(v);
    }
    else {
        if(p->esquerda) Inserir(p->esquerda, v);
        else p->esquerda = novaCaixa(v);
    }
}

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int a;
        cin >> a;
        int n;
        cin >> n;
        TpPont *p = novaCaixa(n);
        for(int i=1;i<a;i++){
            cin >> n;
            Inserir(p, n);
        }
        
        printf("Case %d:\n", tt);
        queue<TpPont*> q;
        q.push(p);
        while(!q.empty()) {
            TpPont* cur = q.front();
            q.pop();
            if(cur != p) putchar(' ');
            printf("%d", cur->v);
            if(cur->esquerda) q.push(cur->esquerda);
            if(cur->direita) q.push(cur->direita);
        }
        puts("\n");     
    }
}