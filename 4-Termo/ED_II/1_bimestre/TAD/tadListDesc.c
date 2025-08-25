#include <stdio.h>
#include <stdlib.h>
struct caixa{
    int info;
    struct caixa *ant, *prox;
};
typedef struct caixa Caixa;
struct descritor{
    Caixa *inicio, *fim;
};
typedef struct descritor Descritor;
void init(Descritor *desc){
    (*desc).inicio = (*desc).fim = NULL;
}
void init2(Descritor **desc){
    *desc = (Descritor *)malloc(sizeof(Descritor));
    (*desc)->inicio = (*desc)->fim = NULL;
}
void inserirInicio(Descritor *desc, int info){
    Caixa *nova = (Caixa*)malloc(sizeof(Caixa));
    nova->info = info;
    nova->ant = NULL;
    nova->prox = (*desc).inicio;
    if(!(*desc).inicio)
        (*desc).inicio = (*desc).fim = nova;
    else{
        (*desc).inicio->ant = nova;
        (*desc).inicio = nova;
    }
}
void inserirInicio2(Descritor *desc, int info){
    Caixa *nova = (Caixa*)malloc(sizeof(Caixa));
    nova->info = info;
    nova->ant = NULL;
    nova->prox = desc->inicio;
    if(!desc->inicio)
        desc->inicio = desc->fim = nova;
    else{
        desc->inicio->ant = nova;
        desc->inicio = nova;
    }
}
void Exibir(Descritor *desc){
    Caixa *nova = desc->inicio;
    while(nova){
        printf("%d ", nova->info);
        nova = nova->prox;
    }
}
void Exibir2(Descritor *desc){
    Caixa *nova = desc->inicio;
    while(nova){
        printf("%d ", nova->info);
        nova = nova->prox;
    }
}
void main1(){
    Descritor desc;
    init(&desc);
    inserirInicio(&desc, 10);
    inserirInicio(&desc, 11);
    Exibir(&desc);
}
void main2(){
    Descritor *desc;
    init2(&desc);
    inserirInicio2(desc, 12);
    inserirInicio2(desc, 13);
    Exibir2(desc);
}
int main(){
    //main1();
    main2();
}
