#include <iostream>
#include <limits>
#include <string>

// Funktion zur Eingabe eines Datums
void date();
// Funktion zur Berechnung des Wochentags
std::string getWeekday(int pastDays);

int main() {
    // Endlosschleife für kontinuierliche Eingabe
    while (true) {
        date();  // Aufruf der Datumseingabe-Funktion
    }
    return 0;
}

void date() {
    int day = -1, month = -1, year = -1;

    // Schleife für die Datumsvalidierung
    while (true) {
        std::cout
            << "Bitte geben Sie bitte ein Datum in der Form (dd mm yyyy) ein: ";
        std::cin >> day >> month >> year;

        // Überprüfung auf fehlerhafte Eingabe
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut."
                      << std::endl;
        } else if (0 < day && 0 < month && 1584 <= year && 32 > day &&
                   13 > month) {
            if (day > 29) {
                if (month == 2) {
                    std::cout
                        << "Ungültige Eingabe. Bitte versuchen Sie es erneut."
                        << std::endl;
                    continue;
                }
                if (day == 31) {
                    if (month % 2 == 0 && month <= 7) {
                        std::cout << "Ungültige Eingabe. Bitte versuchen Sie "
                                     "es erneut."
                                  << std::endl;
                        continue;
                    }
                    if (month % 2 == 1 && month > 7) {
                        std::cout << "Ungültige Eingabe. Bitte versuchen Sie "
                                     "es erneut."
                                  << std::endl;
                        continue;
                    }
                }
            }
            // Erfolgreiche Eingabe, Schleife beenden
            break;

        } else {
            std::cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut."
                      << std::endl;
        }
    }
    int countedDays(0);
    // Berechnung der vergangenen Tage seit dem Jahr 1584
    for (int i = 1584; i < year; i++) {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
            countedDays += 366;
        } else {
            countedDays += 365;
        }
    }

    for (int i = 1; i < month; i++) {
        if (i == 2) {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                countedDays += 29;
            } else
                countedDays += 28;
        } else if (i % 2 == 1 && i <= 7) {
            countedDays += 31;
        } else if (i % 2 == 0 && i > 7) {
            countedDays += 31;
        } else
            countedDays += 30;
    }
    countedDays += day - 1;  // Vergangene Tage ist eins weniger der aktuelle
                             // Tag ist noch nicht vergangen
    std::string weekday = getWeekday(countedDays);

    std::cout << "Der " << day << "." << month << "." << year << " ist ein "
              << weekday << std::endl;
}

// Funktion zur Bestimmung des Wochentags anhand der vergangenen Tage
std::string getWeekday(int pastDays) {
    std::string weekday = "";
    switch ((pastDays % 7)) {
        case 0:
            weekday = "Sonntag";
            break;
        case 1:
            weekday = "Montag";
            break;
        case 2:
            weekday = "Dienstag";
            break;
        case 3:
            weekday = "Mittwoch";
            break;
        case 4:
            weekday = "Donnerstag";
            break;
        case 5:
            weekday = "Freitag";
            break;
        case 6:
            weekday = "Samstag";
            break;
    }
    return weekday;
}
