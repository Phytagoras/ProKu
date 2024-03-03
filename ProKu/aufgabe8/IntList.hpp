#pragma once
#include "IntListElement.hpp"
// Die Klasse, welche eine sortierte Liste von ints repraesentiert:
class IntList {
   public:
    // Ein Zeiger auf das erste Listen-Element
    IntListElement* head;

   public:
    // Standard-Konstruktor:
    // Erstellt eine leere Liste
    IntList();

    // Druckt die Liste auf die Konsole
    void print() const;

    // Testet die Elemente der Liste
    bool test() const;

    int size() const;
    
    int find(int toFind) const;
    void insert(int newValue);

};  // class IntList