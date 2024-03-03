cmake_minimum_required(VERSION 3.5)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(aufgabe7)

# die Liste aller ausfuehrbaren Programe
add_executable(aufgabe7 aufgabe7.cpp Rational.cpp Rational.hpp)
