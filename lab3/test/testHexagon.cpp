#include <gtest/gtest.h>
#include "../include/hexagon.hpp"

TEST(HexagonText, AreaCalculation) {
    Hexagon hexa = Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73);

    EXPECT_DOUBLE_EQ(static_cast<double>(hexa), 6.19);
}

TEST(HexagonTest, GeometricalCenter) {
    Hexagon hexa = Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73);

    Coordinate center = hexa.getGeometricalCenter();

    EXPECT_DOUBLE_EQ(center.getX(), 1);
    EXPECT_DOUBLE_EQ(center.getY(), 2.47);
}