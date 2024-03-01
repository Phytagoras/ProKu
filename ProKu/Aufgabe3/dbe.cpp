// Inkludiere die Header-Dateien "dbe.hpp" und "ggT.hpp", um auf die
// entsprechenden Funktionen zuzugreifen.
#include "dbe.hpp"

#include "ggT.hpp"

// Inkludiere die Standardbibliothek "iostream" für Ein-/Ausgabeoperationen.
#include <iostream>

// Deklariere die Funktion power, die später definiert wird.
int power(int base, int power);

// Definition der Funktion dbe zur Berechnung dezimaler Brüche
void dbe(int d, int m, int p, int n) {
    // Initialisierung der Variablen zae (Zähler) und nae (Nenner) mit 1
    int zae(1), nae(1);

    // Wenn n nicht gleich 0 ist, führe folgende Berechnungen aus
    if (n != 0) {
        // Berechne den Zähler und den Nenner gemäß der gegebenen Formel
        zae = d * (power(10, n) - 1) + p;
        nae = power(10, m) * (power(10, n) - 1);

        // Berechne den größten gemeinsamen Teiler von Zähler und Nenner
        int ggt = ggT(zae, nae);

        // Kürze den Bruch, indem Zähler und Nenner durch ihren ggT geteilt
        // werden
        zae = zae / ggt;
        nae = nae / ggt;
    } else {
        // Wenn n gleich 0 ist, ist der Nenner 10^m und der Zähler d
        zae = d;
        nae = power(10, m);
        // Berechne den größten gemeinsamen Teiler von Zähler und Nenner
        int ggt = ggT(zae, nae);

        // Kürze den Bruch, indem Zähler und Nenner durch ihren ggT geteilt
        // werden
        zae = zae / ggt;
        nae = nae / ggt;
    }

    // Gib den Bruch auf der Konsole aus
    std::cout << "Der Bruch ist: " << zae << "/" << nae << std::endl;
}

// Definition der Funktion power zur Berechnung von Potenzen
int power(int base, int power) {
    // Initialisierung des Startwertes
    int value(1);

    // Schleife zur Berechnung der Potenz
    for (int i = 0; i < power; i++) {
        value *= base;
    }

    // Rückgabe des berechneten Werts
    return value;
}
