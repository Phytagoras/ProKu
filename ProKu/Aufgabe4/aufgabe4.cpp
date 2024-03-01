#include <cmath>
#include <iostream>

// Berechnet die euklidische Norm eines Vektors x der Länge n.
double norm(double x[], int n);

// Führt die Operation y = alpha * x + y aus.
void axpy(double x[], double y[], int n, double alpha);

int main(int argc, char const *argv[]) {
    constexpr int n = 31;
    double pi = M_PI;  // Pi-Konstante aus der cmath-Bibliothek
    double lambda = 2. * (1. - cos(pi / (n + 1)));  // Berechnung von lambda
    double x[n], u[n], b[n], d[n];                  // Definition von Vektoren

    // Initialisierung der Vektoren u und b
    for (int i = 0; i < n; i++) {
        x[i] = 0;  // x-Vektor wird mit Nullen initialisiert
        b[i] = 0;  // b-Vektor wird mit Nullen initialisiert
        u[i] = sin(pi * (double(i + 1.) /
                         double(n + 1.)));  // Berechnung der Werte für u
    }

    // Ausgabe der Norm von u
    std::cout << "Norm(u) = " << norm(u, n) << std::endl;

    // Operation axpy: b = lambda * u + b
    axpy(u, b, n, lambda);

    // Ausgabe der Norm von b nach axpy-Operation
    std::cout << "Norm(b) = " << norm(b, n) << std::endl;

    // Iterative Berechnung
    for (int i = 0; i < 10000; i++) {
        // Berechnung des Vektors d
        d[0] = b[0] - 2. * x[0] + x[1];
        for (int j = 1; j < n - 1; j++) {
            d[j] = b[j] - (2. * x[j]) + x[j - 1] + x[j + 1];
        }
        d[n - 1] = b[n - 1] - (2. * x[n - 1]) + x[n - 2];

        // Überprüfung auf Konvergenz
        if (norm(d, n) <= norm(b, n) * 0.00001) {
            std::cout << "ABBRUCH: Iteration: " << i
                      << " - Norm(d) = " << norm(d, n) << std::endl;
            break;
        }

        // Iterationsschritt: x = 0.5 * d + x
        axpy(d, x, n, 0.5);

        // Ausgabe der Norm von d in regelmäßigen Abständen
        if (i % 100 == 0) {
            std::cout << "Iteration: " << i << " - Norm(d) = " << norm(d, n)
                      << std::endl;
        }
    }

    // Berechnung des Fehlers und Ausgabe
    axpy(u, x, n, -1.);
    std::cout << "FEHLER:  - Norm(x - u) = " << norm(x, n) << std::endl;
    return 0;
}

// Implementierung der Normberechnung
double norm(double x[], int n) {
    double sum(0);
    for (int i = 0; i < n; i++) {
        sum += x[i] * x[i];
    }
    return sqrt(sum);
}

// Implementierung der axpy-Operation
void axpy(double x[], double y[], int n, double alpha) {
    for (int i = 0; i < n; i++) {
        y[i] = alpha * x[i] + y[i];
    }
}
