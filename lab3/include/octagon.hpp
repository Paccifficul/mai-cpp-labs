#pragma once

#include "figure.hpp"

class Octagon : public Figure {
private:
    Coordinate firstPoint;
    Coordinate secondPoint;
    Coordinate thirdPoint;
    Coordinate fourthPoint;
    Coordinate fifthPoint;
    Coordinate sixthPoint;
    Coordinate seventhPoint;
    Coordinate eighthPoint;
public:
    Octagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, 
            double x5, double y5, double x6, double y6, double x7, double y7, double x8, double y8);
    Octagon(Coordinate c1, Coordinate c2, Coordinate c3, Coordinate c4, Coordinate c5, Coordinate c6, Coordinate c7, Coordinate c8);
    Octagon(const Octagon& other);

    Coordinate getGeometricalCenter() const override;
    double getFigureArea() const override;

    operator double() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) override;

    bool operator==(const Figure& other) override;

    std::istream& input(std::istream& in) override;
    std::ostream& output(std::ostream& out) const override;

    Figure* clone() const override;
    virtual ~Octagon();
};