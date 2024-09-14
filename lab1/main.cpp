#include "include/task.h"

int main() {
    std::string s;

    std::cout << "Enter sentence: ";
    std::cin >> s;
    std::cout << "Your entered sentence without vowels: " << removeVowels(s) << std::endl;

    return 0;
}