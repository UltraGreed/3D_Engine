#include "gtest/gtest.h"
#include "Matrix.h"


TEST(MatrixOperationsTests, MatrixAddition) {
    Math::Matrix<int, 2, 2> first({{
                                           {1, 2},
                                           {3, 4}
                                   }});

    Math::Matrix<int, 2, 2> second({{
                                            {5, 6},
                                            {7, 8}
                                    }});

    Math::Matrix<int, 2, 2> expected({{
                                              {6, 8},
                                              {10, 12}
                                      }});

    ASSERT_TRUE((first + second == expected));
}

TEST(MatrixOperationsTests, MatrixSubtraction) {
    Math::Matrix<int, 2, 2> first({{
                                           {1, 2},
                                           {3, 4}
                                   }});

    Math::Matrix<int, 2, 2> second({{
                                            {5, 6},
                                            {7, 8}
                                    }});

    Math::Matrix<int, 2, 2> expected({{
                                              {-4, -4},
                                              {-4, -4}
                                      }});

    ASSERT_TRUE((first - second == expected));
}

TEST(MatrixOperationsTests, MatrixScalarMultiplication) {
    Math::Matrix<int, 2, 2> first({{
                                           {1, 2},
                                           {3, 4}
                                   }});

    Math::Matrix<int, 2, 2> expected({{
                                              {2, 4},
                                              {6, 8}
                                      }});

    ASSERT_TRUE((first * 2 == expected));
}

TEST(MatrixOperationsTests, MatrixScalarDivision) {
    Math::Matrix<int, 2, 2> first({{
                                           {1, 2},
                                           {3, 4}
                                   }});

    Math::Matrix<int, 2, 2> expected({{
                                              {0, 1},
                                              {1, 2}
                                      }});

    ASSERT_TRUE((first / 2 == expected));
}

TEST(MatrixOperationsTests, MatrixMultiplication) {
    Math::Matrix<int, 2, 2> first({{
                                           {1, 2},
                                           {3, 4}
                                   }});

    Math::Matrix<int, 2, 2> second({{
                                            {5, 6},
                                            {7, 8}
                                    }});

    Math::Matrix<int, 2, 2> expected({{
                                              {19, 22},
                                              {43, 50}
                                      }});

    ASSERT_TRUE((first * second == expected));
}

TEST(MatrixOperationsTests, MatrixCofactor) {
    Math::Matrix<float, 2, 2> origin({{
                                              {1, 2},
                                              {3, 4}
                                      }});

    Math::Matrix<float, 2, 2> expected({{
                                                {4, -3},
                                                {-2, 1}
                                        }});

    ASSERT_TRUE((origin.cofactor() == expected));
}


TEST(MatrixOperationsTests, MatrixDeterminant1) {
    Math::Matrix<float, 1, 1> origin({1});

    ASSERT_TRUE((origin.determinant() == origin[0, 0]));
}

TEST(MatrixOperationsTests, MatrixDeterminant2) {
    Math::Matrix<float, 2, 2> origin({{
                                              {1, 2},
                                              {3, 4}
                                      }});

    ASSERT_TRUE(origin.determinant() == -2);
}

TEST(MatrixOperationsTests, MatrixDeterminant3) {
    Math::Matrix<float, 3, 3> origin({{
                                              {1, 2, 5},
                                              {4, 5, 6},
                                              {7, 8, 9}
                                      }});

    ASSERT_TRUE(origin.determinant() == -6);
}

TEST(MatrixOperationsTests, MatrixInversion) {
    Math::Matrix<float, 2, 2> origin({{
                                              {1, 2},
                                              {3, 4}
                                      }});

    Math::Matrix<float, 2, 2> expected({{
                                                {-2, 1},
                                                {1.5, -0.5}
                                        }});

    ASSERT_TRUE((origin.inverse() == expected));
}

TEST(MatrixOperationsTests, MatrixTranspose) {
    Math::Matrix<int, 2, 2> origin({{
                                            {6, 8},
                                            {10, 12}
                                    }});

    Math::Matrix<int, 2, 2> expected({{
                                              {6, 10},
                                              {8, 12}
                                      }});

    ASSERT_TRUE((origin.transpose() == expected));
}

TEST(MatrixOperationsTests, MatrixIdentity) {
    Math::Matrix<int, 2, 2> expected({{
                                              {1, 0},
                                              {0, 1}
                                      }});

    ASSERT_TRUE((Math::Matrix<int, 2, 2>::identity() == expected));
}

TEST(MatrixOperationsTests, MatrixZero) {
    Math::Matrix<int, 2, 2> expected({{
                                              {0, 0},
                                              {0, 0}
                                      }});

    ASSERT_TRUE((Math::Matrix<int, 2, 2>::zero() == expected));
}

TEST(MatrixOperationsTests, MatrixCastToVector) {
    Math::Matrix<int, 1, 4> origin({6, 8, 10, 12});

    Math::Vector<int, 4> expected({6, 8, 10, 12});

    ASSERT_TRUE((Math::castMatrixToVector(origin) == expected));
}

TEST(MatrixOperationsTests, MatrixCastToVector2) {
    Math::Matrix<int, 4, 1> origin(
            {
                    {{6},
                     {8},
                     {10},
                     {12}}
            }
    );

    Math::Vector<int, 4> expected({6, 8, 10, 12});

    ASSERT_TRUE((Math::castMatrixToVector(origin) == expected));
}

TEST(MatrixOperationsTests, MatrixRotation2) {
    Math::Matrix<double, 2, 2> expected({{
                                                {0, -1},
                                                {1, 0}
                                        }});

    ASSERT_TRUE((Math::Matrix<double, 2, 2>::rotation(90) - expected).determinant() < 0.0001);
}

TEST(MatrixOperationsTests, MatrixRotation3) {
    Math::Matrix<double, 3, 3> expected({{
                                                {0, 0, 1},
                                                {0, 1, 0},
                                                {-1, 0, 0}
                                        }});

    ASSERT_TRUE((Math::Matrix<double, 3, 3>::rotation(90, Math::RotationAxis::X) - expected).determinant() < 0.0001);
}

TEST(MatrixOperationsTests, MatrixRotationTeitBrayan) {
    Math::Matrix<double, 3, 3> expected({{
                                                {0.7071067811865475, -0.7071067811865475, 0},
                                                {0.7071067811865475, 0.7071067811865475, 0},
                                                {0, 0, 1}
                                        }});
    ASSERT_TRUE((Math::Matrix<double, 3, 3>::TeitBrayan({90, 0, 0}) - expected).determinant() < 0.0001);
}