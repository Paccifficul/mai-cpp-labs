#include <gtest/gtest.h>
#include "../include/octagon.hpp"

TEST(OctagonTest, AreaCalculation) {
    Octagon octa = Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1);

    EXPECT_DOUBLE_EQ(static_cast<double>(octa), 22.5);
}

TEST(OctagonTest, GeometricalCenter) {
    Octagon octa = Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1);

    Coordinate center = octa.getGeometricalCenter();

    EXPECT_DOUBLE_EQ(center.getX(), 3);
    EXPECT_DOUBLE_EQ(center.getY(), 0.88);
}