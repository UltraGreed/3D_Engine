//
// Created by ultragreed on 4/15/23.
//

#include "Matrix.h"


namespace CoordinateSystem {
    template<typename T, int n>
    T VectorSpace<T, n>::scalarProduct(const Math::Vector<T, n> &vector1, const Math::Vector<T, n> &vector2) const {
        return Math::bilinearForm(Math::Matrix<T, n, n>::gram(this->basis), vector1, vector2);
    }

    template<typename T, int n>
    Math::Vector<T, n> VectorSpace<T, n>::castPointToVector(const Point<T, n> &point) const {
        Math::Vector<T, n> result;
        for (int i = 0; i < n; i++)
            result += this->basis[i] * point[i];
        return result;
    }
}