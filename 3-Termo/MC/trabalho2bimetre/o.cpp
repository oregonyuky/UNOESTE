#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Função f(x) = 1/x²
double f(double x) {
    return 1.0 / (x * x);
}

// Truncar para 3 casas decimais
double trunc3(double x) {
    return floor(x * 1000) / 1000.0;
}

int main() {
    double a = 1.0, b = 2.0;
    int n = 10;
    double h = (b - a) / n;
    double somaEsq = 0, somaDir = 0, somaMeio = 0, somaTrap = 0;
    double somaImp = 0, somaPar = 0;

    // Retângulo (esquerda e direita), ponto médio, trapézio, Simpson
    for (int i = 0; i < n; i++) {
        double xi = a + i * h;
        double xi1 = xi + h;
        double meio = xi + h / 2;

        double fxi = trunc3(f(xi));
        double fxi1 = trunc3(f(xi1));
        double fmeio = trunc3(f(meio));

        somaEsq += fxi;
        somaDir += fxi1;
        somaMeio += fmeio;

        if (i > 0)
            somaTrap += fxi;
    }
    // f(a) e f(b) para trapézio
    somaTrap = (trunc3(f(a)) + 2 * somaTrap + trunc3(f(b))) * h / 2.0;
    somaTrap = trunc3(somaTrap);

    // Retângulos
    double retEsq = trunc3(h * somaEsq);
    double retDir = trunc3(h * somaDir);

    // Ponto Médio
    double pontoMedio = trunc3(h * somaMeio);

    // Simpson (composto)
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        double fxi = trunc3(f(xi));
        if (i % 2 == 0)
            somaPar += fxi;
        else
            somaImp += fxi;
    }
    double simpson = trunc3((h / 3.0) * (trunc3(f(a)) + 4 * somaImp + 2 * somaPar + trunc3(f(b))));

    // Solução analítica
    double exata = trunc3(-1.0 / b + 1.0 / a);

    // Resultados
    cout << fixed << setprecision(3);
    cout << "Integral de f(x) = 1/x^2 no intervalo [1,2] com n = 10\n\n";
    cout << "Solução exata: " << exata << endl;
    cout << "Retângulos (esquerda): " << retEsq << " | Erro: " << trunc3(fabs(retEsq - exata)) << endl;
    cout << "Retângulos (direita):  " << retDir << " | Erro: " << trunc3(fabs(retDir - exata)) << endl;
    cout << "Ponto Médio:           " << pontoMedio << " | Erro: " << trunc3(fabs(pontoMedio - exata)) << endl;
    cout << "Trapézio:              " << somaTrap << " | Erro: " << trunc3(fabs(somaTrap - exata)) << endl;
    cout << "Simpson:               " << simpson << " | Erro: " << trunc3(fabs(simpson - exata)) << endl;

    return 0;
}
