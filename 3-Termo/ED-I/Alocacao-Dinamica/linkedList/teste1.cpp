#include <stdio.h>
#include <string.h>

int main() {
    char frase[] = "maca    ,banana,laranja,uva";
    const char delimitador[] = ",";

    // Primeira chamada ao strtok
    char *token = strtok(frase, delimitador);

    // Continua pegando os próximos tokens
    while (token != NULL) {
        printf("Fruta: %s\n", token);
        token = strtok(NULL, delimitador);
    }

    return 0;
}
