#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void numerar(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    if(in==NULL)
        puts("Erro na hora de abrir o arquivo");
    else{
        char line[100];
        int i=0;
        while(fgets(line, sizeof(line), in)!=NULL)
            printf("%d %s", ++i, line);
        fclose(in);
    }
}
int main(){
    char arquivo[30];
    puts("Digite o nome do arquivo:");
    scanf("%255s", arquivo);
    numerar(arquivo);
    return 0;
}
