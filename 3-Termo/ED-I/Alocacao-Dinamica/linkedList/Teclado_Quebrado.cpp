#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define dbg(v) cout << #v << " = " << (v) << endl 
using namespace std;
class FelipeAkio{
    public:
    struct TpPont{ 
        char v;
        TpPont *ant, *prox;
    };
    struct TpPont1{
        char v;
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
    TpPont1 *novaCaixaV(char v){
        TpPont1 *aux = new TpPont1;
        aux->v = v;
        aux->ant = NULL;
        aux->prox = NULL;
        return aux;
    };
    TpPont1 *InserirFimV(TpPont1 *lis, char v){
        TpPont1 *aux = lis;
        if(!aux)return novaCaixaV(v);
        while(aux->prox)aux = aux->prox;
        aux->prox = novaCaixaV(v);
        aux->prox->ant = aux;
        return lis;
    }
    TpPont *Juntar(TpPont *lis){
        TpPont *aux = lis, *exp = NULL;
        while(aux){
            exp = InserirFim(exp, aux->v);
            aux = aux->prox;
        }
        return exp;
    }
    void Exibir(TpPont1 *lis){
        TpPont1 *aux = lis;
        while(aux->prox)aux = aux->prox; 
        while(aux){
            printf("%c", aux->v);
            aux = aux->ant;
        }
    }
    TpPont *Inverter(TpPont *lis){
        TpPont *aux = lis, *aux1=NULL;
        while(aux->prox)aux = aux->prox;
        while(aux){
            aux1 = InserirFim(aux1, aux->v);
            aux = aux->ant;
        }
        return aux1;
    }
    TpPont *Excluir(TpPont *lis, int i){
        TpPont *aux = lis;
        while(aux && i--)aux = aux->prox; 
        if(!aux)return lis;
        if(!aux->ant){
            lis = aux->prox;
            if (lis) lis->ant = NULL;
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
            delete aux;
            return lis;
        }
    }
    void teste2(){
        freopen("input.txt", "r", stdin);
        char str[100005]; 
        TpPont *lis = NULL;
         TpPont1 *aux = NULL;
        while(fgets(str, sizeof(str), stdin)){
            if (strcmp(str, "") == 0) break;
            TpPont *lis = NULL, *todo=NULL; TpPont1 *aux=NULL;
            for(int i=0;str[i]!='\0';i++){
                if(str[i]=='['){
                    lis = NULL;
                    while(++i <strlen(str)){
                        if(str[i]==']'){
                            break;
                        }
                        if(str[i]=='['){
                            i--;
                            break;
                        }
                        if(str[i]!='\n')
                            lis = InserirFim(lis, str[i]);
                    }   
                    if(lis)
                        lis = Inverter(lis);
                    while(lis){
                        aux = InserirFimV(aux, lis->v);
                        lis = lis->prox;
                    }
                }
                else if(str[i]!=']'){
                    todo = InserirFim(todo, str[i]);
                }
            }
            if (aux) {
                while(aux->prox) aux = aux->prox; 
                while(aux){
                    printf("%c", aux->v);
                    aux = aux->ant;
                }
            }
            while(todo){
                printf("%c", todo->v);
                todo = todo->prox;
            }
        }
    }
};
class Resolvido{
    public:
    struct TpPont {
        char v;
        TpPont *ant, *prox;
    };

    TpPont *novaCaixa(char v) {
        TpPont *aux = new TpPont;
        aux->v = v;
        aux->ant = aux->prox = NULL;
        return aux;
    }

    void liberar(TpPont *p) {
        while (p) {
            TpPont *tmp = p;
            p = p->prox;
            delete tmp;
        }
    }
    void imprimir(TpPont *ini) {
        while (ini) {
            putchar(ini->v);
            ini = ini->prox;
        }
        putchar('\n');
    }
    void teste() {
        char str[100005];
        while (fgets(str, sizeof(str), stdin)) {
            TpPont *ini = NULL, *fim = NULL, *cursor = NULL;
            for (int i = 0; str[i]; i++) {
                char c = str[i];
                if (c == '\n') continue;
                if (c == '[') {
                    cursor = NULL; 
                } else if (c == ']') {
                    cursor = fim; 
                } else {
                    TpPont *novo = novaCaixa(c);
                    if (!ini) {
                        ini = fim = novo;
                        cursor = novo;
                    } else if (cursor == NULL) { 
                        novo->prox = ini;
                        ini->ant = novo;
                        ini = novo;
                        cursor = novo;
                    } else if (cursor == fim) { 
                        fim->prox = novo;
                        novo->ant = fim;
                        fim = novo;
                        cursor = novo;
                    } else { // meio
                        novo->prox = cursor->prox;
                        novo->ant = cursor;
                        if (cursor->prox)
                            cursor->prox->ant = novo;
                        cursor->prox = novo;
                        cursor = novo;
                        if (!novo->prox) fim = novo;
                    }
                }
            }
            imprimir(ini);
            liberar(ini);
        }
    }
};

int main(){
    FelipeAkio f;
    Resolvido c;
    c.teste();
    //f.teste2();
}
