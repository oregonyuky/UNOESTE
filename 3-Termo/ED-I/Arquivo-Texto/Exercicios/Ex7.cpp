#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
void criptografia(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    FILE *out = fopen("novo_text.txt", "w");
    if(in==NULL || out==NULL)
        puts("Erro de abertura no arquivo");
    else{
        int c;
        while(!foef(in)){
            c = fgetc(in);
            fputc(c+4, out);
        }
    }
}

int main(){
    char arquivo[30];
    puts("Digite o nome do arquivo");
    scanf("%255s", arquivo);
    criptografia(arquivo);
    return 0;
}
