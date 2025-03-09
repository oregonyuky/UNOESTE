#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
void retornar_linha(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    if(in==NULL)
        puts("Erro ao abrir o arquivo");
    else{
        char letra, line[100];
        int qtd=0, j=1, best_line=0, maior=INT_MIN;
        puts("Digite uma letra:");
        scanf(" %c", &letra);
        while(fgets(line, sizeof(line), in)!=NULL){
            qtd=0;
            for(int i=0;line[i]!='\0';i++){
                if(letra==line[i])qtd++;
            }
            if(maior < qtd){
                maior = qtd;
                best_line = j;
            }
            j++;
        }
        fclose(in);
        printf("A linha que tem maior quantidade desse caractere eh: %d com %d caracteres\n", best_line, maior);
    }
}
int main(){
    char arquivo[30];
    puts("Digite o nome do arquvo:");
    scanf("%255s", arquivo);
    retornar_linha(arquivo);
    return 0;
}
