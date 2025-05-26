#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

// Truncamento para 4 casas decimais nos cálculos
double trunc4(double x) {
    return floor(x * 10000) / 10000.0;
}

// Truncamento para 3 casas decimais nos resultados finais
double trunc3(double x) {
    return floor(x * 1000) / 1000.0;
}

int main() {
    // Dados da tabela
    vector<double> x = {-1, -0.75, -0.6, -0.5, -0.3, 0, 0.2, 0.4, 0.5, 0.7, 1};
    vector<double> y = {2.05, 1.15, 0.45, 0.4, 0.5, 0, 0.2, 0.6, 0.51, 1.2, 2.05};
    int n = x.size();

    // Somatórios
    double Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    double Sy = 0, Sxy = 0, Sx2y = 0;

    for (int i = 0; i < n; i++) {
        double xi = x[i], yi = y[i];
        double xi2 = trunc4(xi * xi);
        double xi3 = trunc4(xi2 * xi);
        double xi4 = trunc4(xi2 * xi2);

        Sx += trunc4(xi);
        Sx2 += xi2;
        Sx3 += xi3;
        Sx4 += xi4;
        Sy += trunc4(yi);
        Sxy += trunc4(xi * yi);
        Sx2y += trunc4(xi2 * yi);
    }

    // Sistema normal para ajuste quadrático: A * a = B
    double A[3][3] = {
        {static_cast<double>(n), Sx, Sx2},
        {Sx, Sx2, Sx3},
        {Sx2, Sx3, Sx4}
    };
    double B[3] = {Sy, Sxy, Sx2y};

    // Resolver sistema linear (método de Cramer)
    auto det3x3 = [](double M[3][3]) {
        return trunc4(
            M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[0][2]*M[1][0]*M[2][1]
            - M[0][2]*M[1][1]*M[2][0] - M[0][0]*M[1][2]*M[2][1] - M[0][1]*M[1][0]*M[2][2]
        );
    };

    double D = det3x3(A);

    // Matrizes para Cramer
    double A1[3][3], A2[3][3], A3[3][3];
    for (int i = 0; i < 3; i++) {
        A1[i][0] = B[i]; A1[i][1] = A[i][1]; A1[i][2] = A[i][2];
        A2[i][0] = A[i][0]; A2[i][1] = B[i]; A2[i][2] = A[i][2];
        A3[i][0] = A[i][0]; A3[i][1] = A[i][1]; A3[i][2] = B[i];
    }

    double Da = det3x3(A1);
    double Db = det3x3(A2);
    double Dc = det3x3(A3);

    double a = trunc3(Da / D);
    double b = trunc3(Db / D);
    double c = trunc3(Dc / D);

    cout << fixed << setprecision(3);
    cout << "Ajuste quadrático da forma y = ax^2 + bx + c\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Equação ajustada: y = " << a << "x^2 + " << b << "x + " << c << endl;

    return 0;
}
