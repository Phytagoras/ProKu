#include <deque>  // std::deque
#include <iostream>
#include <string>  // std::string

// Zerlegt einen Satz in eine deque aus Woertern
//
// Beispiel:
// Eingabe: "Hello World"
// Ausgabe: ["Hello", "World"]
//
// \param[in] str
// Der string, der in seine Worte zerlegt werden soll
//
// \returns
// Eine deque aus strings, welche die einzelnen Worte
// von 'str' enthaelt
std::deque<std::string> split(const std::string& str) {
    std::deque<std::string> words;
    std::string word;

    for (char ch : str) {
        if (ch != ' ') {
            word += ch;
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

// Kehrt die Buchstaben in einem string um
//
// Beispiel:
// Eingabe: "foobar"
// Ausgabe: "raboof"
//
// \param[in] str
// Der string, dessen Buchstaben umgekehrt werden soll
//
// \returns
// Der umgekehrte string
std::string reverse(const std::string& str) {
    std::string reversed;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

// Kehrt die Buchstaben in jedem string einer deque um
//
// \param[in,out] words
// Eine deque aus strings, welche umgekehrt werden sollen.
void reverse_words(std::deque<std::string>& words) {
    for (std::deque<std::string>::iterator it = words.begin();
         it != words.end();
         it++) {  // for (auto it = words.begin();it != words.end(); it++) mit
                  // auto type deduction
        *it = reverse(*it);
    }
}

// Fuegt eine deque aus strings zu einem mit Leerzeichen getrennten string
// zusammen
//
// Beispiel:
// Eingabe: ["foo", "bar"]
// Ausgabe: "foo bar"
//
// \param[in] words
// Die deque aus strings, welche zusammengefuegt werden sollen
//
// \returns
// Der zusammengesetzte string
std::string join(const std::deque<std::string>& words) {
    std::string result;

    // Iteriere über alle Wörter außer dem letzten
    for (auto it = words.begin(); it != words.end(); ++it) {
        result += *it;  // for( std::deque<std::string>::const_iterator ...
        if (std::next(it) !=
            words.end()) {  // Überprüfe, ob es nicht das letzte Wort ist
            result += " ";
        }
    }

    return result;
}

// Die main Funktion
int main() {
    // Eingabe-Text
    const std::string text = "eht kciuq nworb xof spmuj revo a yzal god";

    // Zerlege in Worte
    std::deque<std::string> words = split(text);

    // Worte umkehren
    reverse_words(words);

    // Worte zusammenfuegen
    std::string rev_text = join(words);

    // Ausgabe
    std::cout << rev_text << std::endl;

    // okay
    return 0;
}