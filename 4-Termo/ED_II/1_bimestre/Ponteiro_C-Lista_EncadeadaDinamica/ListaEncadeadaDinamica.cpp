#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct TpRegistro 
{
	char autores[1000],titulo_livro[1000], editora[500];
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
    char sobrenome[100];
    char nome[100];
    TpAutor *prox;
};
struct TpLivros{
    char titulo[100];
    int ano, paginas;
    TpAutor *InicioA, *FimA;
    TpLivros *ant, *prox;
};
struct TpEditora{
    char editora[100];
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
TpEditora *BuscarEditora(TpDesc &d, char editora[30]){
    TpEditora *aux = d.Inicio;
    while(aux){
        if(!strcmp(aux->editora, editora))return aux;
        aux = aux->prox;
    }
    return NULL; 
} 
TpLivros *BuscarAutor(TpEditora *d, char titulo[30]){
    TpLivros *aux = d->InicioL;
    while(aux){
        if(!strcmp(aux->titulo, titulo))return aux;
        aux = aux->prox;
    }
    return NULL;
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
void InserirLivros(TpEditora *d, char titulo[30], int ano, int paginas){
    TpLivros *aux = d->InicioL, *nc = novaCaixaL(titulo, ano, paginas);
    if(!aux)d->InicioL = d->FimL = nc;
    else{
        d->FimL->prox = nc;
        d->FimL = nc;
    }
}
void InserirAutor(TpLivros *d, char sobrenome[30], char nome[30]){
    TpAutor *aux = d->InicioA, *nc = novaCaixaA(sobrenome, nome);
    if(!aux)d->InicioA = d->FimA = nc;
    else{
        d->FimA->prox = nc;
        d->FimA = nc;
    }
}
void Exibir(TpDesc d){
    TpEditora *aux = d.Inicio;
    //printf("Editora:\n");
    puts("");
    while(aux){
        //printf("Editoras:\n");
        printf("%s\n", aux->editora);
        TpLivros *aux1 = aux->InicioL;
        //printf("Livros:\n");
        while(aux1){
            //printf("Livros:\n");
            printf("    %s %d %d\n", aux1->titulo, aux1->ano, aux1->paginas);
            TpAutor *aux2 = aux1->InicioA;
            //printf("Autores:\n");
            while(aux2){
                printf("        %s %s\n", aux2->sobrenome, aux2->nome);
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
        aux = aux->prox;
    }
}
void trim(char *str){ 
    while (isspace((unsigned char)*str)) str++;
    if (*str) {
        char *end = str + strlen(str) - 1;
        while (end > str && (isspace((unsigned char)*end) || *end == '\n' || *end == '\r'))
            end--;
        *(end + 1) = '\0';
    }
    int len = strlen(str);
    if (len > 0 && str[len - 1] == ',') str[len - 1] = '\0';
}

void funcao(TpDesc &d, TpRegistro R) {
    char autoresCopia[200];
    strcpy(autoresCopia, R.autores);

    char *ptr1, *ptr2;
    char *token = strtok_r(autoresCopia, ";", &ptr2);
    while (token) {
        trim(token);
        if (strlen(token) == 0) {
            token = strtok_r(NULL, ";", &ptr2);
            continue;
        }

        char sobrenome[100] = "", nome[100] = "";
        char *seg = strtok_r(token, ",", &ptr1);
        if (seg) {
            strcpy(sobrenome, seg);
            trim(sobrenome);
            seg = strtok_r(NULL, ",", &ptr1);
            if (seg) {
                strcpy(nome, seg);
                trim(nome);
            }
        }

        if(sobrenome[0]==' ' || sobrenome[0]=='\n'){
            for(int i=0;i<strlen(sobrenome)-1;i++){
                sobrenome[i] = sobrenome[i+1];
            }
        }
        if(nome[0]==' ' || nome[0]=='\n'){
            for(int i=0;i<strlen(nome)-1;i++){
                nome[i] = nome[i+1];
            }
        }
        printf("sobrenome: [%s] nome: [%s] titulo_livro: [%s]\n", sobrenome, nome, R.titulo_livro);

        TpEditora *ed = BuscarEditora(d, R.editora);
        TpLivros *lv = BuscarAutor(ed, R.titulo_livro);
        if(ed && lv)InserirAutor(lv, sobrenome, nome);

        token = strtok_r(NULL, ";", &ptr2);
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
	gera_arq_bin();
	//imprime();
    FILE *arq = fopen("livros.dat", "rb");
    TpRegistro R;
    TpDesc d;
    Inicializar(d);
    while(fread(&R, sizeof(TpRegistro), 1, arq)==1){
          TpEditora *ed = BuscarEditora(d, R.editora);
            if (!ed) { 
                InserirEditora(d, R.editora);
            }
        //InserirAutor(BuscarAutor(BuscarEditora(d, R.editora), R.titulo_livro), sobrenome, nome);
    }
    fclose(arq);
    arq = fopen("livros.dat", "rb");
    while(fread(&R, sizeof(TpRegistro), 1, arq)==1){
        TpEditora *ed = BuscarEditora(d, R.editora);
        TpLivros *lv = BuscarAutor(ed, R.titulo_livro);
        if (!lv) {
            InserirLivros(ed, R.titulo_livro, R.ano, R.paginas);
        }
        funcao(d, R);
    }
    Exibir(d);
	return 0;
}

