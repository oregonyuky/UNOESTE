#include <stdio.h>
#include <stdlib.h>
#include "tadFila.h"
int main(){
    tpFila f;
    inicializarFila(f);
    for(int i=0;i<10;i++){
        inserirFila(f, 'A'+i);
    }
    printf("%c\n", retirarFila(f));
    printf("%d\n", vaziaFila(f));
    printf("%d\n", cheiaFila(f));
    printf("%c\n", elementoInicio(f));
    printf("%c\n", elementoFim(f));
}
