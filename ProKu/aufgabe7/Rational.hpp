#ifndef RATIONAL_H
#define RATIONAL_H


// Ein typedef fuer 'uint'
typedef unsigned int uint;

class Rational {
   private:
    int p;
    uint q;

    uint ggT(uint a, uint b);

   public:
    explicit Rational();
    explicit Rational(int p_in);
    explicit Rational(int p_in, uint q_in);

    int numerator() const;
    uint denominator() const;
    bool is_integer() const;
    bool equals(int p_ref, uint q_ref) const;

    bool operator==(const Rational& other) const;
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
};

#endif /* RATIONAL_H */
