#pragma once
// Die Klasse, welche ein einzelnes Element der Liste repraesentiert:
class IntListElement {
   public:
    // Das zu speichernde Datum
    int value;

    // Der Zeiger auf das naechste Element (oder auf nullptr)
    IntListElement* next;

    // Konstruktor:
    explicit IntListElement(int _value, IntListElement* _next = nullptr);
};  // class IntListElement
