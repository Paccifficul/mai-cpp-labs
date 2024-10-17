#pragma once

#include "figure.hpp"

class Hexagon : public Figure {
private:
    Coordinate firstPoint;
    Coordinate secondPoint;
    Coordinate thirdPoint;
    Coordinate fourthPoint;
    Coordinate fifthPoint;
    Coordinate sixthPoint;
public:
    Hexagon(double x1, double y1, double x2, double y2, double x3, double y3,
            double x4, double y4, double x5, double y5, double x6, double y6);
    Hexagon(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4, Coordinate c5, Coordinate c6);
    Hexagon(const Hexagon& other);

    Coordinate getGeometricalCenter() const override;
    double getFigureArea() const override;

    operator double() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) override;

    bool operator==(const Figure& other) override;

    std::istream& input(std::istream& in) override;
    std::ostream& output(std::ostream& out) const override;

    Figure* clone() const override;
    virtual ~Hexagon();
};