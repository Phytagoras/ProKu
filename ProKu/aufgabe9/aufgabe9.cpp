#include <cmath>  // std::round
#include <iostream>

#include "image.hpp"

void threshold(Image& img);

void floyd_steinberg(Image& img);

int main(int argc, char* argv[]) {
    // Haben wir genuegend Argumente?
    if (argc < 4) {
        std::cout << "BENUTZE: aufgabe-9 <EingabeDatei> <AusgabeDatei1> "
                     "<AusgabeDatei2>"
                  << std::endl;
        return 0;
    }

    // versuche, das Bild einzulesen
    std::cout << "Lese Datei '" << argv[1] << "'..." << std::endl;
    const Image image(argv[1]);

    // Erstelle eine Kopie von 'image',
    // wende 'threshold' Algorithmus darauf an
    // und exportiere das Bild in eine Datei:
    Image image_1(image);

    std::cout << "Wende 'threshold' an..." << std::endl;
    threshold(image_1);

    std::cout << "Schreibe Datei '" << argv[2] << "'..." << std::endl;
    image_1.write(argv[2]);

    // Erstelle eine Kopie von 'image',
    // wende Floyd-Steinberg darauf an
    // und exportiere das Bild in eine Datei:
    Image image_2(image);

    std::cout << "Wende 'floyd_steinberg' an..." << std::endl;
    floyd_steinberg(image_2);

    std::cout << "Schreibe Datei '" << argv[3] << "'..." << std::endl;
    image_2.write(argv[3]);

    // okay
    std::cout << "Fertig!" << std::endl;
    return 0;
}
void threshold(Image& img) {
    for (uint i = 0; i < img.height(); i++) {
        for (uint j = 0; j < img.width(); j++) {
            float* pixel = &img.at(i, j);
            if (*pixel < 0.5) {
                *pixel = 0;
            } else
                *pixel = 1;
        }
    }
}
void floyd_steinberg(Image& img) {
    for (uint i = 0; i < img.height(); i++) {
        for (uint j = 0; j < img.width(); j++) {
            float old = img.at(i, j);
            float err;

            if (old < 0.5) {
                img.at(i, j) = 0;
                err = old;
            } else {
                img.at(i, j) = 1;
                err = old - 1;
            }
            if (j < img.width() - 1) {
                img.at(i, j + 1) = img.at(i, j + 1) + float(7. / 16.) * err;

                if (i < img.height() - 1) {
                    img.at(i + 1, j + 1) =
                        img.at(i + 1, j + 1) + float(1. / 16.) * err;
                }
            }
            if (i < img.height() - 1) {
                img.at(i + 1, j) = img.at(i + 1, j) + float(5. / 16.) * err;
                if (j > 0) {
                    img.at(i + 1, j - 1) =
                        img.at(i + 1, j - 1) + float(3. / 16.) * err;
                }
            }
        }
    }
}