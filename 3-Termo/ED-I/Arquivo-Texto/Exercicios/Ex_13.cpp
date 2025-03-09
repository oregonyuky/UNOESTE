#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int comparar(char* word, char* str){
    char *p, *a[300];
    int index=0;
    p = strtok(str, " ");
    while(p!=NULL){
        a[index++] = (p);
        p = strtok(NULL, " ");
    }
    int c = 0;
    for(int i=0;i<index;i++)
        if(strcmp(a[i], word)==0)c++;
    return c;
}
void retornar_palavra(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    if(in==NULL)
        puts("Erro ao abrir o arquivo");
    else{
        char line[100], word[100];
        int maior=0, qtd=0, j=1, best_line=0;
        puts("Digite a palavra:");
        scanf("%255s", word);
        while(fgets(line, sizeof(line), in)!=NULL){
            qtd = comparar(word, line)+1;
            if(maior < qtd){
                maior = qtd;
                best_line = j;
            }
            j++;
        }
        printf("Linha: %d Quantidade de palavras: %d\n", best_line, maior);
    }
}
int main(){
    char arquivo[30];
    puts("Digite o nome do arquivo");
    scanf("%255s", arquivo);
    retornar_palavra(arquivo);
    return 0;
}
