#include "../include/task.h"

std::string removeVowels(std::string str) {
    std::string res = "";

    for (char c : str) {
        if (c == 'a' || c == 'A' || // English
            c == 'e' || c == 'E' || 
            c == 'y' || c == 'Y' ||
            c == 'u' || c == 'U' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O') continue;

        res += c;
    }

    return res;
}