cmake_minimum_required(VERSION 3.0)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(aufgabe5)

# die Liste aller ausfuehrbaren Programe
add_executable(aufgabe5a-ptr1 aufgabe5a/ptr1.cpp)
add_executable(aufgabe5a-ptr2 aufgabe5a/ptr2.cpp)
add_executable(aufgabe5a-ptr3 aufgabe5a/ptr3.cpp)
add_executable(aufgabe5a-ptr4 aufgabe5a/ptr4.cpp)
add_executable(aufgabe5a-ptr5 aufgabe5a/ptr5.cpp)
add_executable(aufgabe5a-ptr6 aufgabe5a/ptr6.cpp)
add_executable(aufgabe5b aufgabe5b.cpp)
add_executable(aufgabe5c aufgabe5c.cpp)
add_executable(aufgabe5d aufgabe5d.cpp)
