#include <conio2.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXPILHA 30
struct TpPilha{
	int TOPO, idade;
	char PILHA[MAXPILHA];
};
struct TpPilhaS{
	int TOPO;
	char PILHA[MAXPILHA][30], Nomeinicial[30];
};
struct TpElemento{
	int TOPO;
	char PILHA[MAXPILHA][30], Nomeinicial[30];
};
void Inicializar(TpPilha &P){
	P.TOPO = -1;
}
void Inicializar(TpPilhaS &P){
	P.TOPO = -1;
}
void Push(TpPilha &P, char elemento){
	P.PILHA[++P.TOPO] = elemento;
}
void PushS(TpPilhaS &P, char elemento[30]){
    strcpy(P.PILHA[++P.TOPO], elemento);
}
char Pop(TpPilha &P){
	return P.PILHA[P.TOPO--];
}
void PopS(TpPilhaS &P){
	P.PILHA[P.TOPO--][0]='\0';
}
char elementoTopo(TpPilha P){
	return P.PILHA[P.TOPO];
}
char Vazia(int topo){
	return (topo==-1);
}
char Cheia(int topo){
	return (topo==MAXPILHA-1);
}
void PushSS(TpPilhaS &P, char linha[30]){
    if (!Cheia(P.TOPO)) {
        strcpy(P.PILHA[++P.TOPO], linha);
    } else {
        printf("Pilha cheia! Não �Epossú�el adicionar mais linhas.\n");
    }
}
void PopSS(TpPilhaS &P, char linha[30]){
	 if (!Vazia(P.TOPO)) {
        strcpy(linha, P.PILHA[P.TOPO--]);
    } else {
        printf("Pilha vazia! Não �Epossú�el remover elementos.\n");
    }
}
void Exibir(TpPilha P){
	while(!Vazia(P.TOPO))
		printf("%c ", Pop(P));
	printf("\n");
}
void ExibirS(TpPilhaS P){
	while(!Vazia(P.TOPO)){
		printf("%s ", P.PILHA[P.TOPO]);
		PopS(P);
	}
}
//Fun?es
char Menu(void)
{
	clrscr();
	printf("### Operacoes sobre Pilha ###\n");
	printf("[A] Inicializar\n");
	printf("[B] Empilhar (PUSH)\n");
	printf("[C] Desempilhar (POP)\n");
	printf("[D] Elemento do Topo\n");
	printf("[E] Exibir a Pilha\n");
	printf("[F] Exerc. 01 - Concatenacao de Pilhas\n");
	printf("[G] Exerc. 02 - Exclusao\n");
	printf("[H] Exerc. 03 - Posfixada - Infixada\n");
    printf("[I] Exerc. 04 - Sorteio\n");
    printf("[J] Exerc. 05 - Inversa\n");
    printf("[K] Exerc. 06 - Arquivo de texto\n");
    printf("[L] Exerc. 07 - Palindromo\n");
    printf("[M] Exerc. 08 - Frase Inversa\n");
	printf("[ESC] Sair\n");
	printf("\nOpcao: ");
	return toupper(getche());
}

char LeElemento(void)
{
	printf("\nElemento: ");
	return getche();
}

void InserirElementos(TpPilha &P)
{
	char Elemento;
	Inicializar(P);
	printf("\nDigite os Elementos:\n");
	Elemento = getche();
	while (Elemento!=27 && !Cheia(P.TOPO))
	{
		Push(P,Elemento);
		Elemento = getche();
	}
}

