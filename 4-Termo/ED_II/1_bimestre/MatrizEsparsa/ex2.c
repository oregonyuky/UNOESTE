#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL 10   // número máximo de anos
#define NC 10   // número máximo de clientes

typedef struct matrizEsp {
    int lin, col, valor;
    struct matrizEsp *pc, *pl;
} MatEsp;

// Inicializa os vetores de cabeças
void inicializar(MatEsp *vetLin[], MatEsp *vetCol[]) {
    for (int i = 0; i < NL; i++) vetLin[i] = NULL;
    for (int i = 0; i < NC; i++) vetCol[i] = NULL;
}

// Verifica se já existe um nó na posição
void verificaOcupado(MatEsp *pLinha, int col, MatEsp **aux) {
    while (pLinha && col > pLinha->col) pLinha = pLinha->pl;
    if (pLinha && pLinha->col == col)
        *aux = pLinha;
    else
        *aux = NULL;
}

// Insere ou atualiza um valor na matriz esparsa
void insere(MatEsp *vetLin[], MatEsp *vetCol[], int lin, int col, int valor) {
    MatEsp *aux;
    verificaOcupado(vetLin[lin], col, &aux);
    if (aux) {
        aux->valor += valor; // incrementa se já existe
        return;
    }

    MatEsp *nova = (MatEsp*)malloc(sizeof(MatEsp));
    nova->lin = lin;
    nova->col = col;
    nova->valor = valor;
    nova->pl = nova->pc = NULL;

    // Insere na linha
    MatEsp *plinha = vetLin[lin], *ant = NULL;
    while (plinha && col > plinha->col) {
        ant = plinha;
        plinha = plinha->pl;
    }
    if (!ant) vetLin[lin] = nova;
    else ant->pl = nova;
    nova->pl = plinha;

    // Insere na coluna
    MatEsp *pColuna = vetCol[col];
    ant = NULL;
    while (pColuna && lin > pColuna->lin) {
        ant = pColuna;
        pColuna = pColuna->pc;
    }
    if (!ant) vetCol[col] = nova;
    else ant->pc = nova;
    nova->pc = pColuna;
}

// Função para exibir o relatório
void relatorio(MatEsp *vetLin[], MatEsp *vetCol[], char clientes[][50], char anos[][10]) {
    for (int j = 0; j < NC; j++) {
        MatEsp *p = vetCol[j];
        while (p) {
            printf("Cliente: %s\n", clientes[j]);
            printf("  Ano %s = %d vez(es)\n", anos[p->lin], p->valor);
            p = p->pc;
        }
    }
}

int main() {
    MatEsp *vetLin[NL], *vetCol[NC];
    inicializar(vetLin, vetCol);

    // Dados de exemplo
    char clientes[NC][50] = {"Ursula", "Adelia", "Clenilce", "Gilsana"};
    char anos[NL][10] = {"2003", "2004", "2005", "2006"};

    // Inserir os dados conforme o relatório da imagem
    insere(vetLin, vetCol, 3, 0, 1); // 2006 -> Ursula 1
    insere(vetLin, vetCol, 2, 1, 1); // 2005 -> Adelia 1
    insere(vetLin, vetCol, 0, 2, 3); // 2003 -> Clenilce 3
    insere(vetLin, vetCol, 1, 3, 1); // 2004 -> Gilsana 1

    // Exibir relatório
    relatorio(vetLin, vetCol, clientes, anos);


    return 0;
}
