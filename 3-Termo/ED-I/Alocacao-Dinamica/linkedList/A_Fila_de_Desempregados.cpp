#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct TpPont{
    int v;
    TpPont *ant, *prox;
};
TpPont *ExcluirInicio(TpPont *lis){
     if(!lis) return NULL;        
    TpPont *aux = lis;          
    lis = lis->prox;              
    if (lis)lis->ant = NULL;        
    delete aux;                  
    return lis;
}
TpPont *novaCaixa(int v){
    TpPont *aux = new TpPont;
    aux->v = v;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}
TpPont *InserirFim(TpPont *lis, int v){
    TpPont *aux = novaCaixa(v), *aux1 = lis;
    if(lis==NULL){
        lis = aux;
        return lis;
    }
    else{
        while(aux1->prox)aux1 = aux1->prox;
        aux1->prox = aux;
        aux->ant = aux1;
        return lis;
    }

}
void Exibir(TpPont *lis){
    TpPont *aux = lis;
    cout << "\n";
    while(aux){
        printf("%d ", aux->v);
        aux = aux->prox;
    }
    cout << endl;
}
TpPont *CopiarLis(TpPont *lis){
    TpPont *aux = lis;
    TpPont *nov = NULL;
    while(aux){
        nov = InserirFim(nov, aux->v);
        aux = aux->prox;
    }
    return nov;
}
TpPont *ExcluirV(TpPont *lis, int v){
    TpPont *aux = lis;
    while(aux && aux->v != v){
        aux = aux->prox;
    }   
    if(!aux)return lis;
    if(!aux->ant)lis = ExcluirInicio(lis);
    else if(!aux->prox){
        aux->ant->prox=NULL;
        delete aux;
    }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        delete aux;
    }
    return lis;
}
int Recursao(TpPont *lis, int n, int a){ 
    if(!lis) return -1;
    TpPont *aux = CopiarLis(lis);
    if(n==0){
        return aux->v;
    }
    if(aux){
        if(aux->v==a)return -1;
        aux = InserirFim(aux, aux->v);
        aux = ExcluirInicio(aux);
        return Recursao(aux, n-1, a);
    }
}
TpPont *R(TpPont *lis, int n){ 
    if(!lis) return NULL;
    TpPont *aux = lis;
    if(n==0){
        return lis;
    }
    if(aux){
        aux = InserirFim(aux, aux->v);
        aux = ExcluirInicio(aux);
        return R(aux, n-1);
    }
}
TpPont *Inverter(TpPont *lis){
    TpPont *aux = CopiarLis(lis), *l = NULL;
    while(aux->prox)aux = aux->prox;
    while(aux){
        l = InserirFim(l, aux->v);
        aux = aux->ant;
    }
    return l;
}
void teste(){
    TpPont *lis = NULL, *b=NULL;
    int n, k, m;

    while(scanf("%d %d %d", &n, &k, &m) && (n || k || m)){k--, m--;
        for(int i=1;i<=n;i++){
            lis = InserirFim(lis, i);
        }
        b = Inverter(CopiarLis(lis));
        int va, vb, nn=n>>1;
        while(lis){
            nn--;
            //Exibir(lis);
            //Exibir(b);
            va = Recursao(lis, k, -1);
            vb = Recursao(b, m, -1);
            if(va!=vb){
                printf("  %d  %d,", va, vb)
                lis = ExcluirV(lis, vb);
                b = ExcluirV(b, va);
            };
            else{
                printf(" %d", va);
            }
            lis = ExcluirV(lis, va);
            b = ExcluirV(b, vb
        }
        puts("");
    }
}
int main(){
    teste();
}
