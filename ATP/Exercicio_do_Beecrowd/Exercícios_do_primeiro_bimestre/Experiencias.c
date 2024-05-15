#include <stdio.h>
#include <string.h>

int main() {
    int quantidade;
    scanf("%d", &quantidade);

    int array[quantidade];
    char string[quantidade];

    for (int i = 0; i < quantidade; i++) {
        scanf("%d %c", &array[i], &string[i]);
    }

    int soma = 0;
    int frequency = 0, frequency1 = 0, frequency2 = 0;

    for (int i = 0; i < quantidade; i++) {
        soma += array[i];
        if (string[i] == 'C') {
            frequency += array[i];
        } else if (string[i] == 'R') {
            frequency1 += array[i];
        } else if (string[i] == 'S') {
            frequency2 += array[i];
        }
    }

    float result = (float)frequency / soma;
    float result1 = (float)frequency1 / soma;
    float result2 = (float)frequency2 / soma;

    printf("Total: %d cobaias\n", soma);
    printf("Total de coelhos: %d\n", frequency);
    printf("Total de ratos: %d\n", frequency1);
    printf("Total de sapos: %d\n", frequency2);
    printf("Percentual de coelhos: %.2f %%\n", result * 100);
    printf("Percentual de ratos: %.2f %%\n", result1 * 100);
    printf("Percentual de sapos: %.2f %%\n", result2 * 100);

    return 0;
}
