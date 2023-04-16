#include <iostream>
#include "Math/MatrixBased.h"

int main() {
    Math::Matrix<int, 2, 2> matrix1({{
                                            {1, 2},
                                            {3, 4}
                                    }});
    Math::Matrix<int, 2, 2> matrix2({{
                                           {5, 6},
                                           {7, 8}
                                      }});
    Math::Matrix<int, 2, 2> result = matrix1 + matrix2;
    Math::Matrix<int, 2, 2> expected({{
                                             {6, 8},
                                             {10, 12}
                                     }});
    std::cout << (result == expected) << std::endl;
    return 0;
}
