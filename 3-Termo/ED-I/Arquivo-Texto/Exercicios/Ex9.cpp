#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void comecar_vogal(char arquivo[30]){
    FILE *in = fopen(arquivo, "r");
    if(in==NULL)
        puts("Erro na hora de abrir o arquivo");
    else{
        char ch, prev = ' ';
        int read_status, qtd=0;
        char vogais[] = {'a', 'e', 'i', 'o', 'u'};
        while((read_status = fscanf(in, "%c", &ch))==1){
            if(isalpha(ch) && isspace(prev)){
                for(int i=0;i<5;i++){
                    if(ch == vogais[i] || ch == toupper(vogais[i]))qtd++;
                }
            }
            prev = ch;
        }
        fclose(in);
        printf("Quantidade de palavras que iniciam com vogal: %d\n", qtd);
    }
}
int main(){
    char arquivo[30];
    puts("Digite o nome do arquivo");
    scanf("%255s", arquivo);
    comecar_vogal(arquivo);
    return 0;
}
