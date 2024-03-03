///
/// Eine Klasse, welche eine rationale Zahl repraesentiert
///
#include "Rational.hpp"

    uint Rational::ggT(uint a, uint b) {
        // Solange b nicht gleich 0 ist, führe die Schleife aus.
        while (b != 0) {
            // Temporäre Variable temp wird mit dem Wert von b initialisiert.
            uint temp = b;
            // b wird aktualisiert auf den Rest der Division von a durch b.
            b = a % b;
            // a wird aktualisiert auf den vorherigen Wert von b.
            a = temp;
        }
        // Rückgabe des ggT, wobei der Betrag von a zurückgegeben wird.
        return a;
    }

    Rational::Rational() : p(0), q(1u) {}
    Rational::Rational(int p_in) : p(p_in), q(1u) {}
    Rational::Rational(int p_in, uint q_in) : p(p_in), q(q_in) {
        if (p == 0)
            q = 1u;
        else {
            int ggt = Rational::ggT((p > 0) ? p : -p, q);
            p = p / ggt;
            q = q / ggt;
        }
    }
    int Rational::numerator() const { return p; }
    uint Rational::denominator() const { return q; }
    bool Rational::is_integer() const { return q == 1u; }
    bool Rational::equals(int p_ref, uint q_ref) const {
        return p == p_ref && q == q_ref;
    }
    bool Rational::operator==(const Rational& other) const {
        if (numerator() == other.numerator() &&
            denominator() == other.denominator()) {
            return true;
        }
        return false;
    }

    Rational Rational::operator+(const Rational& other) const {
        return Rational(numerator() * other.denominator() +
                            other.numerator() * denominator(),
                        denominator() * other.denominator());
    }
    Rational Rational::operator-(const Rational& other) const {
        return Rational(numerator() * other.denominator() -
                            other.numerator() * denominator(),
                        denominator() * other.denominator());
    }
    Rational Rational::operator*(const Rational& other) const {
        return Rational(numerator() * other.numerator(),
                        denominator() * other.denominator());
    }
    Rational Rational::operator/(const Rational& other) const {
        return Rational(
            numerator() * (other.numerator() > 0 ? 1 : -1) *
                other.denominator(),
            denominator() * uint(other.numerator() > 0 ? other.numerator()
                                                       : -other.numerator()));
    }
