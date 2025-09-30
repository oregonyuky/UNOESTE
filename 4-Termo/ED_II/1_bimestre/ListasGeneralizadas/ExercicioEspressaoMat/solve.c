#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "tadListaGen.h"
typedef union conteudo {
    double valor;
    char operador[4];
    char funcao[30];
} Conteudo;

typedef struct listagen {
    char terminal;              // 'n' = número, 'o' = operador, 'f' = função
    Conteudo info;              // conteúdo
    struct listagen *cabeca;    // sublista
    struct listagen *cauda;     // próximo
} ListaGen;

typedef struct termo {
    char info[30];
    struct termo *prox;
} Termo;

typedef struct pilha {
    struct listagen *l;
    struct pilha *prox;
} Pilha;
void init(Pilha **p) {
    *p = NULL;
}
void push(Pilha **p, ListaGen *l) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    novo->l = l;
    novo->prox = *p;
    *p = novo;
}
void pop(Pilha **p, ListaGen **l) {
    if (*p) {
        Pilha *temp = *p;
        *l = temp->l;
        *p = (*p)->prox;
        free(temp);
    } else {
        *l = NULL;
    }
}
char isEmpty(Pilha *p) {
    return p == NULL;
}
Termo* separa(char equacao[100]) {
    Termo *ini = NULL, *fim = NULL;
    int i = 0, n = strlen(equacao);

    while (i < n) {
        // ignorar espaços
        if (equacao[i] == ' ') {
            i++;
            continue;
        }

        Termo *novo = (Termo*) malloc(sizeof(Termo));
        novo->prox = NULL;

        // se for número (pode ter vários dígitos, ou ponto decimal)
        if (isdigit(equacao[i]) || (equacao[i] == '.')) {
            int j = 0;
            while (i < n && (isdigit(equacao[i]) || equacao[i] == '.')) {
                novo->info[j++] = equacao[i++];
            }
            novo->info[j] = '\0';
        }
        // se for parêntese ou operador de 1 char
        else if (strchr("()+-*/", equacao[i])) {
            novo->info[0] = equacao[i++];
            novo->info[1] = '\0';
        }
        // se for função (ex: sin, cos, sqrt...)
        else if (isalpha(equacao[i])) {
            int j = 0;
            while (i < n && isalpha(equacao[i])) {
                novo->info[j++] = equacao[i++];
            }
            novo->info[j] = '\0';
        }
        else {
            // caractere inválido, só avança
            i++;
            free(novo);
            continue;
        }

        // insere no fim da lista
        if (!ini)
            ini = fim = novo;
        else {
            fim->prox = novo;
            fim = novo;
        }
    }

    return ini;
}

double calcula(ListaGen *L) {
    if (!L) return 0;

    // Se for número
    if (L->terminal == 'n')
        return L->info.valor;

    // Se for operador binário
    if (L->terminal == 'o') {
        double a = calcula(L->cabeca);
        double b = calcula(L->cabeca->cauda);
        if (strcmp(L->info.operador, "+") == 0) return a + b;
        if (strcmp(L->info.operador, "-") == 0) return a - b;
        if (strcmp(L->info.operador, "*") == 0) return a * b;
        if (strcmp(L->info.operador, "/") == 0) return a / b;
    }

    // Se for função (ex: sin, cos)
    if (L->terminal == 'f') {
        double x = calcula(L->cabeca);
        if (strcmp(L->info.funcao, "sin") == 0) return sin(x);
        if (strcmp(L->info.funcao, "cos") == 0) return cos(x);
        if (strcmp(L->info.funcao, "sqrt") == 0) return sqrt(x);
    }

    return 0;
}
ListaGen* CriaNo(char *token) {
    ListaGen *novo = (ListaGen*) malloc(sizeof(ListaGen));
    novo->cabeca = NULL;
    novo->cauda = NULL;

    // Verifica se é número
    if (sscanf(token, "%lf", &novo->info.valor) == 1) {
        novo->terminal = 'n'; // número
    }
    else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
             strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
        novo->terminal = 'o'; // operador
        strcpy(novo->info.operador, token);
    }
    else {
        novo->terminal = 'f'; // função
        strcpy(novo->info.funcao, token);
    }

    return novo;
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
int main() {
    char equacao[100] = "(3+12.5)*cos(0)";
    Termo *t = separa(equacao);

    while (t) {
        printf("[%s] ", t->info);
        t = t->prox;
    }
    printf("\n");
    return 0;
}
