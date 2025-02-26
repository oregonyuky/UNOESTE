#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>
#include <ctype.h>
#include "tadpilha.h"
int main{
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
