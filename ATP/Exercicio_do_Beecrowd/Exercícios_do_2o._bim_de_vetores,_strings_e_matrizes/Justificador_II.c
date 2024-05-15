#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 5

int main() {
    int array[15], par[max], impar[max];
    int conta_par = 0, conta_impar = 0;
    int i, j;

    for (i = 0; i < 15; i++) {
        scanf("%d", &array[i]);
        
        if (array[i] % 2 == 0) {
            par[conta_par] = array[i];
            conta_par++;
            
            // Se o vetor par estiver cheio, imprime e reinicia
            if (conta_par == max) {
                for (j = 0; j < max; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                conta_par = 0;
            }
        } else {
            impar[conta_impar] = array[i];
            conta_impar++;
            
            // Se o vetor impar estiver cheio, imprime e reinicia
            if (conta_impar == max) {
                for (j = 0; j < max; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                conta_impar = 0;
            }
        }
    }

    // Imprime o restante dos valores nos vetores
    for (i = 0; i < conta_impar; i++) {
        printf("impar[%d] = %d\n", i, impar[i]);
    }

    for (i = 0; i < conta_par; i++) {
        printf("par[%d] = %d\n", i, par[i]);
    }

    return 0;
}
