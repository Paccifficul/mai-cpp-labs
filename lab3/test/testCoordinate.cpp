#include <gtest/gtest.h>
#include "../include/coordinate.hpp"

TEST(CoordinateTest, Initialization) {
    Coordinate point(-7.2, 6.4);
    EXPECT_DOUBLE_EQ(point.getX(), -7.2);
    EXPECT_DOUBLE_EQ(point.getY(), 6.4);
}

TEST(CoordinateTest, Equality) {
    Coordinate p1(0, 4.1);
    Coordinate p2(0, 4.1);
    EXPECT_TRUE(p1 == p2);
}