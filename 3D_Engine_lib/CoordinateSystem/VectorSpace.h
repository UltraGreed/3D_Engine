//
// Created by ultragreed on 4/19/23.
//

#pragma once

#include "Vector.h"


namespace CoordinateSystem {
    template<typename T, int n>
    class VectorSpace {
    public:
        explicit VectorSpace(std::array<Math::Vector<T, n>, n> basis) : basis(basis) {}

        explicit VectorSpace(std::array<std::array<T, n>, n> basis) {
            for (int i = 0; i < n; i++)
                this->basis[i] = Math::Vector<T, n>(basis[i]);
        }

        T scalarProduct(const Math::Vector<T, n> &vector1, const Math::Vector<T, n> &vector2) const;

        Math::Vector<T, n> castPointToVector(const Point<T, n> &point) const;

    private:
        std::array<Math::Vector<T, n>, n> basis;
    };
}

#include "VectorSpace.tpp"