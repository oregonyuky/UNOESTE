#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
class Pilha{
    public:
    struct TpItem{ 
        char nome[30];
        int idade;
    };
    struct TpPilha{
        TpItem Pilha;
        TpPilha *prox;
        int Topo;
    };
    void Init(TpPilha *P){

    }
    TpItem Top(TpPilha *P, TpItem I){
        return P->Pilha[P->Topo];
    }
    void Push(TpPilha *P, TpItem I){
        P->Pilha[++P->Topo] = I;
    }
    TpItem *Pop(TpPilha *P){
        return P->Pilha[P->Topo--];
    }
    char IsEmpty(TpPilha *P){
        return P->Topo==-1;
    }
    char isFull(TpPilha *P){
        return P->Topo == MAX-1;
    }
    void Exibir(TpPilha *P){
        TpPilha *aux = P;
        while(aux){
            printf("%s ", aux->nome, aux->idade);
            aux = aux->prox;
        }
    }
    void teste(){
        TpPilha *P;
        TpItem I;
        Init(P);
        Push(P, {"felipe", 24});
        Exibir(P);
    }
};
class Fila{

};
int main(){
    Pilha P;
    P.teste();
}
