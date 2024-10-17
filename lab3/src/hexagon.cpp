#include "../include/hexagon.hpp"

Hexagon::Hexagon(double x1, double y1, double x2, double y2, double x3, double y3,
        double x4, double y4, double x5, double y5, double x6, double y6) {
    firstPoint = Coordinate(x1, y1);
    secondPoint = Coordinate(x2, y2);
    thirdPoint = Coordinate(x3, y3);
    fourthPoint = Coordinate(x4, y4);
    fifthPoint = Coordinate(x5, y5);
    sixthPoint = Coordinate(x6, y6);
}

Hexagon::Hexagon(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4, Coordinate c5, Coordinate c6) {
    firstPoint = c1;
    secondPoint = c2;
    thirdPoint = c3;
    fourthPoint = c4;
    fifthPoint = c5;
    sixthPoint = c6;
}

Hexagon::Hexagon(const Hexagon& other) {
    firstPoint = other.firstPoint;
    secondPoint = other.secondPoint;
    thirdPoint = other.thirdPoint;
    fourthPoint = other.fourthPoint;
    fifthPoint = other.fifthPoint;
    sixthPoint = other.sixthPoint;
}

Coordinate Hexagon::getGeometricalCenter() const {
    double x = (firstPoint.getX() + secondPoint.getX() + thirdPoint.getX() + fourthPoint.getX() + fifthPoint.getX() + sixthPoint.getX()) / 6;
    double y = (firstPoint.getY() + secondPoint.getY() + thirdPoint.getY() + fourthPoint.getY() + fifthPoint.getY() + sixthPoint.getY()) / 6;

    return Coordinate(round(x * 100) / 100, round(y * 100) / 100);
}

double Hexagon::getFigureArea() const {
    // Gauss foramul
    double area = 0.5 * abs(firstPoint.getX() * secondPoint.getY() - firstPoint.getY() * secondPoint.getX()
                    + secondPoint.getX() * thirdPoint.getY() - secondPoint.getY() * thirdPoint.getX()
                    + thirdPoint.getX() * fourthPoint.getY() - thirdPoint.getY() * fourthPoint.getX()
                    + fourthPoint.getX() * fifthPoint.getY() - fourthPoint.getY() * fifthPoint.getX()
                    + fifthPoint.getX() * sixthPoint.getY() - fifthPoint.getY() * sixthPoint.getX()
                    + sixthPoint.getX() * firstPoint.getY() - sixthPoint.getY() * firstPoint.getX());

    return round(area * 100) / 100;
}

Hexagon::operator double() const {
    return getFigureArea();
}

Figure& Hexagon::operator=(const Figure& other) {
    if (this == &other) return *this;

    const Hexagon* hexa = dynamic_cast<const Hexagon*>(&other);

    if (!hexa) throw std::invalid_argument("Your figure is not hexagon");

    firstPoint = hexa->firstPoint;
    secondPoint = hexa->secondPoint;
    thirdPoint = hexa->thirdPoint;
    fourthPoint = hexa->fourthPoint;
    fifthPoint = hexa->fifthPoint;
    sixthPoint = hexa->sixthPoint;

    return *this;
}

Figure& Hexagon::operator=(Figure&& other) {
    const Hexagon* hexa = dynamic_cast<const Hexagon*>(&other);

    if (!hexa) throw std::invalid_argument("Your figure is not hexagon");

    firstPoint = std::move(hexa->firstPoint);
    secondPoint = std::move(hexa->secondPoint);
    thirdPoint = std::move(hexa->thirdPoint);
    fourthPoint = std::move(hexa->fourthPoint);
    fifthPoint = std::move(hexa->fifthPoint);
    sixthPoint = std::move(hexa->sixthPoint);

    return *this;
}

bool Hexagon::operator==(const Figure& other) {
    const Hexagon* hexa = dynamic_cast<const Hexagon*>(&other);
    
    if (!hexa) return false;

    return fifthPoint == hexa->firstPoint && secondPoint == hexa->secondPoint &&
            thirdPoint == hexa->thirdPoint && fourthPoint == hexa->fourthPoint &&
            fifthPoint == hexa->fifthPoint && sixthPoint == hexa->sixthPoint;
}


std::istream& Hexagon::input(std::istream& in) {
        in >> firstPoint >> secondPoint >> thirdPoint 
           >> fourthPoint >> fifthPoint >> sixthPoint;

        return in;
    }

std::ostream& Hexagon::output(std::ostream& out) const {
    out << "Hexagon with points:" << std::endl << firstPoint << std::endl << secondPoint << std::endl
        << thirdPoint << std::endl << fourthPoint << std::endl << fifthPoint << std::endl
        << sixthPoint << std::endl;
    
    return out;
}

Figure* Hexagon::clone() const {
    return new Hexagon(*this);
}

Hexagon::~Hexagon() {

}