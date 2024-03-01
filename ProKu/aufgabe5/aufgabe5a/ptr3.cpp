
// #include <iostream>

// void foo(int* p)
// {
//   // 2)
//   std::cout << "2) foo(p)" << std::endl;
//   std::cout << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   // 3)
//   *p = 3;
//   std::cout << "3) *p = 3" << std::endl;
//   std::cout << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   // 4)
//   p = nullptr;
//   std::cout << "4) p = nullptr" << std::endl;
//   std::cout << "foo: p: [" << (&p) << "] = " << p << std::endl;
//   std::cout << std::endl;
// }

// int main()
// {
//   // 1)
//   int x = 7;
//   int* p = &x;

//   std::cout << "1)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   // 2), 3), 4)
//   foo(p);

//   // 5)
//   std::cout << "5)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   return 0;
// }

#include <iostream>

void foo(int* p) {  // Kopie von p
    // 2)
    std::cout << "2) foo(p)" << std::endl;
    std::cout
        << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p)
        << std::endl;  // Ausgabe der Adresse und des Werts auf den p zeigt
    std::cout << std::endl;

    // 3)
    *p = 3;  // Ändert den Wert auf den p zeigt auf 3 also x=3

    std::cout << "3) *p = 3" << std::endl;
    std::cout << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe der Adresse und des neuen Werts auf den
                             // p zeigt (3)
    std::cout << std::endl;

    // 4)
    p = nullptr;  // Setzt p auf den Null-Zeiger (orig bleibt)

    std::cout << "4) p = nullptr" << std::endl;
    std::cout << "foo: p: [" << (&p) << "] = " << p
              << std::endl;  // Ausgabe der Adresse von p, die jetzt nullptr ist
    std::cout << std::endl;
}

int main() {
    // 1)
    int x = 7;
    int* p = &x;

    std::cout << "1)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem Wert auf
                             // den p zeigt
    std::cout << std::endl;

    // 2), 3), 4)
    foo(p);  // Aufruf der Funktion foo mit p als Argument

    // Nach dem Aufruf von foo(p) in main:

    // 5)
    std::cout << "5)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem Wert auf
                             // den p zeigt (7)
    std::cout << std::endl;

    return 0;
}
