#include <stdio.h>

// 1. Recursividade Linear
void linear(int n) {
    if (n == 0) return;
    printf("%d ", n);
    linear(n - 1);
}
/*
Saída para linear(3):
3 2 1
*/

// 2. Recursividade Dupla
void dupla(int n) {
    if (n == 0) return;
    printf("(%d", n);
    dupla(n - 1);
    dupla(n - 1);
    printf(")");
}
/*
Saída para dupla(2):
(2(1(0)(0))(1(0)(0)))
*/

// 3. Recursividade Múltipla (como Fibonacci)
int multipla(int n) {
    if (n <= 1) return n;
    return multipla(n - 1) + multipla(n - 2);
}
/*
multipla(5) → Fibonacci(5) = 5
Chamada:
multipla(5)
 ↳ multipla(4) + multipla(3)
  ↳ ...
Saída final: 5
*/

// 4. Recursividade Indireta
void b(int); // declaração antecipada
void a(int n) {
    if (n <= 0) return;
    printf("A%d ", n);
    b(n - 1);
}
void b(int n) {
    if (n <= 0) return;
    printf("B%d ", n);
    a(n / 2);
}
/*
Chamada: a(4)
Saída:
A4 B3 A1 B0
*/

// 5. Recursividade Aninhada
int aninhada(int n) {
    if (n <= 1) return n;
    return aninhada(aninhada(n - 1));
}
/*
Chamada: aninhada(3)
Processo:
aninhada(aninhada(2))
 → aninhada(aninhada(1)) = aninhada(1) = 1
Saída final: 1
*/

// 6. Recursividade de Cauda (Tail Recursion)
void tail(int n, int acc) {
    if (n == 0) {
        printf("Resultado acumulado: %d\n", acc);
        return;
    }
    tail(n - 1, acc + n);
}
/*
Chamada: tail(5, 0)
Processo: tail(4,5) → tail(3,9) → ... → tail(0,15)
Saída: Resultado acumulado: 15
*/

int main() {
    printf("1. Linear:\n");
    linear(3);
    printf("\n\n");

    printf("2. Dupla:\n");
    dupla(2);
    printf("\n\n");

    printf("3. Múltipla (Fibonacci):\n");
    printf("Resultado: %d\n\n", multipla(5)); // 5

    printf("4. Indireta:\n");
    a(4);
    printf("\n\n");

    printf("5. Aninhada:\n");
    printf("Resultado: %d\n\n", aninhada(3)); // 1

    printf("6. Cauda (Tail Recursion):\n");
    tail(5, 0); // soma 5 + 4 + 3 + 2 + 1 = 15

    return 0;
}
