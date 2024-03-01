#include <iostream>

#include "dbe.hpp"
#include "ggT.hpp"
#include "kgV.hpp"

int main(int argc, char const *argv[]) {
    std::cout << ggT(3, 17) << std::endl;
    std::cout << ggT(-70, 42) << std::endl;
    std::cout << ggT(0, 1) << std::endl;
    std::cout << ggT(12, -18) << std::endl;
    std::cout << ggT(-24, -96) << std::endl;
    std::cout << ggT(0, 0) << std::endl;
    std::cout << kgV(3, 4) << std::endl;
    std::cout << kgV(-8, 24) << std::endl;
    std::cout << kgV(0, 1) << std::endl;
    std::cout << kgV(6, -13) << std::endl;
    std::cout << kgV(-7, -17) << std::endl;
    std::cout << kgV(0, 0) << std::endl;

    dbe(125, 2, 0, 0);
    dbe(0, 0, 3, 1);
    dbe(10, 1, 7, 3);
    dbe(706, 2, 46341, 5);
    return 0;
}
