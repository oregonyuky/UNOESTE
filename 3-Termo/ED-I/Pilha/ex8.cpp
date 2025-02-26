#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "tadpilha.h"
int main(){
    TpPilhaS P;
    char op;
    do{
        Inicializar(P);
        char aux[30];
        printf("\nFrase: ");
        fflush(stdin);
        gets(aux);
        int tl = strlen(aux);
        char str[30], opp[2];
        strcpy(str, "");
        for(int i=0;aux[i]!='\0';i++){
            opp[0] = aux[i];
            opp[1] = '\0';
            strcat(str, opp);
            if(aux[i+1]==' ' || i+1==tl){
                PushS(P, str);
                strcpy(str, "");
            }
        }
        ExibirS(P);
        printf("\nDeseja continuar? <s/n>");
        op = toupper(getch());
    }while(op!='N');
}
