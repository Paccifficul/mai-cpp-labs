#include <gtest/gtest.h>
#include "../include/Array.hpp"
#include "../include/pentagon.hpp"
#include "../include/Hexagon.hpp"
#include "../include/Octagon.hpp"

TEST(ArrayTest, Initialization) {
    Array arr(3);

    ASSERT_EQ(arr.get(0), nullptr);
    ASSERT_EQ(arr.get(1), nullptr);
    ASSERT_EQ(arr.get(2), nullptr);
}

TEST(ArrayTest, AddAndGet) {
    Array arr(3);

    auto* penta = new Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0);
    auto* octa = new Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1);

    arr.add(penta);
    arr.add(octa);

    EXPECT_EQ(arr.get(0), penta);
    EXPECT_EQ(arr.get(1), octa);
    EXPECT_EQ(arr.get(2), nullptr);
}

TEST(ArrayTest, SumArea) {
    Array arr(3);

    arr.add(new Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0));
    arr.add(new Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73));
    EXPECT_DOUBLE_EQ(arr.getFigureAreaSum(), 54.19);

    arr.add(new Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1));
    EXPECT_DOUBLE_EQ(arr.getFigureAreaSum(), 76.69);
}

TEST(ArrayTest, RemoveElement) {
    Array arr(2);

    auto* hexa = new Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73);
    arr.add(hexa);
    arr.remove(0);

    EXPECT_EQ(arr.get(0), nullptr);
    EXPECT_DOUBLE_EQ(arr.getFigureAreaSum(), 0.0);
}

TEST(ArrayTest, CopyConstructor) {
    Array arr1(2);

    arr1.add(new Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73));
    arr1.add(new Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0));

    Array arr2 = Array(arr1);

    EXPECT_DOUBLE_EQ(arr2.getFigureAreaSum(), arr1.getFigureAreaSum());
    EXPECT_EQ(arr2.get(0)->getGeometricalCenter(), arr1.get(0)->getGeometricalCenter());
    EXPECT_EQ(arr2.get(1)->getGeometricalCenter(), arr1.get(1)->getGeometricalCenter());
}

TEST(ArrayTest, MoveConstructor) {
    Array arr1(2);

    arr1.add(new Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73));
    arr1.add(new Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1));

    Array arr2 = std::move(arr1);

    EXPECT_DOUBLE_EQ(arr2.getFigureAreaSum(), 28.69);
    EXPECT_EQ(arr1.get(0), nullptr);
    EXPECT_EQ(arr1.get(1), nullptr);
}

TEST(ArrayTest, GeometricalCenters) {
    Array arr(2);

    arr.add(new Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73));
    arr.add(new Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1));

    std::ostringstream os;
    arr.getGeometricalCenter(os);
    std::string expected = "(1; 2.47)\n(3; 0.88)\n";

    EXPECT_EQ(os.str(), expected);
}