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

int main(int argc, char const* argv[]) {
    // Erstelle ein Objekt vom Typ IntList:
    IntList list;
    for (int i = 1; i < argc; i++) {
        int tmp;

        assert(parse_int(argv[i], tmp));
        list.insert(tmp);
    }
    list.print();

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
        int elmnt;
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
                {
                    using namespace std;
                    case 's':
                    case 'S':
                        cout << list.size() << endl;
                        break;

                    case 'f':
                    case 'F':
                        elmnt = -1;
                        if (read_int(elmnt)) {
                            int count = list.find(elmnt);
                            if (count == 0) {
                                cout << "Das Element " << elmnt
                                     << " ist nicht in der Liste!" << endl;
                            } else {
                                cout << "Das Element " << elmnt << " ist "
                                     << count << " mal in der Liste!" << endl;
                            }

                        } else {
                            cout << "Fehler - Zu suchendes Element fehlt!"
                                 << endl;
                        }
                        break;
                    case 'i':
                    case 'I':
                        elmnt = -1;
                        if (read_int(elmnt)) {
                            list.insert(elmnt);
                            list.print();
                        } else {
                            cout << "Fehler - Einzufuegendes Element fehlt!"
                                 << endl;
                        }
                        break;

                    case 'e':
                    case 'E':
                        elmnt = -1;
                        if (read_int(elmnt)) {
                            int count = list.find(elmnt);
                            if (count == 0) {
                                cout << "Das Element " << elmnt
                                     << " ist nicht in der Liste!" << endl;
                            } else {
                                cout << "Das Element " << elmnt << " wurde "
                                     << count << " mal geloescht!" << endl;
                            }
                            list.erase(elmnt);

                        } else {
                            cout << "Fehler - Zu loeschendes Element fehlt!"
                                 << endl;
                        }
                        break;
                }
            default:
                std::cout << "FEHLER: unbekannter Befehl '" << command << "'"
                          << std::endl;
                break;
        }
    }

    // Ende
    return 0;
}