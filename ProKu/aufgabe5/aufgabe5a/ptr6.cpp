// #include <iostream>

// void foo(int** p, int x)
// {
//   *p = &x;
//   std::cout << "foo: *p = &x" << std::endl;
//   std::cout << "foo: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p) << " -> "
//   << (**p) << std::endl; std::cout << std::endl;
// }

// void bar(int** q, int y)
// {
//   int a = y;
//   int b = a;
//   *q = &b;
//   std::cout << "bar: a = y; b = a; *q = &b" << std::endl;
//   std::cout << "bar: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "bar: a: [" << (&a) << "] = " << a << std::endl;
//   std::cout << "bar: b: [" << (&b) << "] = " << b << std::endl;
//   std::cout << "bar: q: [" << (&q) << "] = " << q << " -> " << (*q) << " -> "
//   << (**q) << std::endl; std::cout << std::endl;
// }

// int main()
// {
//   int x = 7;
//   int y = 3;
//   int* p = nullptr;
//   int* q = nullptr;

//   // 1)
//   std::cout << "1)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << std::endl;
//   std::cout << "main: q: [" << (&q) << "] = " << q << std::endl;
//   std::cout << std::endl;

//   // 2)
//   std::cout << "2) foo(&p, x)" << std::endl;
//   foo(&p, x);

//   // 3)
//   std::cout << "3)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << "main: q: [" << (&q) << "] = " << q << std::endl;
//   std::cout << std::endl;

//   // 4)
//   std::cout << "4) bar(&q, y)" << std::endl;
//   bar(&q, y);

//   // 5)
//   std::cout << "5)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << "main: q: [" << (&q) << "] = " << q << " -> " <<
//   (*q) << std::endl; std::cout << std::endl;

//   return 0;
// }

#include <iostream>

void foo(int** p, int x) {
    *p = &x;  // *p wird die Adresse von x zugewiesen
    std::cout << "foo: *p = &x" << std::endl;
    std::cout << "foo: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe der Adresse und des Werts von x
    std::cout << "foo: p: [" << (&p) << "] = " << p << " -> " << (*p) << " -> "
              << (**p) << std::endl;  // Ausgabe der Adresse von p, des Werts
                                      // von p und des Werts auf den p zeigt
    std::cout << std::endl;
}

void bar(int** q, int y) {
    int a = y;  // Eine lokale Variable a wird mit dem Wert von y initialisiert
    int b = a;  // Eine weitere lokale Variable b wird mit dem Wert von a
                // initialisiert
    *q = &b;    // *q wird die Adresse von b zugewiesen
    std::cout << "bar: a = y; b = a; *q = &b" << std::endl;
    std::cout << "bar: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe der Adresse und des Werts von y
    std::cout << "bar: a: [" << (&a) << "] = " << a
              << std::endl;  // Ausgabe der Adresse und des Werts von a
    std::cout << "bar: b: [" << (&b) << "] = " << b
              << std::endl;  // Ausgabe der Adresse und des Werts von b
    std::cout << "bar: q: [" << (&q) << "] = " << q << " -> " << (*q) << " -> "
              << (**q) << std::endl;  // Ausgabe der Adresse von q, des Werts
                                      // von q und des Werts auf den q zeigt
    std::cout << std::endl;
}

int main() {
    int x =
        7;  // Eine Variable x wird erstellt und mit dem Wert 7 initialisiert
    int y =
        3;  // Eine Variable y wird erstellt und mit dem Wert 3 initialisiert
    int* p = nullptr;  // Ein Zeiger p wird initialisiert, der auf nullptr zeigt
    int* q = nullptr;  // Ein weiterer Zeiger q wird initialisiert, der
                       // ebenfalls auf nullptr zeigt

    // 1)
    std::cout << "1)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe der Adresse und des Werts von x
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe der Adresse und des Werts von y
    std::cout << "main: p: [" << (&p) << "] = " << p
              << std::endl;  // Ausgabe der Adresse und des Werts von p
    std::cout << "main: q: [" << (&q) << "] = " << q
              << std::endl;  // Ausgabe der Adresse und des Werts von q
    std::cout << std::endl;

    // 2)
    std::cout << "2) foo(&p, x)" << std::endl;
    foo(&p,
        x);  // Aufruf der Funktion foo mit der Adresse von p und dem Wert von x

    // 3)
    std::cout << "3)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe der Adresse und des Werts von x
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe der Adresse und des Werts von y
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe der Adresse von p und des Werts auf den
                             // p zeigt
    std::cout << "main: q: [" << (&q) << "] = " << q
              << std::endl;  // Ausgabe der Adresse und des Werts von q
    std::cout << std::endl;

    // 4)
    std::cout << "4) bar(&q, y)" << std::endl;
    bar(&q,
        y);  // Aufruf der Funktion bar mit der Adresse von q und dem Wert von y

    // 5)
    std::cout << "5)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe der Adresse und des Werts von x
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe der Adresse und des Werts von y
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe der Adresse von p und des Werts auf den
                             // p zeigt
    std::cout << "main: q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // Ausgabe der Adresse von q und des Werts auf den
                             // q zeigt
    std::cout << std::endl;

    return 0;
}
// Der katastrophale Programmierfehler liegt darin, dass die Adressen lokaler
// Variablen außerhalb ihres Gültigkeitsbereichs verwendet werden.

// In der Funktion foo wird die Adresse der lokalen Variable x an *p zugewiesen.
// Nachdem foo beendet ist, wird x jedoch außerhalb ihres Gültigkeitsbereichs
// sein, da sie eine lokale Variable ist und ihr Speicher freigegeben wird, wenn
// die Funktion beendet ist. Dadurch wird *p auf eine ungültige Speicheradresse
// zeigen.

// Gleiches gilt für die Funktion bar. Die Adresse der lokalen Variable b wird
// an *q zugewiesen. Nachdem bar beendet ist, wird b außerhalb ihres
// Gültigkeitsbereichs sein und die Speicheradresse, auf die *q zeigt, ungültig
// machen.

// Deshalb führt der Zugriff auf *p und *q in der main-Funktion zu undefiniertem
// Verhalten, was dazu führt, dass die Ausgabe unter 5) seltsame Werte liefert.
