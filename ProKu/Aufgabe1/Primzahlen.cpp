#include <iostream>


void sieveOfEratosthenes(int n);


int main() {
    int N = 100;
    std::cout << "Primzahlen bis " << N << ": ";
    sieveOfEratosthenes(N);
    std::cout << std::endl;
    return 0;
}



void sieveOfEratosthenes(int n) {
    bool prime[n+1]; // Array zur Speicherung der Primzahlen

    // Alle Elemente des Arrays initialisieren
    for(int i = 0; i <= n; i++) {
        prime[i] = true;
    }

    // Sieb des Eratosthenes Algorithmus
    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            // Alle Vielfachen von p als nicht prim markieren
            for(int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Ausgabe der Primzahlen
    for(int p = 2; p <= n; p++) {
        if(prime[p] == true) {
            std::cout << p << " ";
        }
    }
}