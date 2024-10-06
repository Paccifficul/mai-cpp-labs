#include "include/five.hpp"
#include <iostream>


int main() {
    Five f1 = Five("104");
    Five f2 = Five(2, '2');

    Five res1 = f1 + f2;
    Five res2 = f1 - f2;

    std::cout << "res1: " << res1 << std::endl;
    std::cout << "res2: " << res2 << std::endl;
}