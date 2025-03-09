#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void contagem_1000(){
    FILE *in = fopen("novo_text.txt", "w");
    if(in==NULL)
        puts("Erro ao criar o arquivo");
    else{
        for(int i=0;i<1000;i++)
            fprintf(in, "%d\n", i);
        fprintf(in, "seunome");
        fclose(in);
        puts("Arquivo salvo com sucesso");
    }
}
void mostrar_arquivo(){
    FILE *in = fopen("novo_text.txt", "r");
    if(in==NULL)
        puts("Erro ao abrir o arquivo");
    else{
        char line[100];
        while(fgets(line, sizeof(line), in)!=NULL)
            printf("%s", line);
        fclose(in);
    }
}
int main(){
    char arquivo[30];
    contagem_1000();
    mostrar_arquivo();
    return 0;
}
