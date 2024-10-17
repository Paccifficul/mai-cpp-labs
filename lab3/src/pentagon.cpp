#include "../include/pentagon.hpp"

Pentagon::Pentagon(double x1, double y1, double x2, double y2, double x3, double y3,
        double x4, double y4, double x5, double y5) {
    firstPoint = Coordinate(x1, y1);
    secondPoint = Coordinate(x2, y2);
    thirdPoint = Coordinate(x3, y3);
    fourthPoint = Coordinate(x4, y4);
    fifthPoint = Coordinate(x5, y5);
}

Pentagon::Pentagon(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4, Coordinate c5) {
    firstPoint = c1;
    secondPoint = c2;
    thirdPoint = c3;
    fourthPoint = c4;
    fifthPoint = c5;
}

Pentagon::Pentagon(const Pentagon& other) {
    firstPoint = other.firstPoint;
    secondPoint = other.secondPoint;
    thirdPoint = other.thirdPoint;
    fourthPoint = other.fourthPoint;
    fifthPoint = other.fifthPoint;
}

Coordinate Pentagon::getGeometricalCenter() const {
    double x = (firstPoint.getX() + secondPoint.getX() + thirdPoint.getX() + fourthPoint.getX() + fifthPoint.getX()) / 5;
    double y = (firstPoint.getY() + secondPoint.getY() + thirdPoint.getY() + fourthPoint.getY() + fifthPoint.getY()) / 5;

    return Coordinate(round(x * 100) / 100, round(y * 100) / 100);
}   

double Pentagon::getFigureArea() const {
    // Gauss foramul
    double area = 0.5 * abs(firstPoint.getX() * secondPoint.getY() - firstPoint.getY() * secondPoint.getX()
                    + secondPoint.getX() * thirdPoint.getY() - secondPoint.getY() * thirdPoint.getX()
                    + thirdPoint.getX() * fourthPoint.getY() - thirdPoint.getY() * fourthPoint.getX()
                    + fourthPoint.getX() * fifthPoint.getY() - fourthPoint.getY() * fifthPoint.getX()
                    + fifthPoint.getX() * firstPoint.getY() - fifthPoint.getY() * firstPoint.getX());

    return round(area * 100) / 100;
}

Pentagon::operator double() const {
    return getFigureArea();
}

Figure& Pentagon::operator=(const Figure& other) {
    if (this == &other) return *this;

    const Pentagon* penta = dynamic_cast<const Pentagon*>(&other);

    if (!penta) throw std::invalid_argument("Your figure is not pentagon");

    firstPoint = penta->firstPoint;
    secondPoint = penta->secondPoint;
    thirdPoint = penta->thirdPoint;
    fourthPoint = penta->fourthPoint;
    fifthPoint = penta->fifthPoint;

    return *this;
}

Figure& Pentagon::operator=(Figure&& other) {
    const Pentagon* penta = dynamic_cast<const Pentagon*>(&other);

    if (!penta) throw std::invalid_argument("Your figure is not pentagon");

    firstPoint = std::move(penta->firstPoint);
    secondPoint = std::move(penta->secondPoint);
    thirdPoint = std::move(penta->thirdPoint);
    fourthPoint = std::move(penta->fourthPoint);
    fifthPoint = std::move(penta->fifthPoint);

    return *this;
}

bool Pentagon::operator==(const Figure& other) {
    const Pentagon* penta = dynamic_cast<const Pentagon*>(&other);
    
    if (!penta) return false;

    return fifthPoint == penta->firstPoint && secondPoint == penta->secondPoint &&
            thirdPoint == penta->thirdPoint && fourthPoint == penta->fourthPoint &&
            fifthPoint == penta->fifthPoint;
}

std::istream& Pentagon::input(std::istream& in) {
        in >> firstPoint >> secondPoint >> thirdPoint 
           >> fourthPoint >> fifthPoint;

        return in;
    }

std::ostream& Pentagon::output(std::ostream& out) const {
    out << "Pentagon with points:" << std::endl << firstPoint << std::endl << secondPoint << std::endl
        << thirdPoint << std::endl << fourthPoint << std::endl << fifthPoint << std::endl;
    
    return out;
}

Figure* Pentagon::clone() const {
    return new Pentagon(*this);
}

Pentagon::~Pentagon() {

}