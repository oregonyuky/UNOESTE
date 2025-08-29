#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { VALOR, OPERADOR, FUNCAO, LISTA } TipoNodo;

struct Nodo; // declaração antecipada

typedef struct Lista {
    struct Nodo *cabeca;
    struct Nodo *cauda;
} Lista;

typedef struct {
    char nome[10];  // nome da função, ex: "pow", "sqrt"
    int numArgs;    // número de argumentos
} FuncInfo;

typedef struct Nodo {
    TipoNodo tipo;
    union {
        float valor;         // VALOR
        char operador;       // OPERADOR (+, -, *, /)
        FuncInfo funcao;     // FUNCAO
        Lista lista;         // LISTA (cabeca/cauda)
    } dado;
    struct Nodo *prox;
} Nodo;
float resolverNodo(Nodo *n);

Nodo *novoValor(float v) {
    Nodo *n = malloc(sizeof(Nodo));
    n->tipo = VALOR;
    n->dado.valor = v;
    n->prox = NULL;
    return n;
}

Nodo *novoOperador(char op) {
    Nodo *n = malloc(sizeof(Nodo));
    n->tipo = OPERADOR;
    n->dado.operador = op;
    n->prox = NULL;
    return n;
}

Nodo *novaFuncao(const char *nome, int numArgs) {
    Nodo *n = malloc(sizeof(Nodo));
    n->tipo = FUNCAO;
    strcpy(n->dado.funcao.nome, nome);
    n->dado.funcao.numArgs = numArgs;
    n->prox = NULL;
    return n;
}

Nodo *novaLista() {
    Nodo *n = malloc(sizeof(Nodo));
    n->tipo = LISTA;
    n->dado.lista.cabeca = NULL;
    n->dado.lista.cauda = NULL;
    n->prox = NULL;
    return n;
}

void inserirNodo(Lista *lista, Nodo *n) {
    if (!lista->cabeca) {
        lista->cabeca = lista->cauda = n;
    } else {
        lista->cauda->prox = n;
        lista->cauda = n;
    }
}

float aplicarOperador(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

float aplicarFuncao(FuncInfo f, float *args) {
    if (strcmp(f.nome, "sqrt") == 0) return sqrt(args[0]);
    if (strcmp(f.nome, "sin") == 0)  return sin(args[0]);
    if (strcmp(f.nome, "cos") == 0)  return cos(args[0]);
    if (strcmp(f.nome, "pow") == 0)  return pow(args[0], args[1]);
    return 0;
}


// Resolve uma lista simples (sem sublistas)
float resolverLista(Lista *l) {
    Nodo *atual = l->cabeca;

    // Primeiro: resolver recursivamente todas as sublistas (LISTA)
    while (atual) {
        if (atual->tipo == LISTA) {
            float res = resolverLista(&atual->dado.lista);
            atual->tipo = VALOR;
            atual->dado.valor = res;
        }
        atual = atual->prox;
    }

    // Segundo: processar fun��es
    atual = l->cabeca;
    while (atual) {
        if (atual->tipo == FUNCAO) {
            float args[2];
            Nodo *argNode = atual->prox;
            int i = 0;
            for (; i < atual->dado.funcao.numArgs; i++) {
                args[i] = resolverNodo(argNode);
                Nodo *tmp = argNode;
                argNode = argNode->prox;
                free(tmp);
            }
            float res = aplicarFuncao(atual->dado.funcao, args);
            atual->tipo = VALOR;
            atual->dado.valor = res;
            atual->prox = argNode;
        }
        atual = atual->prox;
    }

    // Terceiro: operadores * e /
    atual = l->cabeca;
    while (atual && atual->prox && atual->prox->prox) {
        if (atual->prox->tipo == OPERADOR &&
            (atual->prox->dado.operador == '*' || atual->prox->dado.operador == '/')) {
            float a = resolverNodo(atual);
            float b = resolverNodo(atual->prox->prox);
            float res = aplicarOperador(a, b, atual->prox->dado.operador);
            atual->tipo = VALOR;
            atual->dado.valor = res;
            Nodo *tmp1 = atual->prox;
            Nodo *tmp2 = tmp1->prox;
            atual->prox = tmp2->prox;
            free(tmp1);
            free(tmp2);
        } else {
            atual = atual->prox;
        }
    }

    // Quarto: operadores + e -
    atual = l->cabeca;
    while (atual && atual->prox && atual->prox->prox) {
        if (atual->prox->tipo == OPERADOR) {
            float a = resolverNodo(atual);
            float b = resolverNodo(atual->prox->prox);
            float res = aplicarOperador(a, b, atual->prox->dado.operador);
            atual->tipo = VALOR;
            atual->dado.valor = res;
            Nodo *tmp1 = atual->prox;
            Nodo *tmp2 = tmp1->prox;
            atual->prox = tmp2->prox;
            free(tmp1);
            free(tmp2);
        } else {
            atual = atual->prox;
        }
    }

    return l->cabeca->dado.valor;
}
float resolverNodo(Nodo *n) {
    if (n->tipo == VALOR) {
        return n->dado.valor;
    }
    else if (n->tipo == LISTA) {
        return resolverLista(&n->dado.lista);
    }
    else {
        fprintf(stderr, "Erro: Nodo inesperado em resolverNodo\n");
        exit(1);
    }
}


int main() {
    // Exemplo: simulação manual de "2 + (3 - 5 * (pow(2,3) - 3) - 8)"
    Lista principal = {0};

    inserirNodo(&principal, novoValor(2));
    inserirNodo(&principal, novoOperador('+'));

    // sublista
    Nodo *subLista1 = novaLista();
    Lista *l1 = &subLista1->dado.lista;
    inserirNodo(l1, novoValor(3));
    inserirNodo(l1, novoOperador('-'));
    inserirNodo(l1, novoValor(5));
    inserirNodo(l1, novoOperador('*'));

    // sub-sublista
    Nodo *subLista2 = novaLista();
    Lista *l2 = &subLista2->dado.lista;
    inserirNodo(l2, novaFuncao("pow", 2));
    inserirNodo(l2, novoValor(2));
    inserirNodo(l2, novoValor(3));
    inserirNodo(l2, novoOperador('-'));
    inserirNodo(l2, novoValor(3));

    inserirNodo(l1, subLista2);
    inserirNodo(l1, novoOperador('-'));
    inserirNodo(l1, novoValor(8));
    inserirNodo(l1, novoOperador('+'));
    inserirNodo(l1, novoValor(3));

    inserirNodo(&principal, subLista1);

    // Agora resolvendo
    // Aqui, para simplificar, vamos fingir que cada sublista é resolvida chamando resolverLista()
    // No exercício real, você faria recursão para encontrar e resolver as mais internas primeiro

    // resolve sub-sublista
    float res2 = resolverLista(l2);
    l2->cabeca = novoValor(res2);
    l2->cauda = l2->cabeca;

    // resolve sublista
    float res1 = resolverLista(l1);
    l1->cabeca = novoValor(res1);
    l1->cauda = l1->cabeca;

    // resolve principal
    float final = resolverLista(&principal);

    printf("Resultado final: %.2f\n", final);

    return 0;
}
