#include <iostream>
#include "Math/MatrixBased.h"

int main() {
    Math::Matrix<int, 2, 2> expected({{
                                              {6, 8},
                                              {10, 12}
                                      }});
    std::cout << (expected[0, 0]) << std::endl;
    return 0;
}
