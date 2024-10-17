#pragma once

#include "coordinate.hpp"
#include <cmath>

class Figure {
public:
    virtual Coordinate getGeometricalCenter() const = 0;
    virtual double getFigureArea() const = 0;
    virtual operator double() const = 0;
    virtual Figure* clone() const = 0;

    virtual Figure& operator=(const Figure& other) {
        return *this;
    }

    virtual Figure& operator=(Figure&& other) = 0;

    virtual bool operator==(const Figure& other) = 0;

    virtual std::istream& input(std::istream& in) = 0;
    virtual std::ostream& output(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, Figure& obj) {
        return obj.output(out);
    }

    friend std::istream& operator>>(std::istream& in, Figure& obj) {
        return obj.input(in);
    }

    virtual ~Figure() = default;
};