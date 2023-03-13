#include "gtest/gtest.h"
#include "VectorSpace.h"

TEST(VectorOperationsTests, VectorAddition) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(0, 0, 0);
    auto vector2 = vectorSpace.CreateVector(1, 0, 0);
    vector1 += vector2;
    ASSERT_TRUE(vector1 == vector2);
}

TEST(VectorOperationsTests, VectorSubstraction) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(2, 0, 0);
    auto vector2 = vectorSpace.CreateVector(1, 0, 0);
    vector1 -= vector2;
    ASSERT_TRUE(vector1 == vector2);
}

TEST(VectorOperationsTests, VectorScalarMultiplication) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(2, 0, 0);
    auto vector2 = vectorSpace.CreateVector(1, 0, 0);
    vector2 *= 2;
    ASSERT_TRUE(vector1 == vector2);
}

TEST(VectorOperationsTests, VectorScalarDivision) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(2, 0, 0);
    auto vector2 = vectorSpace.CreateVector(1, 0, 0);
    vector1 /= 2;
    ASSERT_TRUE(vector1 == vector2);
}

TEST(VectorOperationsTests, VectorVectorMultiplication) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(1, 0, 0);
    auto vector2 = vectorSpace.CreateVector(0, 1, 0);
    auto vector3 = vector1 ^ vector2;
    auto vector4 = vectorSpace.CreateVector(0, 0, 1);
    ASSERT_TRUE(vector4 == vector3);
}

TEST(VectorOperationsTests, VectorVectorScalarMultiplication) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(1, 0, 0);
    auto vector2 = vectorSpace.CreateVector(0, 1, 0);
    auto scalar = vector1 * vector2;
    ASSERT_TRUE(scalar == 0);
}

TEST(VectorOperationsTests, VectorVectorEqualityCheck) {
    VectorSpace vectorSpace;
    auto vector1 = vectorSpace.CreateVector(1, 2, 3);
    auto vector2 = vectorSpace.CreateVector(1, 2, 3);
    auto vector3 = vectorSpace.CreateVector(1, 2, 4);
    ASSERT_TRUE(vector1 == vector2);
    ASSERT_FALSE(vector1 == vector3);
    vector3 -= vectorSpace.CreateVector(0, 0, 1);
    ASSERT_TRUE(vector1 == vector3);
}
