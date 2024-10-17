#include "../include/coordinate.hpp"

Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

Coordinate::Coordinate(double _x, double _y) {
    x = _x;
    y = _y;
}

Coordinate::Coordinate(const Coordinate& other) {
    x = other.x;
    y = other.y;
}

Coordinate::Coordinate(Coordinate&& other) noexcept {
    x = other.x;
    y = other.y;

    other.x = 0;
    other.y = 0;
}

Coordinate& Coordinate::operator=(const Coordinate& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }

    return *this;
}

Coordinate& Coordinate::operator=(Coordinate&& other) noexcept {
    if (this != &other) {
        x = other.x;
        y = other.y;

        other.x = 0;
        other.y = 0;
    }

    return *this;
}

bool Coordinate::operator<(const Coordinate& other) const {
    return x < other.x || (x > other.x && y < other.y);
}

bool Coordinate::operator==(const Coordinate& other) const {
    return x == other.x && y == other.y;
}

double Coordinate::getX() const {
    return x;
}

double Coordinate::getY() const {
    return y;
}

std::istream& operator>>(std::istream& in, Coordinate& obj) {
    in >> obj.x >> obj.y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Coordinate& obj) {
    out << '(' << obj.x << "; " << obj.y << ')';
    return out;
}