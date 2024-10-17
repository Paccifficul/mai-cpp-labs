#include <gtest/gtest.h>
#include "../include/pentagon.hpp"

TEST(PentagonTest, AreaCalculation) {
    Pentagon penta = Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0);

    EXPECT_DOUBLE_EQ(static_cast<double>(penta), 48);
}

TEST(PentagonTest, GeometricalCenter) {
    Pentagon penta = Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0);

    Coordinate center = penta.getGeometricalCenter();

    EXPECT_DOUBLE_EQ(center.getX(), 0);
    EXPECT_DOUBLE_EQ(center.getY(), -0.4);
}