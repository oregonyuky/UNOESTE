#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <windows.h>
bool isOperand(char x){
    return (x>='1' && x<='9');
}
int conta(char str[30]){
    int n[3], l=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            if(str[i+2]=='+')n[++l] = (str[i+1]-'0')+(str[i+3]-'0');
            if(str[i+2]=='-')n[++l] = (str[i+1]-'0')-(str[i+3]-'0');
            if(str[i+2]=='*')n[++l] = (str[i+1]-'0')*(str[i+3]-'0');
            if(str[i+2]=='/')n[++l] = (str[i+1]-'0')/(str[i+3]-'0');
        }

    }
    int num;
    if(l!=2){
        if(isOperand(str[0])){
            if(str[1]=='+')num = (str[0]-'0')+n[1];
            if(str[1]=='-')num = (str[0]-'0')-n[1];
            if(str[1]=='*')num = (str[0]-'0')*n[1];
            if(str[1]=='/')num = (str[0]-'0')/n[1];
        }
        else{
            if(str[5]=='+')num = n[1]+(str[6]-'0');
            if(str[5]=='-')num = n[1]-(str[6]-'0');
            if(str[5]=='*')num = n[1]*(str[6]-'0');
            if(str[5]=='/')num = n[1]/(str[6]-'0');
        }
    }
    else{
        if(str[5]=='+')num = n[1]+n[2];
        if(str[5]=='-')num = n[1]-n[2];
        if(str[5]=='*')num = n[1]*n[2];
        if(str[5]=='/')num = n[1]/n[2];
    }
    return num;
}
void PosFixada(){
    TpPilhaS P1;
    char aux[30], op[2], op1[30], op2[30], opp, temp[30];
    do{
        Inicializar(P1);
        printf("\nPOS FIXADA: ");
        fflush(stdin);
        gets(aux);
        for(int i=0;aux[i]!='\0';i++){
            if(isOperand(aux[i])){
                op[0] = aux[i];
                op[1] = '\0';
                PushS(P1, op);
            }
            else{
                strcpy(op1, P1.PILHA[P1.TOPO]);
                PopS(P1);
                strcpy(op2, P1.PILHA[P1.TOPO]);
                PopS(P1);
                op[0] = aux[i];
                op[1] = '\0';
                strcpy(temp, "(");
                strcat(temp, op2);
                strcat(temp, op);
                strcat(temp, op1);
                strcat(temp, ")");
                PushS(P1, temp);
            }
        }
        printf("\n");
        for(int i=0;i<strlen(P1.PILHA[P1.TOPO])-1;i++)
            P1.PILHA[P1.TOPO][i] = P1.PILHA[P1.TOPO][i+1];
        P1.PILHA[P1.TOPO][strlen(P1.PILHA[P1.TOPO])-2] = '\0';
        printf("\n%s = %d\n", P1.PILHA[P1.TOPO], conta(P1.PILHA[P1.TOPO]));
		printf("\nDeseja continuar: <s/n>?");
		opp = toupper(getch());
    }while(opp!='N');
}
