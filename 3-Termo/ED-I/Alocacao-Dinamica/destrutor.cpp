#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TpPont{
    char Nome[20];
    TpPont *prox;
};
struct TpDescritor{
    TpPont *Inicio, *Fim;
    int Qtde;
};
TpPont *NovaCaixa(char nome[20]){
    TpPont *Caixa = new TpPont;
    Caixa->prox = NULL;
    strcpy(Caixa->Nome, nome);
    return Caixa;
}
void Inicializar(TpDescritor &Desc){
    Desc.Inicio = Desc.Fim = NULL;
    Desc.Qtde=0;
}
void InsOrdenado(TpDescritor &Desc){
    TpPont *NC, *P, *ant;
    char AuxNome[20];
    printf("\n**Inserir Ordenado**\n");
    printf("\nNome: ");
    fgets(AuxNome, sizeof(AuxNome), stdin);
    AuxNome[strcspn(AuxNome, "\n")]='\0';
    while(strcmp(AuxNome, "\0")!=0){
        NC = NovaCaixa(AuxNome);
        if(Desc.Qtde==0){
            Desc.Inicio = Desc.Fim = NC;
        }
        else if(strcmp(AuxNome, Desc.Inicio->Nome)<=0){
            NC->prox = Desc.Inicio;
            Desc.Inicio = NC;
        }
        else if(strcmp(AuxNome, Desc.Fim->Nome)>=0){
            Desc.Fim->prox = NC;
            Desc.Fim = NC;
        }
        else{
            ant = Desc.Inicio;
            P = Desc.Inicio->prox;
            while(P!=NULL && strcmp(AuxNome, P->Nome)>0){
                ant = P;
                P = P->prox;
            }
            ant->prox = NC;
            NC->prox = P;
        }
        Desc.Qtde++;
        printf("Nome: ");
        fgets(AuxNome, sizeof(AuxNome), stdin);
        AuxNome[strcspn(AuxNome, "\n")]='\0';
    }
}
void Exibir(TpDescritor &Desc){
    TpPont *P = Desc.Inicio;
    printf("\n**Lista de Nomes**\n");
    if(P==NULL){
        printf("Lista vazia\n");
        return;
    }
    while(P!=NULL){
        printf("- %s\n", P->Nome);
        P = P->prox;
    }
    printf("Total de nomes: %d\n", Desc.Qtde);
    printf("Nome do inicio: %s\n", Desc.Inicio->Nome);
    printf("Nome do fim: %s\n", Desc.Fim->Nome);
}
void Excluir(TpDescritor &Desc){
    char nome;
    printf("Digite o nome para excluir:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")]='\0';
    while(strcmp(nome, "\0")!=0){
        TpPont *P = Desc.Inicio, *ant=NULL;
        while(P!=NULL && strcmp(nome, P->Nome)!=0){
            ant = P;
            P = P->prox;
        }
    }
}
int main(){
    TpDescritor lista;
    Inicializar(lista);
    InsOrdenado(lista);
    Exibir(lista);
    return 0;
}
