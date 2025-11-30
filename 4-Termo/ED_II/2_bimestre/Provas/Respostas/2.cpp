#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila.h"
typedef struct funcionarios{
    int matricula;
    char nome[50];
    char sexo;
    int codCargo;
    char status[6];
} Funcionarios;
typedef struct cargos{
    int codCargo;
    char nome[50];
    float salario;
    int categoriaIR;
    int elo;
} Cargos;

typedef struct iniFunc{
    Func *raiz;
    iniFunc *prox;
    int codCargo;
} IniFunc;

void inserirFuncionarios(){
    FILE *file = fopen("funcionarios.dat", "wb");
    if(!file)perror("Erro");
    Funcionarios f[10] = {
        {200, "Joao",   'M', 55, "True"},
        {100, "Pedro",  'M', 22, "True"},
        {189, "Ana",    'F', 18, "True"},
        {132, "Carlos", 'M', 39, "True"},
        {121, "Fabio",  'M', 55, "True"},
        {165, "Rita",   'F', 45, "True"},
        {120, "Joana",  'F', 55, "False"},
        {270, "Carla",  'F', 45, "True"},
        {90,  "Eliane", 'F', 18, "True"},
        {195, "Daniela",'F', 18, "True"}
    };
    fwrite(f, sizeof(Funcionarios), 10, file);
    fclose(file);
};

void inserirCargos(){
    FILE *file = fopen("cargos.dat", "wb");
    if(!file)perror("Erro");
    Cargos c[11] = {
        {0,  "",                   0.0,     0,  0},
        {0,  "",                   0.0,     0,  0},
        {22, "Gerente Sistemas",   2500.00, 3,  0},
        {0,  "",                   0.0,     0,  0},
        {0,  "",                   0.0,     0,  0},
        {55, "Analista Sistemas",  2000.00, 2, 10},
        {0,  "",                   0.0,     0,  0},
        {0,  "",                   0.0,     0,  0},
        {18, "Programador",        1100.00, 1,  0},
        {39, "Administrador BD",   1900.00, 2,  0},
        {45, "Analista Junior",    1350.00, 2,  0},
    };
    fwrite(c, sizeof(Cargos), 11, file);
    fclose(file);
}
IniFunc *criarNo(int cod){
    IniFunc *n = (IniFunc*)malloc(sizeof(IniFunc));
    n->codCargo = cod;
    n->prox = NULL;
    n->raiz = NULL;
    return n;
}
void criarOrdenando(IniFunc **ff, int info){
    IniFunc *aux = *ff;
    if(!aux)*ff = criarNo(info);
    else{
        IniFunc *ant = NULL;
        while(aux && aux->codCargo < info){
            ant = aux;
            aux = aux->prox;
        }
        if(!ant){
            IniFunc *novo = criarNo(info);
            novo->prox = aux;
            *ff = novo;
        }else{
            IniFunc *novo = criarNo(info);
            novo->prox = aux;
            ant->prox = novo;
        }
    }
}
void construirDinamica(IniFunc **ff){
    FILE *filec = fopen("cargos.dat", "rb");
    Cargos c;
    while(fread(&c, sizeof(Cargos), 1, filec)==1){
        if(c.codCargo != 0){
            criarOrdenando(ff, c.codCargo);
        }
    }
    fclose(filec);
}
void imprimir(IniFunc *ff){
    IniFunc *aux = ff;
    while(aux){
        printf("%d ", aux->codCargo);
        aux = aux->prox;
    }
}
IniFunc *busca(IniFunc *ff, int cod){
    IniFunc *aux = ff, *nov;
    char flag=1;
    while(aux && flag){
        if(aux->codCargo == cod){
            nov = aux;
            flag=0;
        }
        aux = aux->prox;
    }
    return nov;
}
Func *criaAVL(int pos){
    Func *n = (Func*)malloc(sizeof(Func));
    n->pos = pos;
    n->esq = n->dir = NULL;
    return n;
}
int altura(Func *fu){
    if(!fu)return -1;
    int he = altura(fu->esq);
    int hd = altura(fu->dir);
    return (he > hd ? he : hd) + 1;
}
void rotacaoLL(Func **fu){
    Func *p = *fu;
    Func *q = p->dir;
    p->dir = q->esq;
    q->esq = p;
    *fu = q;
}

void rotacaoRR(Func **fu){
    Func *p = *fu;
    Func *q = p->esq;
    p->esq = q->dir;
    q->dir = p;
    *fu = q;
}

void inserirAVL(Func **fu, int pos, int *rot){
    if(!*fu){
        *fu = criaAVL(pos);
        *rot = 0;
    }else if((*fu)->pos < pos)inserirAVL(&(*fu)->dir, pos, rot);
    else inserirAVL(&(*fu)->esq, pos, rot);
    if(!*rot){
        int fb = altura((*fu)->dir) - altura((*fu)->esq);
        if(abs(fb) == 2){
            *rot = 1;
            if(fb==2){
                int fbf = altura((*fu)->dir->dir) - altura((*fu)->dir->esq);
                if(fbf==1)
                    rotacaoLL(fu);
                else{
                    rotacaoRR(&(*fu)->dir);
                    rotacaoLL(fu);
                }
            }else{
                int fbf = altura((*fu)->esq->dir) - altura((*fu)->esq->esq);
                if(fbf==1)
                    rotacaoRR(fu);
                else{
                    rotacaoLL(&(*fu)->esq);
                    rotacaoRR(fu);
                }
            }
        }
    }
}
void construirAVL(IniFunc **ff){
    FILE *file = fopen("funcionarios.dat", "rb");
    Funcionarios f;
    while(fread(&f, sizeof(Funcionarios), 1, file)==1){
        IniFunc *b = busca(*ff, f.codCargo);
        if(b){
            int rot=0;
            int idx = ftell(file)/sizeof(Funcionarios)-1;
            if(!strcmp(f.status, "True")){
                inserirAVL(&(b)->raiz, idx, &rot);
            }
        }
    }
    fclose(file);
}
void imprimirAVL(Func *fu){
    PilhaP *p;
    Func *aux, *curr = NULL;
    initPP(&p);
    pushPP(&p, fu);
    while(curr || !isEmptyPP(p)){
        while(curr){
            pushPP(&p, curr);
            curr = curr->esq;
        }
        popPP(&p, &curr);
        printf("%d ", curr->pos);
        curr = curr->dir;
    }
}
void imprimirTodo(IniFunc *ff){
    IniFunc *aux = ff;
    while(aux){
        Func *fu = aux->raiz;
        printf("codCargo: %d - ", aux->codCargo);
        imprimirAVL(fu); puts("");
        aux = aux->prox;
    }
}
int main(){
    IniFunc *ff = NULL;
    inserirFuncionarios();
    inserirCargos();
    construirDinamica(&ff);
    imprimir(ff); puts("");
    construirAVL(&ff);
    imprimirTodo(ff);
    
}