#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct TpRegistro 
{
	char autores[100],titulo_livro[100], editora[50];
	int ano, paginas;
};

void imprime()
{
	FILE *arqBin = fopen("livros.dat","rb");
    TpRegistro reg;
    fread(&reg,sizeof(TpRegistro),1,arqBin);
    while (!feof(arqBin))
	{	
    	printf("%s\n%s\n%s\t%d\t%d\n\n",reg.autores, reg.titulo_livro, reg.editora, reg.ano, reg.paginas);
        fread(&reg,sizeof(TpRegistro),1,arqBin);
    }  
}

void gera_arq_bin()
{
	FILE *arq = fopen("livros.txt","r");
    TpRegistro reg;
    FILE *arqBin = fopen("livros.dat","wb");
    fscanf(arq,"%[^|]|%[^|]|%[^|]|%d|%d", reg.autores, reg.titulo_livro, reg.editora, &reg.ano, &reg.paginas);
    while(!feof(arq))
	{
    //	printf("%s\t%s\t%s\t%d\t%d\n",reg.autores, reg.titulo, reg.editora, reg.ano, reg.pag );
    	fwrite(&reg,sizeof(TpRegistro),1,arqBin);
    	fscanf(arq,"%[^|]|%[^|]|%[^|]|%d|%d", reg.autores, reg.titulo_livro, reg.editora, &reg.ano, &reg.paginas);
    };
    fclose(arq);
    fclose(arqBin);
}

struct TpAutor{
    char sobrenome[30];
    char nome[30];
    TpAutor *prox;
};
struct TpListaAutor{
    TpAutor *InicioA, *FimA;
    TpListaAutor *prox;
};
struct TpLivros{
    char titulo[30];
    int ano, paginas;
    TpListaAutor *InicioLi, *FimLi;
    TpLivros *ant, *prox;
};
struct TpEditora{
    char editora[30];
    TpLivros *InicioL, *FimL;
    TpEditora *prox;
};
struct TpDesc{
    TpEditora *Inicio, *Fim;
    int qtd;
};
TpEditora *novaCaixaE(char editora[30]){
    TpEditora *E = (TpEditora *)malloc(sizeof(TpEditora));
    strcpy(E->editora, editora);
    E->prox = NULL;
    E->InicioL = E->FimL = NULL;
    return E;
}
TpLivros *novaCaixaL(char titulo[30], int ano, int paginas){
    TpLivros *L = (TpLivros *)malloc(sizeof(TpLivros));
    strcpy(L->titulo, titulo);
    L->paginas = paginas;
    L->ano = ano;
    L->ant = L->prox = NULL;
    L->InicioLi = L->FimLi = NULL;
    return L;
}
TpListaAutor *novaCaixaLi(void){
    TpListaAutor *L = (TpListaAutor *)malloc(sizeof(TpListaAutor));
    L->prox = NULL; 
    L->InicioA = L->FimA = NULL;
    return L;
}
TpAutor *novaCaixaA(char sobrenome[30], char nome[30]){
    TpAutor *A = (TpAutor *)malloc(sizeof(TpAutor));
    strcpy(A->sobrenome, sobrenome);
    strcpy(A->nome, nome);
    A->prox = NULL;
    return A;
}
void Inicializar(TpDesc &d){
    d.Inicio = d.Fim = NULL;
    d.qtd=0;
}
void InserirEditora(TpDesc &d, char editora[30]){
    TpEditora *aux = d.Inicio, *nc = novaCaixaE(editora);
    if(d.qtd==0){
        d.Inicio = d.Fim = nc;
    }else if(strcmp(d.Inicio->editora, editora)>0){
        nc->prox = d.Inicio;
        d.Inicio = nc;
    }else if(strcmp(d.Fim->editora, editora)<0){
        d.Fim->prox = nc;
        d.Fim = nc;
    }else{
        TpEditora *ant = d.Inicio, *aux1 = d.Inicio->prox;
        while(aux1 && strcmp(aux1->editora, editora)<0){
            ant = aux1;
            aux1 = aux1->prox;
        };
        nc->prox = aux1;
        ant->prox = nc;
    }
    d.qtd++;
}
void InserirLivros(TpEditora *l, char titulo[30], int ano, int paginas){
    TpLivros *aux = l->InicioL, *nc = novaCaixaL(titulo, ano, paginas);
    if(!aux)aux = nc;
    else{
        l->FimL->prox = nc;
        nc->ant = l->FimL;
        l->FimL = nc;
    }
}
void Exibir(TpDesc d){
    TpEditora *aux = d.Inicio;
    while(aux){
        printf("%s\n", aux->editora);
        aux = aux->prox;
    }
}
int main(void)
{
	gera_arq_bin();
	//imprime();
    FILE *arq = fopen("livros.dat", "rb");
    TpRegistro R;
    TpDesc d;
    Inicializar(d);
    while(fread(&R, sizeof(TpRegistro), 1, arq)==1){
        InserirEditora(d, R.editora);
    }
    Exibir(d);
	return 0;
}

