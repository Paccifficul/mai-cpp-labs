#pragma once

#include <iostream>

class Coordinate {
private:
    double x;
    double y;
public:
    Coordinate(); // Конструктор по-умолчанию
    Coordinate(double x, double y); // Конструктор с двумя переменными x, y
    Coordinate(const Coordinate& other); // Конструктор копирвоания без изменения входного параметра
    Coordinate(Coordinate&& other) noexcept; // Конструктор перемещения

    double getX() const;
    double getY() const;

    Coordinate& operator=(const Coordinate& other);
    Coordinate& operator=(Coordinate&& other) noexcept;

    bool operator<(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;

    friend std::istream& operator>>(std::istream& in, Coordinate& obj);
    friend std::ostream& operator<<(std::ostream& out, const Coordinate& obj);
};