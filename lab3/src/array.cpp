#include "../include/array.hpp"

Array::Array() {
    array = new Figure*[1] {nullptr};
    size = 0;
    capacity = 0;
}

Array::Array(size_t _size) {
    size = _size;
    capacity = 0;
    array = new Figure*[size] {nullptr};
}


Array::Array(const Array& other) {
    size = other.size;
    capacity = other.capacity;
    array = new Figure*[size];

    for (int i = 0; i < capacity; i++) {
        array[i] = other.array[i] ? other.array[i]->clone() : nullptr;
    }
}

Array::Array(Array&& other) noexcept {
    array = other.array;
    size = other.size;
    capacity = other.capacity;

    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
}

size_t Array::getSize()
{
    return size;
}

void Array::add(Figure* figure) {
    array[capacity++] = figure;
}

Figure* Array::get(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return array[index];
}

void Array::update(int index, Figure* newFigure) {
    if (index < 0 || index >= size || index > capacity) return;

    if (array[index]) remove(index);

    array[index] = newFigure;
}

void Array::remove(int index) {
    if (index < 0 || index >=size) return;

    if (array[index]) {
        delete array[index];
        array[index] = nullptr;
        capacity--;
    }
}

double Array::getFigureAreaSum() const {
    double sum = 0;

    for (int i = 0; i < capacity; ++i) {
        sum += array[i]->getFigureArea();
    }

    return sum;
}

std::ostream& Array::getCoordinates(std::ostream& os) const {
    for (int i = 0; i < capacity; i++) {
        if (array[i]) {
            array[i]->output(os);
            os << "\n";
        }
    }
    return os;
}

std::ostream& Array::getGeometricalCenter(std::ostream& os) const {
    for (int i = 0; i < size; i++) {
        if (array[i]) {
            os << array[i]->getGeometricalCenter() << "\n";
        }
    }
    return os;
}

Array::~Array() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }

    delete[] array;
    size = 0;
}
