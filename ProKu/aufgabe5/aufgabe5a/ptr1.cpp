/* #include <iostream>

int main() {
    // 1)
    int x = 7;
    int* p = &x;

    std::cout << "1)" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x << std::endl;
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
    std::cout << std::endl;

    // 2)
    *p = 3;

    std::cout << "2) *p = 3" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x << std::endl;
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p) << std::endl;
    std::cout << std::endl;

    return 0;
}
 */
#include <iostream>

int main() {
    // 1)
    int x = 7;
    int* p = &x;

    std::cout << "1)" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem Wert auf
                             // den p zeigt
    std::cout << std::endl;

    // 2)
    *p = 3;  // Ändert den Wert von x über den Zeiger p

    std::cout << "2) *p = 3" << std::endl;
    std::cout << "x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse nach Änderung
    std::cout << "p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem neuen Wert
                             // auf den p zeigt (der ebenfalls 3 ist)
    std::cout << std::endl;

    return 0;
}
