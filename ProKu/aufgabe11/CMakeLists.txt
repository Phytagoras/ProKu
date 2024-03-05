cmake_minimum_required(VERSION 3.0)

# C++11 Standard verwenden
set(CMAKE_CXX_STANDARD 11)

# zusaetzliche Compiler-Optionen
add_compile_options(-O0 -pedantic -Wfatal-errors -Wall)
add_compile_options(-Wextra -Wshadow -Wconversion -Wno-unused)

# Projektname fuer CMake
project(aufgabe11)

# die Liste aller ausfuehrbaren Programe
add_executable(example1 example1.cpp canvas_window.cpp)
add_executable(example2 example2.cpp canvas_window.cpp)
add_executable(example3 example3.cpp canvas_window.cpp)
add_executable(aufgabe11 aufgabe11.cpp canvas_window.cpp)

# Programme gegen 'X11' Bibliothek linken
target_link_libraries(example1 X11)
target_link_libraries(example2 X11)
target_link_libraries(example3 X11)
target_link_libraries(aufgabe11 X11)
