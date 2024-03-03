
#include "IntList.hpp"

#include <cassert>
#include <iostream>
#include <limits>
#include <sstream>  // fuer std::istringstream

#include "IntListElement.hpp"
#include "aufgabe8.hpp"

// Standard-Konstruktor:
// Erstellt eine leere Liste
IntList::IntList() : head(nullptr) {}

// Druckt die Liste auf die Konsole
void IntList::print() const {
    // Start der Ausgabe:
    std::cout << "[";

    // Laufe ueber alle Elemente der Liste:
    // Wir starten dazu mit dem Element, auf das "head" zeigt,
    // und iterieren mit dem Zeiger "ptr" ueber alle Elemente
    // der Liste, indem wir "ptr" auf "ptr->next" setzen:
    const IntListElement* ptr(head);
    while (ptr != nullptr) {
        // Drucke das Datum des aktuellen Elementes:
        std::cout << " " << ptr->value;

        // Und gehe zum naechsten Element ueber:
        ptr = ptr->next;
    }

    // Ende der Ausgabe:
    std::cout << "]" << std::endl;
}

// Testet die Elemente der Liste
bool IntList::test() const {
    // Lese den Rest der Zeile von der Konsole ein
    std::string values;
    std::getline(std::cin, values);

    // Laufe ueber die Liste:
    std::size_t so = 0u, sn = 0u;
    const IntListElement* ptr(head);
    for (int pos = 1; true; ++pos) {
        // Finde naechtes Datum in Eingabe
        so = values.find_first_not_of(' ', sn);

        // Kein naechstes Datum erwartet?
        if (so == values.npos) {
            // Weitere Elemente in der Liste vorhanden?
            if (ptr != nullptr) {
                std::cout << "TEST FEHLGESCHLAGEN!" << std::endl;
                std::cout << "Position: " << pos << std::endl;
                std::cout << "Erwartet: Ende der Liste" << std::endl;
                std::cout << "Gefunden: " << ptr->value << std::endl;
                return false;
            }

            // Okay, erwartetes Listen-Ende gefunden
            break;
        }

        // Finde naechstes Leerzeichen nach Datum
        sn = values.find_first_of(' ', so);
        if (sn == values.npos) sn = values.size();

        // Extrahiere naechstes Datum in einen int
        std::string sval = values.substr(so, sn - so);
        int value(0);
        if (!parse_int(sval.c_str(), value)) {
            std::cout << "FEHLER: Konnte '" << sval
                      << "' nicht als Ganzzahl einlesen!" << std::endl;
            return false;
        }

        // Keine weiteren Elemente vorhanden?
        if (ptr == nullptr) {
            std::cout << "TEST FEHLGESCHLAGEN!" << std::endl;
            std::cout << "Position: " << pos << std::endl;
            std::cout << "Erwartet: " << value << std::endl;
            std::cout << "Gefunden: Ende der Liste" << std::endl;
            return false;
        }

        // Vergleiche Daten
        if (value != ptr->value) {
            std::cout << "TEST FEHLGESCHLAGEN!" << std::endl;
            std::cout << "Position: " << pos << std::endl;
            std::cout << "Erwartet: " << value << std::endl;
            std::cout << "Gefunden: " << ptr->value << std::endl;
            return false;
        }

        // Gehe zum naechsten Element ueber
        ptr = ptr->next;
    }

    // Okay, Test erfolgreich
    std::cout << "TEST OK" << std::endl;
    return true;
}
int IntList::size() const {
    const IntListElement* ptr(head);
    int counter = 0;
    while (ptr != nullptr) {
        counter++;

        // Und gehe zum naechsten Element ueber:
        ptr = ptr->next;
    }
    return counter;
}

int IntList::find(int toFind) const {
    const IntListElement* ptr(head);
    int counter = 0;
    while (ptr != nullptr) {
        if (ptr->value == toFind) {
            counter++;
        }
        // Und gehe zum naechsten Element ueber:
        ptr = ptr->next;
    }
    return counter;
}