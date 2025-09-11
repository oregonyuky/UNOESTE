#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadListaGen.h"
union no{
    double valor;
    char operador[4];
    char funcao[30];
}
typedef struct listagen{
    char terminal;
    union no;
    struct listagen *cabeca, *cauda;
}
typedef struct termo{
    char info[30];
    struct termo *prox;
}
typedef struct pilha{
    struct listagen *l;
}
Termo *separa(char equacao[100]){
    Termo *t = (Termo*)malloc(sizeof(Termo));
    for(int i=0;i<strlen(equacao)-1;i++){
        Termo *aux = (Termo*)malloc(sizeof(Termo));
        char tmp[3] = "";
        if(i < strlen(equacoa) && equacao[i]=='*' && equacao[i+1]=='*'){
            tmp[0] = equacao[i];
            tmp[1] = equacao[i+1];
            tmp[2] = '\0';
        }
        else{
            tmp[0] = equacao[i];
            tmp[1] = '\0';
        }
        strcpy(aux->info, tmp);
        aux->prox = NULL;
        if(!*t)
            *t = aux;
        else{
            Termo *aux1 = *t;
            while(aux1->prox)aux1 = aux1->prox;
            aux1->prox = aux;
        }
    }
    return t;
}
ListaGen *CriaNo(char str[30]){
    ListaGen *aux = (ListaGen*)malloc(sizeof(ListaGen));
    if(!strcmp(str, "(")){
        aux->terminal = 0;
        aux->no.valor = 0;
    }else if(str[0]-'0' >= 0 && str[0]-'0' <= 9){
        aux->terminal = 1;
        aux->no.valor = atof(str);
    }else if()
    aux->terminal = 1;
    strcpy(aux->no.valor, str);
    aux->cabeca = NULL;
    aux->cauda = NULL;
}
double resultadoEquacao(char equacao[100]){
    ListaGen *L = NULL, *atual; double result;
    Pilha *p1, *p2;
    Termo *lista = separa(equacao);
    init(&p1);init(&p2);
    while(lista){
        if(!L){
            L = atual = CriaNo(lista->info);//!
            push(&p2, L);//!
        }
        else if(!strcmp(lista->info, "(")){
            atual->cauda = CriaNo("0");//!
            atual = atual->cauda;
            push(&p1, atual);
            push(&p2, atual);
            lista = lista->prox;
            atual->cabeca = CriaNo(lista->info);
            atual = atual->cabeca;
        }
        else if(!strcmp(lista->info, ")")){
            pop(&p1, &atual);//!
        }else{
            atual->cauda = CriaNo(lista->info);
            atual = atual->cauda;
        }
        lista = lista->prox;
    }
    while(!isEmpty(p2)){//!
        pop(&p2, &atual);
        if(L==atual)
            result = calcula(L);//!
        else
            atual->info.valor = calcula(atual->cabeca);
    }
    return result;
}
int main(){

}