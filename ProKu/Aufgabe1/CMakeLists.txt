# setze CMake Version 3.0 voraus
cmake_minimum_required(VERSION 3.0)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(Proku)

# die Liste aller ausfuehrbaren Programme
add_executable(Prim Primzahlen.cpp)
add_executable(teilA teilA.cpp)

add_executable(hailey Bailey-Borwein-Plouffe-Formel.cpp)