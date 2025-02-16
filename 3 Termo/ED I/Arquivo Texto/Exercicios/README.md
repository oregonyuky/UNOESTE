# Ex 1
```cpp
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
```
# Ex 2
```cpp
#include <stdio.h>
#include <ctype.h>
void analyzeFile(const char* inputFile){
    FILE *inFile = fopen(inputFile, "r");
    if(!inFile){
        perror("Erro ao abrir o arquivo de entrada");
        return;
    }
    int c;
    int letterCount = 0, spaceCount = 0, lineCount = 0;  
    while(!feof(inFile)){
        c = fgetc(inFile);
        if(!feof(inFile)){
            if (isalpha(c)) letterCount++;
            else if (c == ' ') spaceCount++;
            else if (c == '\n') lineCount++;
        }
    }
    
    printf("Letras: %d\n", letterCount);
    printf("Espaços: %d\n", spaceCount);
    printf("Linhas: %d\n", lineCount);
    fclose(inFile);
}
int main() {
    const char* inputFile = "input.txt"; 
    analyzeFile(inputFile);
    return 0;
}
```
# Ex 3
```cpp
#include <stdio.h>
#include <stdbool.h>

int compareFiles(char file1, char file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    
    if (!f1 || !f2) {
        perror("Erro ao abrir um dos arquivos");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return false;
    }
    
    int c1, c2;
    bool areIdentical = true;
    
    while (!feof(f1) && !feof(f2) && areIdentical) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        
        if (c1 != c2) {
            areIdentical = false;
        }
    }
    
    if (feof(f1) != feof(f2)) {
        areIdentical = false;
    }
    
    fclose(f1);
    fclose(f2);
    
    return areIdentical;
}

int main() {
    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";
    
    if (compareFiles(file1, file2)) {
        printf("Os arquivos são idênticos.\n");
    } else {
        printf("Os arquivos são diferentes.\n");
    }
    
    return 0;
}
```
# Ex 4
```cpp
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void capitalizarPrimeirasLetras(const char *arquivoEntrada, const char *arquivoSaida) {
    FILE *entrada = fopen(arquivoEntrada, "r");
    FILE *saida = fopen(arquivoSaida, "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char ch;
    int novoNome = 1;

    while (!feof(entrada)) {
        ch = fgetc(entrada);

        if (feof(entrada)) break;

        if (novoNome && isalpha(ch)) {
            ch = toupper(ch);
            novoNome = 0;
        } else if (!isalpha(ch)) {
            novoNome = 1;
        }

        fputc(ch, saida);
    }

    fclose(entrada);
    fclose(saida);
}

int main() {
    char arquivoEntrada[100], arquivoSaida[100];

    printf("Digite o caminho do arquivo de entrada: ");
    scanf("%s", arquivoEntrada);
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", arquivoSaida);

    capitalizarPrimeirasLetras(arquivoEntrada, arquivoSaida);

    printf("Arquivo com as primeiras letras maiúsculas criado com sucesso!\n");

    return 0;
}
```

