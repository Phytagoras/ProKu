
// Funktion zur Berechnung des größten gemeinsamen Teilers (ggT) von zwei ganzen
// Zahlen.
int ggT(int a, int b) {
    // Solange b nicht gleich 0 ist, führe die Schleife aus.
    while (b != 0) {
        // Temporäre Variable temp wird mit dem Wert von b initialisiert.
        int temp = b;
        // b wird aktualisiert auf den Rest der Division von a durch b.
        b = a % b;
        // a wird aktualisiert auf den vorherigen Wert von b.
        a = temp;
    }
    // Rückgabe des ggT, wobei der Betrag von a zurückgegeben wird.
    return (a > 0) ? a : -a;
}
