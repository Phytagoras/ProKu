#include <iostream>
#include <limits>

int main() {
    int a = 0, b = 0;
    char op;

    while (true) {
        std::cout << "Bitte geben Sie zwei ganze Zahlen und einen Operator (+, -, *, /, %) ein: ";
        std::cin >> a >> op >> b;

        // Überprüfen, ob die Eingabe erfolgreich war
        if (std::cin.fail()) {
            std::cin.clear(); // Fehlerzustand zurücksetzen
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Puffer leeren
            std::cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut." << std::endl;
        } else if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%') {
            std::cout << "Ungültiger Operator. Bitte verwenden Sie einen der folgenden: +, -, *, /, %" << std::endl;
        } else if ((op == '/' || op == '%') && b == 0) {
            std::cout << "Division durch Null ist nicht erlaubt. Bitte geben Sie eine andere Zahl ein." << std::endl;
        } else {
            // Eingabe war erfolgreich, Breche die Schleife ab
            break;
        }
    }
    std::cout << "Eingabe: " << a << " " << op << " " << b << " = ";

double solution (0);
double c(a), d(b);
    switch (op)
    {
    case '+':
        solution = a + b; 
        break;
    case '-':
        solution = a - b; 
        break;
    case '*':
        solution = a * b; 
        break;
    case '/':
        solution = c / d; 
        break;
    case '%':
        solution = a % b; 
        break;
    
    default:
        break;
    }

    std::cout << solution << std::endl;

    return 0;
}
