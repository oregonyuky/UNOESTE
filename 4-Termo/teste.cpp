#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>
using namespace std;
int main(){
    FILE *arq = fopen("um.txt", "r");
    FILE *criar, *criar1;
    char s[1000];
    while(fgets(s, sizeof(s), arq)){
        s[strcspn(s, "\n")]='\0';
        //printf("%s\n", s);
        if(s[0]=='4'){
            char nome[1000];
            strcpy(nome, "");
            for(int i=4;i<strlen(s);i++){
                char temp[2];
                temp[0] = (s[i]==' ' ? '_' : s[i]);
                temp[1] = '\0';
                strcat(nome, temp);
            }
            char um[30], dois[30], tres[30], quatro[30];
            //_mkdir(nome);
            sprintf(um, "%s/1_bimestre", nome);
            sprintf(dois, "%s/2_bimestre", nome);
            _mkdir(um);
            _mkdir(dois);
            strcat(um, "/README.md");
            strcat(dois, "/README.md");
            criar = fopen(um, "w");
            criar1 = fopen(dois, "w");

        }
    }
    fclose(arq);
    fclose(criar);
    fclose(criar1);
}