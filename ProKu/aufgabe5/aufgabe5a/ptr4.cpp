// #include <iostream>

// void swap1(int a, int b)
// {
//   std::cout << "swap1: a: [" << (&a) << "] = " << a << std::endl;
//   std::cout << "swap1: b: [" << (&b) << "] = " << b << std::endl;
//   int t(a);
//   a = b;
//   b = t;
// }

// void swap2(int* p, int* q)
// {
//   std::cout << "swap2: p: [" << (&p) << "] = " << p << " -> " << (*p) <<
//   std::endl; std::cout << "swap2: q: [" << (&q) << "] = " << q << " -> " <<
//   (*q) << std::endl; int t(*p); *p = *q; *q = t;
// }

// int main()
// {
//   int x = 7;
//   int y = 3;

//   // 1)
//   std::cout << "1)" << std::endl;
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << std::endl;

//   // 2)
//   std::cout << "2) swap1(x,y)" << std::endl;
//   swap1(x, y);
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << std::endl;

//   // 3)
//   std::cout << "3) swap2(&x,&y)" << std::endl;
//   swap2(&x, &y);
//   std::cout << "main: x: [" << (&x) << "] = " << x << std::endl;
//   std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
//   std::cout << std::endl;

//   return 0;
// }

#include <iostream>

void swap1(int a,
           int b) {  // der Wert wird kopiert - In swap1 werden Kopien von x und
                     // y übergeben, daher bleiben die Werte von x und y in
                     // main() unverändert, nachdem swap1 aufgerufen wurde.
    std::cout << "swap1: a: [" << (&a) << "] = " << a
              << std::endl;  // Ausgabe der Adresse und des Werts von a
    std::cout << "swap1: b: [" << (&b) << "] = " << b
              << std::endl;  // Ausgabe der Adresse und des Werts von b
    int t(a);
    a = b;
    b = t;
}

void swap2(int* p,
           int* q) {  // In swap2 werden die Adressen von x und y übergeben, und
                      // die Werte der Variablen x und y in main() werden direkt
                      // manipuliert. Daher werden die Werte von x und y in
                      // main() nach dem Aufruf von swap2 vertauscht.
    std::cout << "swap2: p: [" << (&p) << "] = " << p << " -> " << (*p)
              << std::endl;  // Ausgabe der Adresse, des Werts und des Werts auf
                             // den p zeigt
    std::cout << "swap2: q: [" << (&q) << "] = " << q << " -> " << (*q)
              << std::endl;  // Ausgabe der Adresse, des Werts und des Werts auf
                             // den q zeigt
    int t(*p);
    *p = *q;
    *q = t;
}

int main() {
    int x = 7;
    int y = 3;

    // 1)
    std::cout << "1)" << std::endl;
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // Ausgabe von x und seiner Adresse
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // Ausgabe von y und seiner Adresse
    std::cout << std::endl;

    // 2)
    std::cout << "2) swap1(x,y)" << std::endl;
    swap1(x, y);  // Aufruf von swap1 mit Kopien von x und y
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // x bleibt unverändert
    std::cout << "main: y: [" << (&y) << "] = " << y
              << std::endl;  // y bleibt unverändert
    std::cout << std::endl;

    // 3)
    std::cout << "3) swap2(&x,&y)" << std::endl;
    swap2(&x, &y);  // Aufruf von swap2 mit Adressen von x und y
    std::cout << "main: x: [" << (&x) << "] = " << x
              << std::endl;  // x und y sind nun vertauscht
    std::cout << "main: y: [" << (&y) << "] = " << y << std::endl;
    std::cout << std::endl;

    return 0;
}
