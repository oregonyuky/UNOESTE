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
     if(!lis) return NULL;         // Se a lista está vazia, retorna NULL imediatamente.
    TpPont *aux = lis;            // Guarda o ponteiro para o primeiro nó (que será excluído).
    lis = lis->prox;              // Avança o ponteiro da lista para o próximo nó.
    if (lis)                     // Se a lista não ficou vazia após o avanço,
        lis->ant = NULL;          // ajusta o ponteiro 'ant' do novo primeiro nó para NULL.
    delete aux;                  // Deleta o nó antigo (primeiro da lista).
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
int Recursao(TpPont *lis, int n){ 
    if(!lis) return -1;
    TpPont *aux = CopiarLis(lis);
    if(n==0){
        return aux->v;
    }
    if(aux){
        aux = InserirFim(aux, aux->v);
        aux = ExcluirInicio(aux);
        return Recursao(aux, n-1);
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
int Busca(TpPont *lis, int v){
    TpPont *aux = CopiarLis(lis);
    while(aux){
        if(aux->v == v)return 1;
        aux = aux->prox;
    }
    return 0;
}
void teste(){
    TpPont *lis = NULL, *b=NULL;
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);k--, m--;
    for(int i=1;i<=n;i++){
        lis = InserirFim(lis, i);
    }
    b = Inverter(CopiarLis(lis));
    int v;
    while(lis){
        Exibir(lis);
        Exibir(b);
         v = Recursao(lis, k);
        printf("%d\n", v);
        lis = R(lis, k);
        lis = ExcluirV(lis, v);
        if(Busca(b, v))
            b = ExcluirV(b, v);
        if(!lis) break;
        v = Recursao(b, m);
        printf("%d\n", v);
        b = R(b, m);
        lis = ExcluirV(lis, v);
        b = ExcluirV(b, v);
    }
}
void teste1(){
    TpPont *lis = NULL;
    lis = InserirFim(lis, 0);
    lis = InserirFim(lis, 1);
    lis = InserirFim(lis, 2);
    lis = InserirFim(lis, 3);
    Exibir(lis);
    lis = R(lis, 2);
    Exibir(lis);
}
int main(){
    teste();
}