#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
void letras_maiusculo(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    FILE *out = fopen("novo_text.txt", "w");
    if(in==NULL || out==NULL)
        puts("Erros na hora de abrir o arquivo");
    else{
        while((read_status = fscanf(in, "%c", &ch))==1){
            if(isalpha(ch) && isspace(prev))
                fputc(toupper(ch), out);
            else
                fputc(ch, out);
            prev = ch;
        }        
        fclose(in);
        fclose(out);
        puts("Arquivo convertido com sucesso para novo_text.txt\n");
    }
}   
int main(){
    char arquivo_entrada[30], arquivo_saida;
    printf("Digite o nome do arquivo de entrada:\n");
    scanf("%255s", arquivo_entrada);
    letras_maiusculo(arquivo_entrada);
    return 0;
}
