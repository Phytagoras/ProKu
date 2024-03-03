#include <cassert>  // assert
#include <iostream>

#include "Rational.hpp"

void lyness(Rational a, Rational x0, Rational x1);

std::ostream& operator<<(std::ostream& os, const Rational& number) {
    if (number.is_integer()) {
        os << number.numerator();
    } else {
        os << number.numerator() << "/" << number.denominator();
    }
    return os;
}
// ############################################################################
// ############################################################################
// ############################################################################

// Konstruktor-Test
//*
bool check_ctor(int p_in, uint q_in, int p_ref, uint q_ref) {
    // Erstelle r := p/q
    Rational r(p_in, q_in);

    // Vergleiche 'r' mit Referenz-Werten
    if (r.equals(p_ref, q_ref)) {
        // Okay, 'a' stimmt mit den vorgegebenen Referenz-Werten
        // ueberein, wir geben also 'true' zurueck
        return true;  // okay
    }

    // Fehlschlag
    std::cout << "FEHLER" << std::endl;
    std::cout << "!!! Eingabe.: " << p_in << "/" << q_in << std::endl;
    std::cout << "!!! Erwartet: " << p_ref << "/" << q_ref << std::endl;
    std::cout << "!!! Erhalten: " << r.numerator() << "/" << r.denominator()
              << std::endl;
    return false;
}

bool test_ctor() {
    std::cout << "Teste Konstruktor: ";

    // Durchlaufe Tests
    bool okay = true;
    okay = okay && check_ctor(2, 1u, 2, 1u);    // 2/1
    okay = okay && check_ctor(1, 3u, 1, 3u);    // 1/3
    okay = okay && check_ctor(0, 7u, 0, 1u);    // 0/7 -> 0/1
    okay = okay && check_ctor(-6, 9u, -2, 3u);  // -6/9 -> -2/3
    okay = okay && check_ctor(6, 2u, 3, 1u);    // 6/2 -> 3/1

    // Waren alle Tests erfolgreich?
    if (okay) std::cout << "OK" << std::endl;
    return okay;
}
//*/

// ############################################################################
// ############################################################################
// ############################################################################

// Operator Tests
//*
bool check_plus(const Rational& a, const Rational& b, int p_ref, uint q_ref) {
    // Berechne r := (a + b)
    Rational r = a + b;

    // Vergleiche 'r' mit gegebenen Referenz-Werten
    if (r.equals(p_ref, q_ref)) {
        // Okay, 'r' stimmt mit den vorgegebenen Referenz-Werten
        // ueberein, wir geben also 'true' zurueck
        return true;  // okay
    }

    // Fehlschlag
    std::cout << "FEHLER" << std::endl;
    std::cout << "!!! Eingabe.:     a = " << a << std::endl;
    std::cout << "!!! Eingabe.:     b = " << b << std::endl;
    std::cout << "!!! Erwartet: a + b = " << p_ref << "/" << q_ref << std::endl;
    std::cout << "!!! Erhalten: a + b = " << r.numerator() << "/"
              << r.denominator() << std::endl;
    return false;
}

bool test_plus_op() {
    // Erstelle ein paar Zahlen zum Testen
    Rational a(3, 2);
    Rational b(10, 4);  // = 5/2
    Rational c(1, 3);
    Rational d(-5, 2);
    Rational e(0);

    // Ausgabe:
    std::cout << "Teste operator+(): ";

    // Durchlaufe Tests
    bool okay = true;
    okay = okay && check_plus(a, b, 4, 1u);    //  3/2 +  5/2 =  4
    okay = okay && check_plus(a, c, 11, 6u);   //  3/2 +  1/3 = 11/6
    okay = okay && check_plus(b, c, 17, 6u);   // 10/4 +  1/3 = 17/6
    okay = okay && check_plus(a, d, -1, 1u);   //  3/2 + -5/2 = -1
    okay = okay && check_plus(b, d, 0, 1u);    // 10/4 + -5/2 = 0
    okay = okay && check_plus(c, d, -13, 6u);  //  1/3 + -5/2 = -13/6
    okay = okay && check_plus(e, b, 5, 2u);    //    0 + 10/4 = 5/2

    // Waren alle Tests erfolgreich?
    if (okay) std::cout << "OK" << std::endl;
    return okay;
}
//*/

