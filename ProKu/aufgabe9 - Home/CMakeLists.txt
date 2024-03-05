cmake_minimum_required(VERSION 3.0)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(aufgabe9)

# die Liste aller ausfuehrbaren Programe
add_executable(aufgabe9 aufgabe9.cpp image.cpp jpeg_io.cpp)

# Programm gegen 'jpeglib' linken
target_link_libraries(aufgabe9 jpeg)

# Ziel zum Erzeugen der Ausgabebilder
add_custom_target(bilder
  COMMAND aufgabe9 ../bilder/bahn.jpg bahn_th.jpg bahn_fs.jpg
  COMMAND aufgabe9 ../bilder/minerva.jpg minerva_th.jpg minerva_fs.jpg
  COMMAND aufgabe9 ../bilder/royo.jpg royo_th.jpg royo_fs.jpg
)
