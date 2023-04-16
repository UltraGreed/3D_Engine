#include "gtest/gtest.h"
#include "Math/MatrixBased.h"

TEST(MatrixOperationsTests, MatrixAddition) {

    Math::Matrix<int, 2, 2> expected({{
                                             {6, 8},
                                             {10, 12}
                                     }});

    ASSERT_TRUE((expected[0, 0] == 6));

}


