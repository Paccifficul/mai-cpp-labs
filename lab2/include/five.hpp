#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class Five {
private:
    unsigned char* array;
    size_t size;
public:
    Five();
    Five(const size_t &n, unsigned char t = 0);
    Five(const std::initializer_list<unsigned char> &t);
    Five(const std::string &t);
    Five(const Five &other);
    Five(Five&& other) noexcept;

    Five operator+(const Five& other);
    Five operator-(const Five& other);

    Five& operator=(const Five& other);
    Five& operator+=(const Five& other);
    Five& operator-=(const Five& other);

    const bool operator==(const Five& other);
    const bool operator!=(const Five& other);
    const bool operator>(const Five& other);
    const bool operator>=(const Five& other);
    const bool operator<(const Five& other);
    const bool operator<=(const Five& other);

    friend std::ostream& operator<<(std::ostream& out, Five& f);

    virtual ~Five() noexcept;
};