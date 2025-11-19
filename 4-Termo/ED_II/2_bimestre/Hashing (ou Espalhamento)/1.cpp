#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 13

// Estrutura do registro
typedef struct tpRegistro {
    int numero;
    char nome[40];
    float salario;
    char status;    // 'T' = ocupado, 'F' = vazio ou removido
    struct tpRegistro* elo;  // ponteiro para o próximo (encadeamento)
} Registro;

// Tabela hash (array de ponteiros para Registro)
Registro* tabela[n];

// Função hash
int hash(int numero) {
    return numero % n;
}

// Inicializa a tabela hash (todos os slots vazios)
void inicializaTabela() {
    for(int i = 0; i < n; i++) {
        tabela[i] = NULL;
    }
}

// Lê os dados do registro (nome e salário)
void leReg(Registro* r) {
    printf("Nome: ");
    getchar(); // limpa o \n deixado pelo scanf anterior
    fgets(r->nome, sizeof(r->nome), stdin);
    r->nome[strcspn(r->nome, "\n")] = 0; // remove \n

    printf("Salario: ");
    scanf("%f", &r->salario);
}

// Busca um número na tabela hash
// Retorna o ponteiro para o registro encontrado ou onde deveria inserir
// achou = 1 se encontrou, 0 se não
Registro** buscaHash(int numero, int* achou) {
    int pos = hash(numero);
    Registro** ptr = &tabela[pos];

    *achou = 0;

    while (*ptr != NULL) {
        if ((*ptr)->numero == numero && (*ptr)->status == 'T') {
            *achou = 1;
            return ptr; 
        }
        ptr = &((*ptr)->elo); 
    }
    return ptr; 
}
void insereHash() {
    int numero;
    printf("Numero (0 ou negativo para terminar): ");
    scanf("%d", &numero);

    while (numero > 0) {
        int achou;
        Registro** pos = buscaHash(numero, &achou);

        if (achou) {
            printf("Numero ja existente!\n\n");
        } else {
            Registro* novo = (Registro*)malloc(sizeof(Registro));
            novo->numero = numero;
            leReg(novo);
            novo->status = 'T';
            novo->elo = NULL;
            *pos = novo;
            printf("Registro inserido com sucesso!\n\n");
        }

        printf("Numero (0 ou negativo para terminar): ");
        scanf("%d", &numero);
    }
}

void exibeTabela() {
    printf("\n=== TABELA HASH ===\n");
    for(int i = 0; i < n; i++) {
        printf("[%2d]: ", i);
        Registro* p = tabela[i];
        while(p != NULL) {
            if(p->status == 'T') {
                printf("-> %d (%s) ", p->numero, p->nome);
            }
            p = p->elo;
        }
        printf("-> NULL\n");
    }
    printf("===================\n\n");
}

int main() {
    inicializaTabela();
    printf("=== CADASTRO COM TABELA HASH EM MEMORIA ===\n\n");
    insereHash();
    exibeTabela();
    return 0;
}