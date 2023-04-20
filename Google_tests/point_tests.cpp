//
// Created by ultragreed on 4/20/23.
//

#include "gtest/gtest.h"
#include "Point.h"
#include "Vector.h"


TEST(PointOperationsTests, PointVectorAddition) {
    CoordinateSystem::Point<int, 3> point1({1, 2, 3});
    Math::Vector<int, 3> vector1({4, 5, 6});
    CoordinateSystem::Point<int, 3> point2({5, 7, 9});

    EXPECT_TRUE((point1 + vector1 == point2));
}

TEST(PointOperationsTests, PointVectorSubtraction) {
    CoordinateSystem::Point<int, 3> point1({1, 2, 3});
    Math::Vector<int, 3> vector1({4, 5, 6});
    CoordinateSystem::Point<int, 3> point2({-3, -3, -3});

    EXPECT_TRUE((point1 - vector1 == point2));
}

TEST(PointOperationsTests, PointIndexation) {
    CoordinateSystem::Point<int, 3> point1({1, 2, 3});

    EXPECT_EQ(point1[0], 1);
    EXPECT_EQ(point1[1], 2);
    EXPECT_EQ(point1[2], 3);
}

TEST(PointOperationsTests, PointIndexationModify) {
    CoordinateSystem::Point<int, 3> point1({1, 2, 3});

    point1[0] = 4;
    point1[1] = 5;
    point1[2] = 6;

    EXPECT_EQ(point1[0], 4);
    EXPECT_EQ(point1[1], 5);
    EXPECT_EQ(point1[2], 6);
}