#include <iomanip>
#include <iostream>

#include "parse.hpp"

double transform(int i, int n, double r);
double escape_time(double x, double y, double cx, double cy, double rmax,
                   int kmax);

int main() {
    int argc = 10;
    const char *argv[] = {"PFAD", "Dateiname", "20",   "20",  "1.6",
                          "1.2",  "0.41",      "0.14", "100", "100"};
    const char *dateiNAme;
    int breite, hoehe, kmax;  //natuerlich kann ich auch uInt verwenden...die Frage kommt eh
    double cx, cy, rx, ry, rmax;
    // std::cout << argc << std::endl;
    // for (int i(0); i < argc; ++i) {
    //     std ::cout << i << ": '" << argv[i] << "'" << std ::endl;
    // }
    if (argc == 10) {
        dateiNAme = argv[1];
        if (parse(argv[2], breite) && breite >= 8 && breite <= 2048) {
            std ::cout << "Breite: " << breite << std ::endl;

            if (parse(argv[3], hoehe) && hoehe >= 8 && hoehe <= 2048) {
                std ::cout << "Hoehe: " << hoehe << std ::endl;
                if (parse(argv[4], rx) && rx >= 0.1 && rx <= 5.) {
                    std ::cout << "rx: " << rx << std ::endl;
                    if (parse(argv[5], ry) && ry >= 0.1 && ry <= 5.) {
                        std ::cout << "ry: " << ry << std ::endl;
                        if (parse(argv[6], cx) && cx >= -2. && cx <= 2.) {
                            std ::cout << "cx: " << cx << std ::endl;
                            if (parse(argv[7], cy) && cy >= -2. && cy <= 2.) {
                                std ::cout << "cy: " << cy << std ::endl;
                                if (parse(argv[8], rmax) && rmax >= 10. &&
                                    rmax <= 500.) {
                                    std ::cout << "rmax: " << rmax
                                               << std ::endl;
                                    if (parse(argv[9], kmax) && kmax >= 10 &&
                                        kmax <= 500) {
                                        std ::cout << "kmax: " << kmax
                                                   << std ::endl;
                                        // EINGABE ERFOLGREICH HIER WEITER
                                        //
                                        //

                                        double *pixelVal =
                                            new double[breite * hoehe];
                                        for (int row = 0; row < hoehe; row++) {
                                            for (int col = 0; col < breite;
                                                 col++) {
                                                double value = escape_time(
                                                    transform(row, hoehe, rx),
                                                    transform(col, breite, ry),
                                                    cx, cy, rmax, kmax);
                                                pixelVal[row * breite + col] =
                                                    value;
                                                std::cout << row << "  " << col
                                                          << std::endl;
                                            }
                                        }
                                        // bool writeJpeg =
                                        //     if (write_jpeg(
                                        //             breite,
                                        //             hoehe,
                                        //             pixelVal,
                                        //             dateiName));
                                        std::cout << std::fixed
                                                  << std::setprecision(2);
                                        for (int row = 0; row < hoehe; row++) {
                                            std::cout
                                                << "| "
                                                << pixelVal[row * breite + 0];
                                            for (int col = 1; col < breite;
                                                 col++) {
                                                std::cout
                                                    << "  ---  "
                                                    << pixelVal[row * breite +
                                                                col];
                                            }
                                            std::cout << " |" << std::endl
                                                      << std::endl;
                                        }
                                        std::cout << std::defaultfloat;
                                        delete pixelVal;
                                    } else
                                        std ::cout
                                            << "Mit der kmax stimmt was nicht!"
                                            << std ::endl;
                                } else
                                    std ::cout
                                        << "Mit der Hoehe stimmt was nicht!"
                                        << std ::endl;
                            } else
                                std ::cout << "Mit der cy stimmt was nicht!"
                                           << std ::endl;
                        } else
                            std ::cout << "Mit der cx stimmt was nicht!"
                                       << std ::endl;
                    } else
                        std ::cout << "Mit der ry stimmt was nicht!"
                                   << std ::endl;
                } else
                    std ::cout << "Mit der rx stimmt was nicht!" << std ::endl;
            } else
                std ::cout << "Mit der Hoehe stimmt was nicht!" << std ::endl;
        } else
            std ::cout << "Mit der Breite stimmt was nicht!" << std ::endl;
    } else
        std ::cout << "Die Anzahl der Parameter ist falsch!!!" << std ::endl;
    return 0;
}

double transform(int i, int n, double r) {
    return ((2. * r * double(i)) / (double(n) - 1.)) - 1;
}

double escape_time(double x, double y, double cx, double cy, double rmax,
                   int kmax) {
    int k = 0;
    while (x * x + y * y < rmax && k < kmax) {
        double tmpX(x), tmpY(y);
        x = tmpX * tmpX - tmpY * tmpY + cx;
        y = tmpX * tmpY * 2. + cy;
        k++;
    }
    return double(k) / double(kmax);
}
