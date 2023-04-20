//
// Created by ultragreed on 4/19/23.
//
#pragma once

#include <array>

#include "BaseMatrix.h"
#include "Vector.h"


namespace Math {
    template<typename T, int n, int m>
    class BaseMatrix;

    template<typename T, int n>
    class Vector;
}

namespace CoordinateSystem {
    template<typename T, int n>
    class Point {
    public:
        Point() : baseMatrix() {}

        Point(std::array<T, n> pointArray) : baseMatrix(pointArray) {}

        explicit Point(Math::BaseMatrix<T, n, 1> baseMatrix) : baseMatrix(baseMatrix) {}

        T &operator[](int i);

        T operator[](int i) const;

        Point<T, n> operator+(const Math::Vector<T, n> &other) const;

        Point<T, n> operator-(const Math::Vector<T, n> &other) const;

        bool operator==(const Point<T, n> &other) const;

    private:
        Math::BaseMatrix<T, n, 1> baseMatrix;
    };
}

#include "Point.tpp"
