#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void Quntidade_de_letras_espacos_linhas(char inFile[30], char outFile[30]){
    FILE *entrada = fopen(inFile, "r");
    if(entrada == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    FILE *saida = fopen(outFile, "w");
    if(saida == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    int c;
    while(!feof(entrada)){
        c = 
    }
}