//*
bool check_minus(const Rational& a, const Rational& b, int p_ref, uint q_ref) {
    // Berechne r := (a - b)
    Rational r = a - b;

    // Vergleiche 'r' mit Referenz-Werten
    if (r.equals(p_ref, q_ref)) {
        // Okay, 'r' stimmt mit den vorgegebenen Referenz-Werten
        // ueberein, wir geben also 'true' zurueck
        return true;  // okay
    }

    // Fehlschlag
    std::cout << "FEHLER" << std::endl;
    std::cout << "!!! Eingabe.:     a = " << a << std::endl;
    std::cout << "!!! Eingabe.:     b = " << b << std::endl;
    std::cout << "!!! Erwartet: a - b = " << p_ref << "/" << q_ref << std::endl;
    std::cout << "!!! Erhalten: a - b = " << r.numerator() << "/"
              << r.denominator() << std::endl;
    return false;
}

bool test_minus_op() {
    // Erstelle ein paar Zahlen zum Testen
    Rational a(3, 2);
    Rational b(10, 4);  // = 5/2
    Rational c(1, 3);
    Rational d(-5, 2);
    Rational e(0);

    // Ausgabe:
    std::cout << "Teste operator-(): ";

    // Durchlaufe Tests
    bool okay = true;
    okay = okay && check_minus(a, b, -1, 1u);  //  3/2 -  5/2 = -1
    okay = okay && check_minus(a, c, 7, 6u);   //  3/2 -  1/3 = 7/6
    okay = okay && check_minus(b, c, 13, 6u);  // 10/4 -  1/3 = 13/6
    okay = okay && check_minus(a, d, 4, 1u);   //  3/2 - -5/2 = 4
    okay = okay && check_minus(b, d, 5, 1u);   // 10/4 - -5/2 = 5
    okay = okay && check_minus(c, d, 17, 6u);  //  1/3 - -5/2 = 17/6
    okay = okay && check_minus(e, b, -5, 2u);  //    0 - 10/4 = -5/2

    // Waren alle Tests erfolgreich?
    if (okay) std::cout << "OK" << std::endl;
    return okay;
}
//*/

//*
bool check_multiply(const Rational& a, const Rational& b, int p_ref,
                    uint q_ref) {
    // Berechne r := (a * b)
    Rational r = a * b;

    // Vergleiche 'r' mit Referenz-Werten
    if (r.equals(p_ref, q_ref)) {
        // Okay, 'r' stimmt mit den vorgegebenen Referenz-Werten
        // ueberein, wir geben also 'true' zurueck
        return true;  // okay
    }

    // Fehlschlag
    std::cout << "FEHLER" << std::endl;
    std::cout << "!!! Eingabe.:     a = " << a << std::endl;
    std::cout << "!!! Eingabe.:     b = " << b << std::endl;
    std::cout << "!!! Erwartet: a * b = " << p_ref << "/" << q_ref << std::endl;
    std::cout << "!!! Erhalten: a * b = " << r.numerator() << "/"
              << r.denominator() << std::endl;
    return false;
}

bool test_multiply_op() {
    // Erstelle ein paar Zahlen zum Testen
    Rational a(3, 2);
    Rational b(10, 4);  // = 5/2
    Rational c(1, 3);
    Rational d(-5, 2);
    Rational e(0);

    // Ausgabe:
    std::cout << "Teste operator*(): ";

    // Durchlaufe Tests
    bool okay = true;
    okay = okay && check_multiply(a, b, 15, 4u);   //  3/2 *  5/2 = 15/4
    okay = okay && check_multiply(a, c, 1, 2u);    //  3/2 *  1/3 = 1/2
    okay = okay && check_multiply(b, c, 5, 6u);    // 10/4 *  1/3 = 5/6
    okay = okay && check_multiply(a, d, -15, 4u);  //  3/2 * -5/2 = -15/4
    okay = okay && check_multiply(b, d, -25, 4u);  // 10/4 * -5/2 = -25/4
    okay = okay && check_multiply(c, d, -5, 6u);   //  1/3 * -5/2 = -5/6
    okay = okay && check_multiply(e, b, 0, 1u);    //    0 * 10/4 = 0

    // Waren alle Tests erfolgreich?
    if (okay) std::cout << "OK" << std::endl;
    return okay;
}
//*/

