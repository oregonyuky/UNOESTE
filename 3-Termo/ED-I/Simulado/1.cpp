#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pmNpilhas.h"
char  size(tpPilha p, int i){
    return p.TOPO[i] - p.BASE[i] + 1;
}
void gravar(tpPilha p, tpPilha aux, FILE *arq1, int j){
    char nova_str[100];
    nova_str[0] = '\0';
    int len;
    for(int i=0;i<=j;i++){
        if(!vazia(p, i)){
            while(!vazia(p, i)){
                len = strlen(nova_str);
                nova_str[len] = pop(p, i);
                nova_str[len+1] = '\0';
            }
            strcat(nova_str, " ");
            
        }
        else{
            while(!vazia(aux, i)){
                len = strlen(nova_str);
                nova_str[len] = pop(aux, i);
                nova_str[len+1] = '\0';
            }
            strcat(nova_str, " ");
        }
    }
    fprintf(arq1, "%s\n", nova_str);
}
int main(){
    FILE *arq = fopen("input.txt", "r");
    FILE *arq1 = fopen("output.txt", "w");
    if(arq==NULL)printf("Erro na hora de ler o arquivo\n");
    else{
        char str[100];
        tpPilha p, aux;
        int np = 20, c;
        inicializar(p, np);
        inicializar(aux, np);
        while(fgets(str, sizeof(str), arq))printf("%s", str);
        printf("\nDigite quantidade de caracteres: ");
        scanf("%d", &c);
        rewind(arq);
        while(fgets(str, sizeof(str), arq)){
            int j=0;
            for(int i=0;str[i]!='\n';i++){
                if(str[i]!=' ' && str[i]!='\n')push(p, j, str[i]);
                else if(str[i]==' ')j++;
            }
            for(int i=0;i<=j;i++){
                if(size(p, i) != c){
                    while(!vazia(p, i))
                        push(aux, i, pop(p, i));
                }
            }
            for(int i=0;i<=j;i++){
                if(vazia(p, i)){
                    exibir(aux, i);
                }
                else
                    exibir(p, i);
                printf(" ");
            }
            gravar(p, aux, arq1, j);
            inicializar(p, np);
            inicializar(aux, np);
            printf("\n");
        }
        printf("\n");
        fclose(arq);
        fclose(arq1);
    }
    return 0;
}
