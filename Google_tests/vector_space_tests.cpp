//
// Created by ultragreed on 4/21/23.
//

#include "gtest/gtest.h"

#include "VectorSpace.h"
#include "Point.h"

TEST(VectorSpaceTests, VectorSpaceCreate) {
    CoordinateSystem::VectorSpace<int, 3> vectorSpace({{{1, 0, 0},
                                                        {0, 1, 0},
                                                        {0, 0, 1}}});
}

TEST(VectorSpaceTests, VectorSpaceCreate2) {
    std::array<Math::Vector<int, 3>, 3> basis = {{
                                                         {{1, 0, 0}},
                                                         {{0, 1, 0}},
                                                         {{0, 0, 1}}
                                                 }};
    CoordinateSystem::VectorSpace<int, 3> vectorSpace(basis);
}


TEST(VectorSpaceTests, VectorSpaceScalarProduct) {
    CoordinateSystem::VectorSpace<int, 3> vectorSpace({{{1, 0, 0},
                                                        {0, 1, 0},
                                                        {0, 0, 1}}});

    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({4, 5, 6});

    EXPECT_EQ(vectorSpace.scalarProduct(vector1, vector2), 32);
}

TEST(VectorSpaceTests, VectorSpaceCastPointToVector) {
    CoordinateSystem::VectorSpace<int, 3> vectorSpace({{{1, 0, 0},
                                                        {0, 1, 0},
                                                        {0, 0, 1}}});
    CoordinateSystem::Point<int, 3> point({1, 2, 3});
    Math::Vector<int, 3> expected({1, 2, 3});

    EXPECT_EQ(vectorSpace.castPointToVector(point), expected);
}

