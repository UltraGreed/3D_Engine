//
// Created by ultragreed on 4/21/23.
//
#include "gtest/gtest.h"

#include "CoordinateSystem.h"

TEST(CoordinateSystemTests, CoordinateSystemCreation) {
    CoordinateSystem::VectorSpace<int, 3> vectorSpace({{{1, 0, 0},
                                                        {0, 1, 0},
                                                        {0, 0, 1}}});
    CoordinateSystem::Point<int, 3> startPoint({0, 0, 0});

    CoordinateSystem::CoordinateSystem<int, 3> coordinateSystem(vectorSpace, startPoint);

    EXPECT_TRUE(coordinateSystem.getStartPoint() == startPoint);
}
