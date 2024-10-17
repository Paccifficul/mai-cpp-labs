#include "../include/octagon.hpp"

Octagon::Octagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, 
            double x5, double y5, double x6, double y6, double x7, double y7, double x8, double y8) {
    firstPoint = Coordinate(x1, y1);
    secondPoint = Coordinate(x2, y2);
    thirdPoint = Coordinate(x3, y3);
    fourthPoint = Coordinate(x4, y4);
    fifthPoint = Coordinate(x5, y5);
    sixthPoint = Coordinate(x6, y6);
    seventhPoint = Coordinate(x7, y7);
    eighthPoint = Coordinate(x8, y8);
}

Octagon::Octagon(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4, Coordinate c5, Coordinate c6, Coordinate c7, Coordinate c8) {
    firstPoint = c1;
    secondPoint = c2;
    thirdPoint = c3;
    fourthPoint = c4;
    fifthPoint = c5;
    sixthPoint = c6;
    seventhPoint = c7;
    eighthPoint = c8;
}

Octagon::Octagon(const Octagon& other) {
    firstPoint = other.firstPoint;
    secondPoint = other.secondPoint;
    thirdPoint = other.thirdPoint;
    fourthPoint = other.fourthPoint;
    fifthPoint = other.fifthPoint;
    sixthPoint = other.sixthPoint;
    seventhPoint = other.secondPoint;
    eighthPoint = other.eighthPoint;
}

Coordinate Octagon::getGeometricalCenter() const {
    double x = (firstPoint.getX() + secondPoint.getX() + thirdPoint.getX() + fourthPoint.getX() + fifthPoint.getX() + sixthPoint.getX() + seventhPoint.getX() + eighthPoint.getX()) / 8;
    double y = (firstPoint.getY() + secondPoint.getY() + thirdPoint.getY() + fourthPoint.getY() + fifthPoint.getY() + sixthPoint.getY() + seventhPoint.getY() + eighthPoint.getY()) / 8;
    
    return Coordinate(round(x * 100) / 100, round(y * 100) / 100);
}

double Octagon::getFigureArea() const {
    // Gauss foramul
    double area = 0.5 * abs(firstPoint.getX() * secondPoint.getY() - firstPoint.getY() * secondPoint.getX()
                    + secondPoint.getX() * thirdPoint.getY() - secondPoint.getY() * thirdPoint.getX()
                    + thirdPoint.getX() * fourthPoint.getY() - thirdPoint.getY() * fourthPoint.getX()
                    + fourthPoint.getX() * fifthPoint.getY() - fourthPoint.getY() * fifthPoint.getX()
                    + fifthPoint.getX() * sixthPoint.getY() - fifthPoint.getY() * sixthPoint.getX()
                    + sixthPoint.getX() * seventhPoint.getY() - sixthPoint.getY() * seventhPoint.getX()
                    + seventhPoint.getX() * eighthPoint.getY() - seventhPoint.getY() * eighthPoint.getX()
                    + eighthPoint.getX() * firstPoint.getY() - eighthPoint.getY() * firstPoint.getX());
    
    return round(area * 100) / 100;
}

Octagon::operator double() const {
    return getFigureArea();
}

Figure& Octagon::operator=(const Figure& other) {
    if (this == &other) return *this;

    const Octagon* octa = dynamic_cast<const Octagon*>(&other);

    if (!octa) throw std::invalid_argument("Your figure is not octagon");

    firstPoint = octa->firstPoint;
    secondPoint = octa->secondPoint;
    thirdPoint = octa->thirdPoint;
    fourthPoint = octa->fourthPoint;
    fifthPoint = octa->fifthPoint;
    sixthPoint = octa->sixthPoint;
    seventhPoint = octa->seventhPoint;
    eighthPoint = octa->eighthPoint;

    return *this;
}

Figure& Octagon::operator=(Figure&& other) {
    const Octagon* octa = dynamic_cast<const Octagon*>(&other);

    if (!octa) throw std::invalid_argument("Your figure is not octagon");

    firstPoint = std::move(octa->firstPoint);
    secondPoint = std::move(octa->secondPoint);
    thirdPoint = std::move(octa->thirdPoint);
    fourthPoint = std::move(octa->fourthPoint);
    fifthPoint = std::move(octa->fifthPoint);
    sixthPoint = std::move(octa->sixthPoint);
    seventhPoint = std::move(octa->seventhPoint);
    eighthPoint = std::move(octa->eighthPoint);

    return *this;
}

bool Octagon::operator==(const Figure& other) {
    const Octagon* octa = dynamic_cast<const Octagon*>(&other);
    
    if (!octa) return false;

    return fifthPoint == octa->firstPoint && secondPoint == octa->secondPoint &&
            thirdPoint == octa->thirdPoint && fourthPoint == octa->fourthPoint &&
            fifthPoint == octa->fifthPoint && sixthPoint == octa->sixthPoint &&
            seventhPoint == octa->secondPoint && eighthPoint == octa->eighthPoint;
}

std::istream& Octagon::input(std::istream& in) {
        in >> firstPoint >> secondPoint >> thirdPoint >> fourthPoint
           >> fifthPoint >> sixthPoint >> seventhPoint >> eighthPoint;

        return in;
    }

std::ostream& Octagon::output(std::ostream& out) const {
    out << "Octagon with points:" << std::endl << firstPoint << std::endl << secondPoint << std::endl
        << thirdPoint << std::endl << fourthPoint << std::endl << fifthPoint << std::endl
        << sixthPoint << std::endl << seventhPoint << std::endl << eighthPoint << std::endl;
    
    return out;
}

Figure* Octagon::clone() const {
    return new Octagon(*this);
}

Octagon::~Octagon() {

}