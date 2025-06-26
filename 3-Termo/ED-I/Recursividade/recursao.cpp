#include <iostream>
using namespace std;
// 1. Recursão Linear
int linear(int n) {
    if (n == 0) return 0;
    return linear(n - 1) + 1;
}
// 2. Recursão Binária
int binaria(int n) {
    if (n <= 1) return 1;
    return binaria(n - 1) + binaria(n - 2);
}
// 3. Recursão Múltipla
int multipla(int n) {
    if (n <= 0) return 1;
    cout << n << endl;
    return multipla(n - 1);
    cout << n << endl;
    return multipla(n - 2);
    cout << n << endl;
    //multipla(n - 3);
}
// 4. Recursão Aninhada
int aninhada(int x) {
    if (x <= 6) {
        cout << x << endl;
        return x + 2;
    }
    cout << x << endl;
    int inner = aninhada(x / 3);
    return aninhada(inner + 1);
}
// 5. Recursão Direta
void direta(int n) {
    if (n == 0) return;
    cout << "direta(" << n << ")\n";
    direta(n - 1);
}

// 6. Recursão Indireta
void B(int n); // protótipo
void A(int n) {
    if (n <= 0) return;
    cout << "A(" << n << ")\n";
    B(n - 1);
}
void B(int n) {
    if (n <= 0) return;
    cout << "B(" << n << ")\n";
    A(n - 1);
}

// 7. Recursão de Cauda
void cauda(int n) {
    if (n == 0) return;
    cout << "cauda(" << n << ")\n";
    cauda(n - 1); // última instrução
}

// 8. Recursão de Cabeça
void cabeca(int n) {
    if (n == 0) return;
    cabeca(n - 1); // chamada primeiro
    cout << "cabeca: " << n << endl;
}

int main() {
    cout << "1. Linear: " << linear(5) << "\n\n";

    cout << "2. Binária: " << binaria(5) << "\n\n";

    cout << "3. Múltipla:\n";
    cout << multipla(3) << endl;
    cout << "\n";

    cout << "4. Aninhada:\n";
    cout << "Resultado: " << aninhada(21) << "\n\n";

    cout << "5. Direta:\n";
    direta(3);
    cout << "\n";

    cout << "6. Indireta:\n";
    A(3);
    cout << "\n";

    cout << "7. Cauda:\n";
    cauda(3);
    cout << "\n";

    cout << "8. Cabeça:\n";
    cabeca(3);
    cout << "\n";

    return 0;
}
