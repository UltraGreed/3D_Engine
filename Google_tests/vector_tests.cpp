//
// Created by ultragreed on 4/20/23.
//
#include "gtest/gtest.h"
#include "Vector.h"


TEST(VectorOperationsTests, VectorAddition) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({4, 5, 6});
    Math::Vector<int, 3> vector3({5, 7, 9});

    EXPECT_EQ(vector1 + vector2, vector3);
}

TEST(VectorOperationsTests, VectorSubtraction) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({4, 5, 6});
    Math::Vector<int, 3> vector3({-3, -3, -3});

    EXPECT_EQ(vector1 - vector2, vector3);
}

TEST(VectorOperationsTests, VectorScalarMultiplication) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({2, 4, 6});

    EXPECT_EQ(vector1 * 2, vector2);
}

TEST(VectorOperationsTests, VectorScalarDivision) {
    Math::Vector<float, 3> vector1({1, 2, 3});
    Math::Vector<float, 3> vector2({0.5, 1, 1.5});

    EXPECT_EQ(vector1 / 2, vector2);
}

TEST(VectorOperationsTests, VectorScalarProduct) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({4, 5, 6});
    int expected = 32;

    EXPECT_EQ(vector1 * vector2, expected);
}

TEST(VectorOperationsTests, VectorVectorProduct) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Vector<int, 3> vector2({4, 5, 6});
    Math::Vector<int, 3> expected({-3, 6, -3});

    EXPECT_EQ(vector1 & vector2, expected);
}

TEST(VectorOperationsTests, VectorLength) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    double expected = 3.7416573867739413;

    EXPECT_EQ(vector1.length(), expected);
}

TEST(VectorOperationsTests, VectorNormalize) {
    Math::Vector<double, 3> vector1({1, 2, 3});
    Math::Vector<double, 3> expected({0.2672612419124244, 0.5345224838248488, 0.8017837257372732});

    EXPECT_EQ(vector1.normalize(), expected);
}

TEST(VectorOperationsTests, VectorNormalizeZeroVectorWithException) {
    Math::Vector<double, 3> vector1({0, 0, 0});

    EXPECT_THROW(vector1.normalize(), std::invalid_argument);
}

TEST(VectorOperationsTests, VectorMatrixTranspose) {
    Math::Vector<int, 3> vector1({1, 2, 3});
    Math::Matrix<int, 1, 3> expected({1, 2, 3});

    EXPECT_TRUE((vector1.castToMatrix().transpose() == expected));
}
