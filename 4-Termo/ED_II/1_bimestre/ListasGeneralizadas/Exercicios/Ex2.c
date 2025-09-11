#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insere(ListaGen **l, char info[8], int n){
    FilaP *f1, *f2;
    Fila *fn1, *fn2;
    ListaGen *aux;
    int nivel;
    initP(&f1);initP(&f2);init(&fn1);init(&fn2);
    enequeue(&f1, *l);
    enequeue(&f2, *l);
    enequeueP(&fn1, 1);
    enequeueP(&fn2, 1);
    while(!isEmpty(f1)){
        dequeueP(&f1, &aux);
        while(aux){
            if(!Nula(Head(aux)) && !Atomo(Head(aux))){
                enqueue(&f1, Head(aux));
                enqueue(&f2, aux);
                enqueue(&fn1, nivel+1);
                enqueue(&fn2, nivel+2);
            }
            aux = Tail(aux);
        }
        while(!isEmptyP(f2)){
            dequeue(&f2, &aux);
            dequeue(&fn2, &nivel);
            if(nivel==n){
                if(*l == aux)
                    insereLG(&*l, info);
                else
                    insereLG(&aux->no.lista.cabeca, info);
            }
        }
    }
}
void insereLG(ListaGen **l, char info[8]){
    ListaGen *ant = NULL, *aux = *l;
    char flag = 1;
    while(aux && flag){
        if(Atomo(Head(aux)) && strcmp(info, Head(aux)->no.info)<=0)
            flag=0;
        else{
            ant = aux;
            aux = Tail(aux);
        }
    }
    if(!aux || strcmp(info, aux->no.info)!=0){
        if(!ant)
            *l = Cons(CriaT(info), *l);
        else
            ant->no.lista.cauda = Cons(CriaT(info), aux);
    }
}
