#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Pessoa {
    char CPF[15];
    char Nome[50];
    char Endereco[50];
    char Estado[3];
    char Email[50];
};

struct Cidade {
    int CodCidade;
    char NomeCidade[50];
    char Estado[3];
};

struct Passagem {
    int NroPassagem;
    int CodVoo;
    char CPF[15];
    int CodCidade;
    char DataCompra[11];
    int Poltrona;
    struct Pessoa *Inicio, *Fim; // ← IGNORADO neste exercício
    struct Passagem *ant, *prox;
};

struct Voo {
    int CodVoo;
    char DataVoo[11];
    int NroLugares;
    int CodCidadeOrigem;
    int CodCidadeDestino;
    struct Passagem *Inicio, *Fim;
    struct Voo *ant, *prox;
};

struct TpDesc {
    Voo *Inicio, *Fim;
    int qtd;
};

// ---------- Inicializa descritor ----------
void Inicializar(TpDesc &d) {
    d.Inicio = d.Fim = NULL;
    d.qtd = 0;
}

// ---------- Cria novo nó de voo ----------
Voo* novaCaixa(Voo aux) {
    Voo* v = (Voo*) malloc(sizeof(Voo));
    *v = aux;
    v->Inicio = v->Fim = NULL;
    v->ant = v->prox = NULL;
    return v;
}

// ---------- Insere voo no fim ----------
void InserirFimVoo(TpDesc &d, Voo v) {
    Voo *nc = novaCaixa(v);
    if (d.qtd == 0) {
        d.Inicio = d.Fim = nc;
    } else {
        d.Fim->prox = nc;
        nc->ant = d.Fim;
        d.Fim = nc;
    }
    d.qtd++;
}

// ---------- Insere passagem no fim da sublista de um voo ----------
void InserirPassagemFim(Voo* voo, Passagem* p) {
    p->ant = p->prox = NULL;
    if (voo->Inicio == NULL) {
        voo->Inicio = voo->Fim = p;
    } else {
        voo->Fim->prox = p;
        p->ant = voo->Fim;
        voo->Fim = p;
    }
}

// ---------- Busca voo por código ----------
Voo* buscarVoo(TpDesc d, int cod) {
    Voo* p = d.Inicio;
    while (p) {
        if (p->CodVoo == cod) return p;
        p = p->prox;
    }
    return NULL;
}

// ---------- Carrega voos ----------
void carregarVoos(const char nomeArquivo[30], TpDesc &d) {
    FILE *arq = fopen(nomeArquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    Voo v;
    while (fread(&v, sizeof(Voo), 1, arq) == 1) {
        InserirFimVoo(d, v);
    }

    fclose(arq);
}

// ---------- Carrega passagens e vincula aos voos ----------
void carregarPassagens(const char nomeArquivo[30], TpDesc &d) {
    FILE *arq = fopen(nomeArquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    Passagem p;
    while (fread(&p, sizeof(Passagem), 1, arq) == 1) {
        Passagem *nova = (Passagem*) malloc(sizeof(Passagem));
        *nova = p;
        nova->ant = nova->prox = NULL;

        Voo* v = buscarVoo(d, p.CodVoo);
        if (v) {
            InserirPassagemFim(v, nova);
        }
    }

    fclose(arq);
}

// ---------- Carrega vetor de pessoas ----------
void carregarPessoas(const char nomeArquivo[30], Pessoa pessoas[], int &qtd) {
    FILE* f = fopen(nomeArquivo, "rb");
    if (!f) return;
    while (fread(&pessoas[qtd], sizeof(Pessoa), 1, f) == 1)
        qtd++;
    fclose(f);
}

// ---------- Carrega vetor de cidades ----------
void carregarCidades(const char nomeArquivo[30], Cidade cidades[], int &qtd) {
    FILE* f = fopen(nomeArquivo, "rb");
    if (!f) return;
    while (fread(&cidades[qtd], sizeof(Cidade), 1, f) == 1)
        qtd++;
    fclose(f);
}

// ---------- Mostrar estrutura ----------
void MostrarEstrutura(TpDesc d) {
    Voo* v = d.Inicio;
    while (v) {
        printf("\nVoo %d - %s (%d lugares) | Origem %d → Destino %d\n",
               v->CodVoo, v->DataVoo, v->NroLugares, v->CodCidadeOrigem, v->CodCidadeDestino);
        Passagem* p = v->Inicio;
        while (p) {
            printf("  Passagem %d - CPF: %s - Poltrona %d - Compra: %s - Cidade: %d\n",
                   p->NroPassagem, p->CPF, p->Poltrona, p->DataCompra, p->CodCidade);
            p = p->prox;
        }
        v = v->prox;
    }
}
void ExcluirVoo(TpDesc &d, int codVoo) {
    Voo* v = d.Inicio;

    // Buscar o voo com o código informado
    while (v && v->CodVoo != codVoo)
        v = v->prox;

    if (!v) {
        printf("Voo %d não encontrado.\n", codVoo);
        return;
    }

    // 1. Liberar todas as passagens do voo
    Passagem* p = v->Inicio;
    while (p) {
        Passagem* temp = p;
        p = p->prox;
        free(temp);
    }

    // 2. Ajustar ponteiros da lista duplamente encadeada
    if (v->ant) v->ant->prox = v->prox;
    else d.Inicio = v->prox;

    if (v->prox) v->prox->ant = v->ant;
    else d.Fim = v->ant;

    // 3. Liberar o voo
    free(v);
    d.qtd--;

    printf("Voo %d excluído com sucesso.\n", codVoo);
}
// ---------- MAIN ----------
int main() {
    TpDesc d;
    Pessoa pessoas[MAX];
    Cidade cidades[MAX];
    int qtdPessoas = 0, qtdCidades = 0;

    Inicializar(d);

    carregarVoos("voos.bin", d);
    carregarPassagens("passagens.bin", d);
    carregarPessoas("pessoas.bin", pessoas, qtdPessoas);
    carregarCidades("cidades.bin", cidades, qtdCidades);

    MostrarEstrutura(d);

    printf("\nTotal de pessoas: %d | Total de cidades: %d\n", qtdPessoas, qtdCidades);
    return 0;
}
