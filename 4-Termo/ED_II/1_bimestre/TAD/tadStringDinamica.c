#include <stdio.h>
#include <stdlib.h>

/* =========================
   TAD PILHA (genérica)
   ========================= */
typedef struct NoPilha {
    void *info;
    struct NoPilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void init(Pilha **p) {
    *p = (Pilha*) malloc(sizeof(Pilha));
    (*p)->topo = NULL;
}

void push(Pilha **p, void *x) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->info = x;
    novo->prox = (*p)->topo;
    (*p)->topo = novo;
}

int pop(Pilha **p, void **x) {
    if((*p)->topo == NULL) return 0; // pilha vazia
    NoPilha *aux = (*p)->topo;
    *x = aux->info;
    (*p)->topo = aux->prox;
    free(aux);
    return 1;
}

int isEmpty(Pilha *p) {
    return (p->topo == NULL);
}

void liberaPilha(Pilha **p) {
    void *aux;
    while(!isEmpty(*p)) {
        pop(p, &aux);
    }
    free(*p);
    *p = NULL;
}

/* =========================
   LISTA ENCADEADA (StringDin)
   ========================= */
struct StringDin {
    char letra;
    struct StringDin *prox;
};
typedef struct StringDin StrDin;

void Reinicia(StrDin **str){
    StrDin *aux;
    while(*str){
        aux = *str;
        *str = aux->prox;
        free(aux);
    }
}

void ReiniciaRecursao(StrDin **str){
    if(*str){
        ReiniciaRecursao(&(*str)->prox);
        free(*str);
        *str = NULL;
    }
}

void ExibeInvertido(StrDin *str){
    if(str){
        ExibeInvertido(str->prox);
        printf("%c", str->letra);
    }
}

void ExibeInvertido2(StrDin *str){
    Pilha *p;
    init(&p);
    while(str){
        push(&p, str);
        str = str->prox;
    }
    while(!isEmpty(p)){
        pop(&p, (void**)&str);
        printf("%c", str->letra);
    }
    liberaPilha(&p);
}

void tamanho(StrDin *str, int *cont){
    StrDin *aux = str;
    while(aux){
        aux = aux->prox;
        (*cont)++;
    }
}

int tamanho2(StrDin *str){
    StrDin *aux = str;
    int n=0;
    while(aux){
        aux = aux->prox;
        n++;
    }
    return n;
}

int tamanho3(StrDin *str){
    if(!str) return 0;
    return tamanho3(str->prox)+1;
}

void remover(StrDin **str, int nro, int start){
    StrDin *ant, *aux;
    if(start==0){
        while(*str && nro>0){
            aux = *str;
            *str = aux->prox;
            free(aux);
            nro--;
        }
    }
    else{
        ant = *str;
        while(ant && start>1){
            ant = ant->prox;
            start--;
        }
        if(ant){
            while(ant->prox && nro>0){
                aux = ant->prox;
                ant->prox = aux->prox;
                free(aux);
                nro--;
            }
        }
    }
}

/* =========================
   Funções auxiliares
   ========================= */
void inserirInicio(StrDin **str, char c){
    StrDin *nova = (StrDin*)malloc(sizeof(StrDin));
    nova->letra = c;
    nova->prox = *str;
    *str = nova;
}

void Exibir(StrDin *str){
    while(str){
        printf("%c", str->letra);
        str = str->prox;
    }
    printf("\n");
}

/* =========================
   MAIN
   ========================= */
int main(){
    StrDin *lista = NULL;

    // Inserindo alguns caracteres
    inserirInicio(&lista, 'o');
    inserirInicio(&lista, 'l');
    inserirInicio(&lista, 'a');
    inserirInicio(&lista, ' '); 
    inserirInicio(&lista, 'i');
    inserirInicio(&lista, 'a');
    inserirInicio(&lista, 'h');

    printf("Lista normal: ");
    Exibir(lista);

    printf("Exibe invertido (recursao): ");
    ExibeInvertido(lista);
    printf("\n");

    printf("Exibe invertido (pilha): ");
    ExibeInvertido2(lista);
    printf("\n");

    int cont=0;
    tamanho(lista, &cont);
    printf("Tamanho (versao 1): %d\n", cont);
    printf("Tamanho (versao 2): %d\n", tamanho2(lista));
    printf("Tamanho (versao 3): %d\n", tamanho3(lista));

    // Remover 2 elementos do início
    remover(&lista, 2, 0);
    printf("Depois de remover 2 do inicio: ");
    Exibir(lista);

    // Remover 2 elementos a partir da posicao 2
    remover(&lista, 2, 2);
    printf("Depois de remover 2 a partir da posicao 2: ");
    Exibir(lista);

    // Reinicia normal
    Reinicia(&lista);
    printf("Depois de Reinicia: ");
    Exibir(lista);

    // Reinserindo para testar ReiniciaRecursao
    inserirInicio(&lista, 'X');
    inserirInicio(&lista, 'Y');
    inserirInicio(&lista, 'Z');
    printf("Lista reinserida: ");
    Exibir(lista);

    ReiniciaRecursao(&lista);
    printf("Depois de ReiniciaRecursao: ");
    Exibir(lista);

    return 0;
}
