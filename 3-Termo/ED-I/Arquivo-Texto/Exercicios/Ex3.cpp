#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void comparar_arquivo(char entrada1[30], char entrada2[30]){
    FILE *arquivo1 = fopen(entrada1, "r");
    FILE *arquivo2 = fopen(entrada2, "r");
    if(arquivo1==NULL || arquivo2==NULL)
        puts("Erro na hora de abertura\n");
    else{
        char buffer[1024], buffer2[1024];
        int identical;
        while(fgets(buffer, sizeof(arquivo1), arquivo1) && fgets(buffer2, sizeof(arquivo2), arquivo2) && identical)
            identical = (strcmp(buffer, buffer2)==0);
        fclose(arquivo1);
        fclose(arquivo2);
        if(identical)
            puts("Os arquivos sao iguais\n");
        else
            puts("Os arquivos sao diferentes\n");
    }
}
int main(){
    char entrada[30], saida[30];
    printf("Digite o nome do arquivo de entrada:\n");
    scanf("%255s", entrada);
    printf("Digite o nome do arquivo de saida:\n");
    scanf("%255s", saida);
    comparar_arquivo(entrada, saida);
    return 0;
}
