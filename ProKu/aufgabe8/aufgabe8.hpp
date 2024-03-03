#pragma once

#include <cassert>
#include <iostream>
#include <limits>
#include <sstream>  // fuer std::istringstream

#include "IntList.hpp"
#include "IntListElement.hpp"

// Hilfs-Funktion:
// Fehlerbehandlung fuer std::cin
void clear_cin();

// Liest ein einzelnes Zeichen von der Konsole:
//
// \param[out] c
// Eine Referenz auf den char, in welchen eingelesen werden soll
//
// \returns
// true, falls ein Zeichen eingelesen wurde, sonst false
bool read_char(char& c);

// Liest einen einzelnen int von der Konsole:
//
// \param[out] i
// Eine Referenz auf den int, in welchen eingelesen werden soll
//
// \returns
// true, falls eine Zahl eingelesen wurde, sonst false
bool read_int(int& i);

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
bool parse_int(const char* str, int& i);

int main();