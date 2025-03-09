#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void contar_caracteres(char arquivo[30]){
    int c;
    int espacos=0, linhas=0, letras=0;
    FILE *entrada = fopen(arquivo, "r");
    if(entrada == NULL)
        printf("Erro na hora de abertura\n");
    else{
        while(!feof(entrada)){
            c = fgetc(entrada);
            if(isspace(c))espacos++;
            else if(isalpha(c))letras++;
            else if(c=='\n')linhas++;
            if(!feof(entrada))
                printf("%c", c);
        }
        puts("\n");
        if(linhas==0)linhas=1;
        printf("Quantidade de espaco: %d\n", espacos);
        printf("Quantidade de letras: %d\n", letras);
        printf("Quantidade de linhas: %d\n", linhas);
    }
}
int main(){
    char arquivo[30];
    puts("Digite o nome do arquivo:\n");
    scanf("%255s", arquivo);
    contar_caracteres(arquivo);
    return 0;
}
