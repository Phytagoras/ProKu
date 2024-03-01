#include <iostream>
#include <iomanip>
#include <cmath>

// Funktion zur Berechnung der Bailey-Formel für die Approximation von Pi
double baileyFormel();

// Hilfsfunktion zur Berechnung von Potenzen
double power(double base, int power);

int main()
{
    // Berechnung der Näherung von Pi mit der Bailey-Formel
    double approx = baileyFormel();

    // Ausgabe der Näherung mit 15 Dezimalstellen Genauigkeit
    std::cout << std::fixed << std::setprecision(15) << approx << std::endl;

    // Ausgabe des Fehlers zwischen der Näherung und dem tatsächlichen Pi
    std::cout << "Fehler: " << approx - M_PI << std::endl;

    return 0;
}

// Funktion zur Berechnung der Bailey-Formel für Pi
double baileyFormel()
{
    // Variablen für die aktuelle und vorherige Iteration sowie die Iterationszahl
    double currIteration(0), prevIteration(-1);
    int iteration(0);

    // Schleife zur Annäherung von Pi, bis die vorherige und aktuelle Iteration gleich sind
    while (currIteration != prevIteration)
    {
        // Aktualisierung der vorherigen Iteration
        prevIteration = currIteration;

        // Berechnung der aktuellen Iteration nach der Bailey-Formel
        currIteration = currIteration + (1.0 / power(16.0, iteration)) * ((4.0 / (8.0 * iteration + 1.0)) - (2.0 / (8.0 * iteration + 4.0)) - (1.0 / (8.0 * iteration + 5.0)) - (1.0 / (8.0 * iteration + 6.0)));

        // Inkrement der Iterationszahl
        iteration++;
    }

    // Rückgabe der endgültigen Näherung von Pi
    return currIteration;
}

// Funktion zur Berechnung von Potenzen
double power(double base, int power)
{
    // Initialisierung des Startwertes
    double value(1);

    // Schleife zur Berechnung der Potenz
    for (int i = 0; i < power; i++)
    {
        value *= base;
    }

    // Rückgabe des berechneten Werts
    return value;
}
