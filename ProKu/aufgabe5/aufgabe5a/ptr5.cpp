// #include <iostream>

// void foo(int** pp, int* pa, int *pb)
// {
//   std::cout << "foo: pp: [" << (&pp) << "] = " << pp << " -> " << (*pp) << "
//   -> " << (**pp) << std::endl; std::cout << "foo: pa: [" << (&pa) << "] = "
//   << pa << " -> " << (*pa) << std::endl; std::cout << "foo: pb: [" << (&pb)
//   << "] = " << pb << " -> " << (*pb) << std::endl; std::cout << std::endl;

//   // 3)
//   *pp = (*pa < *pb ? pa : pb);

//   std::cout << "3) *pp = (*pa < *pb ? pa : pb)" << std::endl;
//   std::cout << "foo: pp: [" << (&pp) << "] = " << pp << " -> " << (*pp) << "
//   -> " << (**pp) << std::endl; std::cout << "foo: pa: [" << (&pa) << "] = "
//   << pa << " -> " << (*pa) << std::endl; std::cout << "foo: pb: [" << (&pb)
//   << "] = " << pb << " -> " << (*pb) << std::endl; std::cout << std::endl;
// }

// int main()
// {
//   int x = 7;
//   int y = 3;
//   int* p = &x;

//   // 1)
//   std::cout << "1)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   // 2)
//   std::cout << "2) foo(&p, &x, &y)" << std::endl;
//   foo(&p, &x, &y);

//   // 4)
//   std::cout << "4)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << std::endl;

//   return 0;
// }

#include <iostream>

void foo(int** pp, int* pa, int* pb) {
    std::cout << "foo: pp: [" << (&pp) << "] = " << pp << " -> " << (*pp)
              << " -> " << (**pp)
              << std::endl;  // Ausgabe der Adresse, des Werts und des Werts auf
                             // den pp zeigt
    std::cout << "foo: pa: [" << (&pa) << "] = " << pa << " -> " << (*pa)
              << std::endl;  // Ausgabe der Adresse und des Werts von pa
    std::cout << "foo: pb: [" << (&pb) << "] = " << pb << " -> " << (*pb)
              << std::endl;  // Ausgabe der Adresse und des Werts von pb
    std::cout << std::endl;

    // 3)
    *pp =
        (*pa < *pb ? pa : pb);  // *pp wird auf die Adresse von pa oder pb
                                // gesetzt, je nachdem welcher Wert kleiner ist

    std::cout << "3) *pp = (*pa < *pb ? pa : pb)" << std::endl;
    std::cout << "foo: pp: [" << (&pp) << "] = " << pp << " -> " << (*pp)
              << " -> " << (**pp)
              << std::endl;  // Ausgabe der Adresse, des Werts und des Werts auf
                             // den pp zeigt nach Änderung
    std::cout << "foo: pa: [" << (&pa) << "] = " << pa << " -> " << (*pa)
              << std::endl;  // pa bleibt unverändert
    std::cout << "foo: pb: [" << (&pb) << "] = " << pb << " -> " << (*pb)
              << std::endl;  // pb bleibt unverändert
    std::cout << std::endl;
}

int main() {
    int x = 7;
    int y = 3;
    int* p = &x;

    // 1)
    std::cout << "1)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe von y und seiner Adresse
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe von p, seiner Adresse und dem Wert auf
                             // den p zeigt
    std::cout << std::endl;

    // 2)
    std::cout << "2) foo(&p, &x, &y)" << std::endl;
    foo(&p, &x,
        &y);  // Aufruf von foo mit den Adressen von p, x und y als
              // Argumenten
              //
              // Der Aufruf von foo(&p, &x, &y); in main() hat keine
              // Auswirkungen auf x, y in main(). Aber foo() ändert
              // den Wert von p, sodass es auf die Adresse von x oder y zeigt,
              // je nachdem welcher Wert kleiner ist.

    // 4)
    std::cout << "4)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // y bleibt unverändert
    std::cout << "main: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // p zeigt nun auf die Adresse von x oder y, je
                             // nachdem welcher Wert kleiner ist
    std::cout << std::endl;

    return 0;
}
