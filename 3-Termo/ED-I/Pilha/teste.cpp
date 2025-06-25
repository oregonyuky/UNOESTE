#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *arq = fopen("um.txt", "r");
    FILE *criar;
    if(arq==NULL)return 1;
    char ch[100];
    char nov[100];
    while(fgets(ch, sizeof(ch), arq)){
        //printf("%s", ch);
        strcpy(nov, "");
        char temp[2];
        for(int i=0;i<strlen(ch);i++){

            temp[0] = ch[i]; temp[1] = '\0';
            if(ch[i]=='F' && ch[i+1]=='a' && ch[i+2]=='v' && i<strlen(ch)-2)break;
            if(isalpha(ch[i])){
                strcat(nov, temp);
            }else if(isalpha(ch[i-1]) && ch[i]==' ' && i>0){
                strcat(nov, temp);
            }
        }
        for(int i=0;nov[i]!='\0';i++){
            if(nov[i]==' ')nov[i]='_';
        }
        strcat(nov, ".cpp");
        printf("%s\n", nov);
        criar = fopen(nov, "w");
    }
    fclose(criar);
    fclose(arq);
    return 0;
}

