#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define dbg(v) cout << #v << " = " << (v) << endl 
using namespace std;
struct TpPont{
    char v;
    TpPont *ant, *prox;
};
struct TpPont1{
    const char *v;
    TpPont1 *ant, *prox;
};
TpPont *novaCaixa(char v){
    TpPont *aux = new TpPont;
    aux->v = v;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
};
TpPont *InserirFim(TpPont *lis, char v){
    TpPont *aux = lis, *nc = novaCaixa(v);
    if(!aux)return novaCaixa(v);
    while(aux->prox)aux = aux->prox;
    aux->prox = novaCaixa(v);
    aux->prox->ant = aux;
    return lis;
}
TpPont1 *novaCaixaV(const char *v){
    TpPont1 *aux = new TpPont1;
    aux->v = v;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
};
TpPont1 *InserirFimV(TpPont1 *lis, const char *v){
    TpPont1 *aux = lis;
    if(!aux)return novaCaixaV(v);
    while(aux->prox)aux = aux->prox;
    aux->prox = novaCaixaV(v);
    aux->prox->ant = aux;
    return lis;
}
char *Juntar(TpPont *lis){
    TpPont *aux = lis;
    char *nome = new char;
    strcpy(nome, "");
    char temp[2];
    while(aux){
        temp[0] = aux->v;
        temp[1] = '\0';
        strcat(nome, temp);
        aux = aux->prox;
    }
    return nome;
}
void Exibir(TpPont1 *lis){
    TpPont1 *aux = lis;
    while(aux->prox)aux = aux->prox;
    while(aux){
        printf("%s", aux->v);
        aux = aux->ant;
    }
    puts("");
}
TpPont *Excluir(TpPont *lis, int i){
    TpPont *aux = lis;
    while(aux && i--)aux = aux->prox; 
    if(!aux)return lis;
    if(!aux->ant){
        aux = aux->prox;
        delete aux;
        return lis;
    }
    else if(!aux->prox){
        aux->ant->prox = NULL;
        delete(aux);
        return lis;
    }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        return lis;
    }
}
void teste(){
    char str[100]; 
    TpPont *lis = NULL;
    FILE *arq = fopen("input.txt", "r");
    while(fscanf(arq, "%[^\n]\n", str)!=EOF){
        if (strcmp(str, "") == 0) break;
        TpPont *lis = NULL; TpPont1 *aux=NULL;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='['){
                while(++i <strlen(str)){
                    if(str[i]==']')break;   
                    if(str[i]=='['){i--;break;}
                    //dbg(i);
                    lis = InserirFim(lis, str[i]);
                }   
            }
        }
        //printf("%s\n", Juntar(lis));
        aux = InserirFimV(aux, Juntar(lis));
        Exibir(aux);printf("%s\n", str);
    }
    fclose(arq);
}
void teste2(){
    freopen("input.txt", "r", stdin);
    char str[100]; 
    TpPont *lis = NULL;
     TpPont1 *aux = NULL;
    while(fgets(str, sizeof(str), stdin)){
        if (strcmp(str, "") == 0) break;
        TpPont *lis = NULL, *todo=NULL;
        for(int i=0;str[i]!='\0';i++)
            todo = InserirFim(todo, str[i]);
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='['){
                todo = Excluir(todo, i);
                lis = NULL;
                while(++i <strlen(str)){
                    if(str[i]==']'){
                        todo = Excluir(todo, i);
                        break;
                    } 
                    if(str[i]=='['){
                        todo = Excluir(todo, i);
                        i--;
                        break;
                    }
                    lis = InserirFim(lis, str[i]);
                    todo = Excluir(todo, i);
                }   
                aux = InserirFimV(aux, Juntar(lis));
                //printf("%s\n", Juntar(lis));
            }
        }
        printf("%s\n", str);
        Exibir(aux);
        while(todo){
            printf("%c", todo->v);
            todo = todo->prox;
        }
    }
}
void teste3(){
    TpPont *lis = NULL;
    lis = InserirFim(lis, 'a');
    lis = InserirFim(lis, 'b');
    lis = InserirFim(lis, 'c');
    lis = InserirFim(lis, 'd');
    lis = InserirFim(lis, 'e');
    lis = Excluir(lis, 3);
    while(lis){
        printf("%c ", lis->v);
        lis = lis->prox;
    }
}
int main(){
    teste2();
}
