#include <stdio.h>
#include <ctype.h>
void convertToUppercase(char inputFile,char outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    if(!inFile){
        perror("Erro ao abrir o arquivo de entrada");
        return;
    }
    FILE *outFile = fopen(outputFile, "w");
    if(!outFile){
        perror("Erro ao criar o arquivo de saída");
        fclose(inFile);
        return;
    }
    int c;
    while (!feof(inFile)){
        c = fgetc(inFile);
        if (!feof(inFile)) {
            fputc(toupper(c), outFile);
        }
    }
    printf("Conversão concluída. Arquivo salvo como %s\n", outputFile);
    fclose(inFile);
    fclose(outFile);
}
int main() {
    const char* inputFile = "input.txt";  
    const char* outputFile = "output.txt"; 
    convertToUppercase(inputFile, outputFile);
    return 0;
}
