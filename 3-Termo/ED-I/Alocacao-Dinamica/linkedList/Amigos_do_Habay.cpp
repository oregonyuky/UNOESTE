#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct TpPont{
    char nome[30];
    char b[30];
    TpPont *ant, *prox;
};
TpPont *novaCaixa(char nome[30], char b[30]){
    TpPont *aux = new TpPont;
    strcpy(aux->nome, nome);
    strcpy(aux->b, b);
    aux->ant = NULL;
    aux->prox= NULL;
    return aux;
}
TpPont *InserirFim(TpPont *lis, char nome[30], char b[30]){
    TpPont *aux = lis;
    if(!aux)return novaCaixa(nome, b);
    while(aux->prox)aux = aux->prox;
    aux->prox = novaCaixa(nome, b);
    aux->prox->ant = aux;
    return lis;
}
TpPont *InserirOrdenada(TpPont *lis, char nome[30], char b[30]){
    TpPont *aux = lis, *busca = lis;
    while(busca){
        if(strcmp(busca->nome, nome) == 0)return lis;
        busca = busca->prox;
    }
    TpPont *nc = novaCaixa(nome, b);
    if(!lis)return nc;
    while(aux && strcmp(aux->nome, nome) < 0)aux = aux->prox;
    if(!aux){
        TpPont *fim = lis;
        while(fim->prox)fim = fim->prox;
        fim->prox = nc;
        nc->ant = fim;
    }
    else if(!aux->ant){
        nc->prox = aux;
        aux->ant = nc;
        return nc;
    }else{
        nc->prox = aux;
        nc->ant = aux->ant;
        aux->ant->prox = nc;
        aux->ant = nc;
    }
    return lis;
}
void Exibir(TpPont *lis){
    TpPont *aux = lis; 
    while(aux){
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}
const char *Vencedor(TpPont *lis){
    TpPont *aux = lis, *aux1 = NULL;
    int maior = -1;
    const char *vencedor = NULL;
    while(aux){
        if(!strcmp(aux->b, "YES")){
            if(maior < (int)strlen(aux->nome)){
                maior = (int)strlen(aux->nome);
                vencedor = aux->nome;
            }
        }
        aux = aux->prox;
    }
    return vencedor;
}
int main(){
    freopen("input.txt", "r", stdin);
    char str[30], b[4], nome[30], vencedor[30];
    strcpy(str, "");
    strcpy(b, "");
    strcpy(nome, "");
    char temp[2];
    TpPont *lis = NULL, *lis1 =NULL, *no = NULL;
    while(fgets(str, sizeof(str), stdin)){
        str[strcspn(str, "\n")]='\0';
        if(!strcmp(str, "FIM"))break;
        for(int i=0, j=0;str[i]!='\0';i++){
            temp[0] = str[i];
            temp[1] = '\0';
            if(j==0){
                if(str[i]==' ')
                    j=1;
                else strcat(nome, temp); 
            }else{ 
                strcat(b, temp); 
            } 
        } 
        lis1 = InserirFim(lis1, nome, b);
        if(!strcmp(b, "YES"))
            lis = InserirOrdenada(lis, nome, b);
        else 
            no = InserirOrdenada(no, nome, b);
        strcpy(str, "");
        strcpy(b, "");
        strcpy(nome, "");
    }
    
    Exibir(lis);
    Exibir(no);
    
    puts("");
    printf("Amigo do Habay:\n");
    printf("%s\n", Vencedor(lis1));
    return 0;
}
