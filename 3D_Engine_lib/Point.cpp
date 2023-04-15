//
// Created by ultragreed on 4/15/23.
//

#include "CoordinateSystem.h"
#include "MatrixBased.h"

namespace CoordinateSystem {
    template<typename T, int n>
    Point<T, n> Point<T, n>::operator+(const Math::Vector<T, n> &other) const {
        return Point<T, n>(this->baseMatrix + other.getBaseMatrix());
    }

    template<typename T, int n>
    Point<T, n> Point<T, n>::operator-(const Math::Vector<T, n> &other) const {
        return Point<T, n>(this->baseMatrix - other.getBaseMatrix());
    }

    template<typename T, int n>
    T Point<T, n>::operator[](int i) const {
        return this->baseMatrix[i, 0];
    }
}