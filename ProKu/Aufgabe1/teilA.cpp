#include <iostream> // Bibliothek für Ein-/Ausgabeoperationen

// Funktionsdeklarationen für berechneSumme1 und berechneSumme2
double berechneSumme1();
double berechneSumme2();

int main() {
    // Berechnet die Summe mit der Funktion berechneSumme1 und speichert das Ergebnis in summeX
    double summeX = berechneSumme1();

    // Berechnet die Summe erneut mit der Funktion berechneSumme1 und speichert das Ergebnis in summeY
    double summeY = berechneSumme2();

    // Ausgabe der berechneten Summe X mit einer Beschreibung
    std::cout << "Die Summe x ist: " << summeX << std::endl;

    // Ausgabe der berechneten Summe Y mit einer Beschreibung
    std::cout << "Die Summe y ist: " << summeY << std::endl;

    // Berechnet und gibt 1 minus Summe X aus
    std::cout << "1 - x: " << 1.0 - summeX << std::endl;

    // Berechnet und gibt 1 minus Summe Y aus
    std::cout << "1 - y: " << 1.0 - summeY << std::endl;

    // Vergleicht summeX und summeY und gibt das Ergebnis (wahr oder falsch) aus
    std::cout << "x == y: " << ((summeX == summeY) ? "wahr" : "falsch") << std::endl;

    return 0; // Zeigt erfolgreiches Beenden des Programms an
}

// Funktion zur Berechnung der Summe von 8 Termen, jeder mit dem Wert 1.0 / 8.0
double berechneSumme1() {
    double summe = 0.0; // Initialisierung einer Variablen zur Speicherung der Summe
    for (int i = 0; i < 8; i++) {
        summe += 1.0 / 8.0; // Addiert 1.0 / 8.0 zur Summe in jeder Iteration
    }
    return summe; // Rückgabe der finalen berechneten Summe
}

// Funktion zur Berechnung der Summe von 10 Termen, jeder mit dem Wert 1.0 / 10.0
double berechneSumme2() {
    double summe = 0.0; // Initialisierung einer Variablen zur Speicherung der Summe
    for (int i = 0; i < 10; i++) {
        summe += 1.0 / 10.0; // Addiert 1.0 / 10.0 zur Summe in jeder Iteration
    }
    
        std::cout << summe << 1.0 - summe << std::endl;
    return summe; // Rückgabe der finalen berechneten Summe
}