//*
bool check_divide(const Rational& a, const Rational& b, int p_ref, uint q_ref) {
    // Berechne r := (a / b)
    Rational r = a / b;

    // Vergleiche 'r' mit Referenz-Werten
    if (r.equals(p_ref, q_ref)) {
        // Okay, 'r' stimmt mit den vorgegebenen Referenz-Werten
        // ueberein, wir geben also 'true' zurueck
        return true;  // okay
    }

    // Fehlschlag
    std::cout << "FEHLER" << std::endl;
    std::cout << "!!! Eingabe.:     a = " << a << std::endl;
    std::cout << "!!! Eingabe.:     b = " << b << std::endl;
    std::cout << "!!! Erwartet: a / b = " << p_ref << "/" << q_ref << std::endl;
    std::cout << "!!! Erhalten: a / b = " << r.numerator() << "/"
              << r.denominator() << std::endl;
    return false;
}

bool test_divide_op() {
    // Erstelle ein paar Zahlen zum Testen
    Rational a(3, 2);
    Rational b(10, 4);  // = 5/2
    Rational c(1, 3);
    Rational d(-5, 2);
    Rational e(0);

    // Ausgabe:
    std::cout << "Teste operator/(): ";

    // Durchlaufe Tests
    bool okay = true;
    okay = okay && check_divide(a, b, 3, 5u);    //  3/2 /  5/2 = 3/5
    okay = okay && check_divide(a, c, 9, 2u);    //  3/2 /  1/3 = 9/2
    okay = okay && check_divide(b, c, 15, 2u);   // 10/4 /  1/3 = 15/2
    okay = okay && check_divide(a, d, -3, 5u);   //  3/2 / -5/2 = -3/5
    okay = okay && check_divide(b, d, -1, 1u);   // 10/4 / -5/2 = -1
    okay = okay && check_divide(c, d, -2, 15u);  //  1/3 / -5/2 = -2/15
    okay = okay && check_divide(e, b, 0, 1u);    //    0 / 10/4 = 0

    // Waren alle Tests erfolgreich?
    if (okay) std::cout << "OK" << std::endl;
    return okay;
}
//*/

// ############################################################################
// ############################################################################
// ############################################################################

bool run_tests() {
    std::cout << "Starte Tests..." << std::endl;
    std::cout << std::endl;

    // Durchlaufe alle Tests
    bool okay = true;
    okay = okay && test_ctor();
    okay = okay && test_plus_op();
    okay = okay && test_minus_op();
    okay = okay && test_multiply_op();
    okay = okay && test_divide_op();

    if (okay) {
        std::cout << std::endl;
        std::cout << "Alle Tests waren erfolgreich!" << std::endl;
        return true;
    } else {
        return false;
    }
}

// ############################################################################
// ############################################################################
// ############################################################################

int main() {
    run_tests();

    // TODO: hier 'lyness' Funktion aufrufen
    lyness(Rational(11), Rational(29, 82), Rational(19, 22));
    lyness(Rational(20), Rational(-11, 3), Rational(-35, 32));
    lyness(Rational(21, 37), Rational(-51, 35), Rational(-32, 7));
    return 0;
}

void lyness(Rational a, Rational x0, Rational x1){
    Rational current(x1), prev(x0);
    for (int k = 2; k < 20; k++) {
        Rational tmp(current);     //arbeiten eh ohne Heap
        current = (a + current) / prev;
        prev = tmp;
       // std::cout << "k: " << k << "  --> " << current << std::endl;
        std::cout << current;
        if (current == x1 && prev == x0)
        {
            std::cout << "  -beendet- k: " << k << std::endl;
            break;
        }
        std::cout << ", ";
        }
}