void Concatenacao(TpPilha &P1, TpPilha P2)
{
	TpPilha P3;
	Inicializar(P3);
	while (!Vazia(P2.TOPO))
		Push(P3,Pop(P2));
		
	while (!Vazia(P3.TOPO) && !Cheia(P1.TOPO))
			Push(P1,Pop(P3));
}
void Exclusao(TpPilha &P)
{
	TpPilha P1;
	int pos, e, a;
	do{
		Inicializar(P1);
		e = LeElemento();
		pos=0;
		while(pos<P.TOPO && e!=P.PILHA[pos])
			pos++;
		if(pos<P.TOPO){
			a = P.TOPO-pos;
			while(a--)
				Push(P1, Pop(P));
			Pop(P);
			while(!Vazia(P1.TOPO) && !Cheia(P.TOPO))
				Push(P, Pop(P1));
		}
		else
			printf("Nao encontrado\n");
	}while(e!=27);
}
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
void Sorteio(){
    TpPilha P1, P2, P3, P4, P5, P6, P7, P8, P9;
    srand(time(NULL));
    char op, alp[27] = "abcdefghi";
    int sorteio, num, pilha;
    Inicializar(P1);
	Inicializar(P2);
	Inicializar(P3);
	Inicializar(P4);
	Inicializar(P5);
	Inicializar(P6);
	Inicializar(P7);
	Inicializar(P8);
	Inicializar(P9);
	for(int i=0;i<9;i++){    	
        	Push(P1, alp[i]);
        	Push(P2, alp[i]);
	        Push(P3, alp[i]);
	        Push(P4, alp[i]);
	        Push(P5, alp[i]);
	        Push(P6, alp[i]);
	        Push(P7, alp[i]);
	        Push(P8, alp[i]);
	        Push(P9, alp[i]);
	    }
    do{
        printf("\nDeseja comecar o sorteio? <s/n>");
        op = toupper(getch());
        if(op=='S'){
            sorteio = rand() % 2;
            pilha = rand() % 9;
            num = rand() % 9;
            //printf("\n%d\n", sorteio);
            if(sorteio==0){
            	//printf("\n%d\n", pilha);
                switch(pilha){
                    case 0:Push(P1, alp[num]);break;
                    case 1:Push(P2, alp[num]);break;
                    case 2:Push(P3, alp[num]);break;
                    case 3:Push(P4, alp[num]);break;
                    case 4:Push(P5, alp[num]);break;
                    case 5:Push(P6, alp[num]);break;
                    case 6:Push(P7, alp[num]);break;
                    case 7:Push(P8, alp[num]);break;
                    case 8:Push(P9, alp[num]);break;
                }
            }
            else{
                switch(pilha){
                    case 0:Pop(P1);break;
                    case 1:Pop(P2);break;
                    case 2:Pop(P3);break;
                    case 3:Pop(P4);break;
                    case 4:Pop(P5);break;
                    case 5:Pop(P6);break;
                    case 6:Pop(P7);break;
                    case 7:Pop(P8);break;
                    case 8:Pop(P9);break;
                    
                }
            }
            printf("\nModo: %s\n", (sorteio==0 ? "Push" : "Pop"));
            if(sorteio==0)
            	printf("Caractere aleatorio: %c\n", alp[num]);
            printf("Pilha: %d\n", pilha+1);
            printf("\n");
	    	printf("P1: ");Exibir(P1);
	    	printf("P2: ");Exibir(P2);
	    	printf("P3: ");Exibir(P3);
	    	printf("P4: ");Exibir(P4);
	    	printf("P5: ");Exibir(P5);
	    	printf("P6: ");Exibir(P6);
	    	printf("P7: ");Exibir(P7);
	    	printf("P8: ");Exibir(P8);
	    	printf("P9: ");Exibir(P9);
        }
    }while(op!='N');
}
void Inversa(){
    TpPilha P, P1;
    char op;
    do{
        Inicializar(P);
        Inicializar(P1);
        printf("\nVetor: ");
        for(int i=0;i<10;i++){
            scanf(" %c", &P.PILHA[i]);
            P.TOPO=i;
        }
        Exibir(P);
        op = toupper(getch());
    }while(op!='N');
}
void ArquivoTexto(){
    FILE *ptr = fopen("ArquivoTexto.txt", "r");
    FILE *ptrN = fopen("temp.txt", "w");
    TpPilhaS P;
    char aux[30];
    Inicializar(P);
    fscanf(ptr, "%[^\n]\n", aux);
    while(!feof(ptr)){
        PushSS(P, aux);
        fscanf(ptr, "%[^\n]\n", aux);
    }
    PushSS(P, aux);
    while(!Vazia(P.TOPO)){
    	PopSS(P, aux);
        fprintf(ptrN, "%s\n", aux);
    }
    fclose(ptr);
    fclose(ptrN);
}
void Palindromo(){
    TpPilha P1, P2;
    char op, aux[30];
    do{
        printf("\nString: ");
        fflush(stdin);
        gets(aux);
        int tl = strlen(aux);
        for(int i=0;i<tl/2;i++){
            Push(P1, aux[i]);
            Push(P2, aux[tl-i-1]);
        }
        int qtd=0;
        while(!Vazia(P1.TOPO)){
            if(P1.PILHA[P1.TOPO]==P2.PILHA[P2.TOPO])qtd++;
        }
        if(qtd<tl/2)
            printf("%s nao eh palindromo\n", aux);
        else
            printf("%s eh palindromo\n", aux);
        printf("Deseja continuar? <s/n>\n");
        op=toupper(getch());
    }while(op!='N');
}
void FraseInversa(){
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
int main(void)
{
	//LIFO ... "Last In, First Out"
	TpPilha Pilha, Pilha2;
	char op;
	do
	{
		op = Menu();
		switch (op)
		{
			case 'A':	Inicializar(Pilha);
						printf("\nPilha Inicializada!\n");
						break;
						
			case 'B':	if (!Cheia(Pilha.TOPO))
						{
							Push(Pilha,LeElemento());
							printf("\nElemento Empilhado!\n");
						}
						else printf("\nPilha Cheia!\n");
						break;
			
			case 'C':	if (!Vazia(Pilha.TOPO))
							printf("\nElemento Desempilhado: %c\n",Pop(Pilha));
						else
							printf("\nPilha Vazia!\n");
						break;
			
			case 'D':	if (!Vazia(Pilha.TOPO))
							printf("\nElemento do TOPO: %c\n",elementoTopo(Pilha));
						else
							printf("\nPilha Vazia!\n");		
						break;
			
			case 'E':	printf("\nConteudo da Pilha:\n");
						if (!Vazia(Pilha.TOPO))
							Exibir(Pilha);
						else
							printf("\nPilha Vazia!\n");	
						break;
			
			case 'F':	printf("\nConcatenacao da Pilha:\n");
						printf("\nPILHA 1:\n");
						InserirElementos(Pilha);
						printf("\nPILHA 2:\n");
						InserirElementos(Pilha2);
						Concatenacao(Pilha,Pilha2);
						printf("\nResultado da Concatenacao:\n");
						Exibir(Pilha);
						break;
			case 'G': if(!Vazia(Pilha.TOPO)){
							Exclusao(Pilha);
							printf("Exclusao concluida\n");
						}
						break;
            case 'H': PosFixada();break;
            case 'I': Sorteio();break;
            case 'J': Inversa();break;
            case 'K': ArquivoTexto();break;
            case 'L': Palindromo();break;
            case 'M': FraseInversa();break;
		}
		getch();
	}while(op!=27);
	return 0;
}









