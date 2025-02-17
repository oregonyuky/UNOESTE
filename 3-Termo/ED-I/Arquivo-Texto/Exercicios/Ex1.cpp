#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void to_uppercase_file(char inputFile, char outputFile){
    FILE *entrada = fopen(inputFile, "r");
    if(entrada == NULL){
        printf("Erro ao abrir arquivo de entrada\n");
        return;
    }
    FILE *output = fopen(outputFile, "w");
    if(output == NULL){
        printf("Erro ao abrir arquivo de saida\n");
        return;
    }
    int c;
    while(!feof(entrada)){
        c = fgetc(entrada);
        if(!feof(entrada)){
            fputc(toupper(c), output);
        }
    }
    fclose(entrada);
    fclose(output);
}
int main(){
    char entrada[256], output[256];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%255s", entrada);
    printf("Digite o nome do arquivo de saida: ");
    scanf("%255s", output);
    to_uppercase_file(entrada, saida);
    printf("Arquivo convertido com sucesso.\n");
    return 0;
}
