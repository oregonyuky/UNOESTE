#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
class Pilha{
    public:
    typedef struct TpItem{ 
        char info;
    };
    typedef struct TpPilha{
        struct TpItem Pilha;
        struct TpPilha *prox;
    };
    void Init(TpPilha **ptr){
        *ptr = NULL;
    }
    void Push(TpPilha **ptr, TpItem I){
        TpItem *aux, *atual;
        aux = (TpPilha *)malloc(sizeof(TpPilha));
        aux->info = I.info;
        aux->prox = NULL;
        if(*str == NULL)
            *str = aux;
        else{
            atual = *str;
            while(atual->prox != NULL)atual = atual->prox;
            atual->prox = aux;
        }
    }
    TpPilha Pop(TpPilha **ptr){
        
    }

};
int main(){
    Pilha P;
    P.teste();
}
