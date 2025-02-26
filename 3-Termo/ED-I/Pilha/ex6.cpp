#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "tadpilha.h"
int main(){
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
