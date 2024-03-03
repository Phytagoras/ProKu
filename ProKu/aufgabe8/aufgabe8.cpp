#include "aufgabe8.hpp"

#include <cassert>
#include <iostream>
#include <limits>
#include <sstream>  // fuer std::istringstream

#include "IntList.hpp"
#include "IntListElement.hpp"

// Hilfs-Funktion:
// Fehlerbehandlung fuer std::cin
void clear_cin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Liest ein einzelnes Zeichen von der Konsole:
//
// \param[out] c
// Eine Referenz auf den char, in welchen eingelesen werden soll
//
// \returns
// true, falls ein Zeichen eingelesen wurde, sonst false
bool read_char(char& c) {
    if ((std::cin >> c).good()) return true;
    std::cout << "FEHLER: Ungueltige Eingabe" << std::endl;
    clear_cin();
    return false;
}

// Liest einen einzelnen int von der Konsole:
//
// \param[out] i
// Eine Referenz auf den int, in welchen eingelesen werden soll
//
// \returns
// true, falls eine Zahl eingelesen wurde, sonst false
bool read_int(int& i) {
    if ((std::cin >> i).good()) return true;
    std::cout << "FEHLER: Ungueltige Eingabe" << std::endl;
    clear_cin();
    return false;
}

// Konvertiert eine Zeichenkette in einen int (falls moeglich)
//
// \param[in] str
// Die Zeichenkette, die konvertiert werden soll
//
// \param[out] i
// Eine Referenz auf den int, in welchen eingelesen werden soll
//
// \returns
// true, falls die Zeichenkette konvertiert wurde, sonst false
bool parse_int(const char* str, int& i) {
    assert(str != nullptr);
    std::istringstream iss(str);
    return !(iss >> i).fail();
}

int main() {
    // Erstelle ein Objekt vom Typ IntList:
    IntList list;

    // >>>>>>>>>> TESTWEISE >>>>>>>>>>
    // Wichtig:
    // Loeschen Sie diesen Test-Code, wenn Sie bei Teilaufgabe d) ankommen!
    // Erstelle 5 Elemente auf dem Stack und verkette sie von Hand:
    IntListElement elem_0(7, nullptr);
    IntListElement elem_1(5, &elem_0);
    IntListElement elem_2(5, &elem_1);
    IntListElement elem_3(3, &elem_2);
    IntListElement elem_4(2, &elem_3);
    // Haenge die Elemente in die Liste ein:
    list.head = &elem_4;
    // <<<<<<<<<< TESTWEISE <<<<<<<<<<

    // Endlos-Eingabe-Schleife:
    bool quit(false);
    while (!quit) {
        // Eine char-Variable fuer das erste Zeichen der Eingabe:
        char command(0);

        // Eingabe-Aufforderung:
        std::cout << "> ";

        // Lese den Befehl ein:
        if (!read_char(command)) continue;

        // Welcher Befehl ist das?
        switch (command) {
            case 'Q':
            case 'q':
                // Beende Schleife
                quit = true;
                break;

            case 'P':
            case 'p':
                // Liste ausgeben
                list.print();
                break;

            case 'T':
            case 't':
                // Liste testen
                list.test();
                break;

            // TODO: weitere Befehle einfuegen
            case 's':
            case 'S':
                std::cout << list.size() << std::endl;
                break;

            default:
                std::cout << "FEHLER: unbekannter Befehl '" << command << "'"
                          << std::endl;
                break;
        }
    }

    // Ende
    return 0;
}