#pragma once

#include <iostream>
#include "figure.hpp"

class Array {
private:
    Figure** array;
    size_t size;
    size_t capacity;
public:
    Array();
    Array(size_t _size);
    Array(const Array& other);
    Array(Array&& other) noexcept;

    size_t getSize();

    void add(Figure* figure);
    Figure* get(int index) const;
    void update(int index, Figure* newFigure);
    void remove(int index);

    double getFigureAreaSum() const;

    std::ostream& getCoordinates(std::ostream& os) const;
    std::ostream& getGeometricalCenter(std::ostream& os) const;

    ~Array();
};