cmake_minimum_required(VERSION 3.0)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(aufgabe6)

# die Liste aller ausfuehrbaren Programe
add_executable(aufgabe6 aufgabe6.cpp jpeg_io.cpp parse.cpp)

# Programm gegen 'jpeglib' linken
target_link_libraries(aufgabe6 jpeg)

# Ziel zum Erzeugen der Ausgabebilder
add_custom_target(images 
  COMMAND aufgabe6 ./image1.jpg 1280 960 1.6 1.2  0.41  0.14 100 100
  COMMAND aufgabe6 ./image2.jpg 1280 960 1.6 1.2 -0.60  0.50 100 100
  COMMAND aufgabe6 ./image3.jpg 1280 960 1.6 1.2 -0.78  0.13 100 100
  COMMAND aufgabe6 ./image4.jpg 1280 960 1.6 1.2  0.00 -0.80 100 100
  COMMAND aufgabe6 ./image5.jpg 1280 960 0.4 0.3 -1.40  0.00 100 100
)
