// #include <iostream>

// int main()
// {
//   // 1)
//   int x = 7;
//   int y = 3;
//   int z = 5;
//   int* p = &x;
//   int* q = &z;

//   std::cout << "1)" << std::endl;
//   std::cout << "x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "z: [" << (&z) << "] = " << z << std::endl;
//   std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
//   std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q) << std::endl;
//   std::cout << std::endl;

//   // 2)
//   *p = *q;

//   std::cout << "2) *p = *q" << std::endl;
//   std::cout << "x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "z: [" << (&z) << "] = " << z << std::endl;
//   std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
//   std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q) << std::endl;
//   std::cout << std::endl;

//   // 3)
//   *q = 6;

//   std::cout << "3) *q = 6" << std::endl;
//   std::cout << "x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "z: [" << (&z) << "] = " << z << std::endl;
//   std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
//   std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q) << std::endl;
//   std::cout << std::endl;

//   // 4)
//   p = q;

//   std::cout << "4) p = q" << std::endl;
//   std::cout << "x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "z: [" << (&z) << "] = " << z << std::endl;
//   std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
//   std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q) << std::endl;
//   std::cout << std::endl;

//   // 5)
//   q = &y;

//   std::cout << "5) q = &y" << std::endl;
//   std::cout << "x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "z: [" << (&z) << "] = " << z << std::endl;
//   std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
//   std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q) << std::endl;
//   std::cout << std::endl;

//   return 0;
// }

#include <iostream>

int main() {
    // 1)
    int x = 7;
    int y = 3;
    int z = 5;
    int* p = &x;
    int* q = &z;

    std::cout << "1)" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse
    std::cout << "y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe von y und seiner Adresse
    std::cout << "z: [" << (&z) << "] = " << z
              << std::endl;  // Ausgabe von z und seiner Adresse
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem Wert auf
                             // den p zeigt
    std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // Ausgabe von q, seiner Adresse und dem Wert auf
                             // den q zeigt
    std::cout << std::endl;

    // 2)
    *p = *q;  // Ändert den Wert von x auf den Wert von z

    std::cout << "2) *p = *q" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse nach Änderung
    std::cout << "y: [" << (&y) << "] = " << y
              << std::endl;  // y bleibt unverändert
    std::cout << "z: [" << (&z) << "] = " << z
              << std::endl;  // z bleibt unverändert
    std::cout
        << "p: [" << (&p) << "] = " << p << " -> " << (*p)
        << std::endl;  // Ausgabe von p, seiner Adresse und dem neuen Wert auf
                       // den p zeigt (der ebenfalls den Wert von z hat)
    std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // q bleibt unverändert
    std::cout << std::endl;

    // 3)
    *q = 6;  // Ändert den Wert von z auf 6

    std::cout << "3) *q = 6" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "y: [" << (&y) << "] = " << y
              << std::endl;  // y bleibt unverändert
    std::cout << "z: [" << (&z) << "] = " << z
              << std::endl;  // Ausgabe von z und seiner Adresse nach Änderung
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // p bleibt unverändert
    std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // Ausgabe von q, seiner Adresse und dem neuen Wert
                             // auf den q zeigt (der jetzt 6 ist)
    std::cout << std::endl;

    // 4)
    p = q;  // p wird auf die Adresse von z gesetzt

    std::cout << "4) p = q" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe von y und seiner Adresse nach Änderung
    std::cout << "z: [" << (&z) << "] = " << z
              << std::endl;  // z bleibt unverändert
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem neuen Wert
                             // auf den p zeigt (die Adresse von z)
    std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // q bleibt unverändert
    std::cout << std::endl;

    // 5)
    q = &y;  // q wird auf die Adresse von y gesetzt

    std::cout << "5) q = &y" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe von y und seiner Adresse nach Änderung
    std::cout << "z: [" << (&z) << "] = " << z
              << std::endl;  // z bleibt unverändert
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem neuen Wert
                             // auf den p zeigt (die Adresse von y)
    std::cout << "q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // Ausgabe von q, seiner Adresse und dem neuen Wert
                             // auf den q zeigt (die Adresse von y)
    std::cout << std::endl;

    return 0;
}
