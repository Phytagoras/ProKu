// Inkludiere die Header-Datei "ggT.hpp", um auf die ggT-Funktion zuzugreifen.
#include "ggT.hpp"

// Funktion zur Berechnung des kleinsten gemeinsamen Vielfachen (kgV) von zwei
// ganzen Zahlen.
int kgV(int a, int b) {
    // Wenn a und b gleichzeitig 0 sind, ist das kgV ebenfalls 0, also gebe 0
    // zurück.
    if (a == 0 && b == 0) return 0;
    // Berechne das Produkt von a und b und speichere es in ab.
    int ab = (a * b > 0) ? a * b : -a * b;
    // Berechne das kgV durch Division des Produkts von a und b durch den ggT
    // von a und b.
    return ab / ggT(a, b);
}
