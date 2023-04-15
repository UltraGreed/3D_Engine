//
// Created by ultragreed on 4/15/23.
//
#include "MatrixBased.h"
#include <array>

#ifndef INC_3D_ENGINE_VECTORSPACE_H
#define INC_3D_ENGINE_VECTORSPACE_H


namespace CoordinateSystem {
    template<typename T, int n>
    class Point {
    public:
        Point() : baseMatrix() {}

        explicit Point(std::array<T, n> pointArray) : baseMatrix(pointArray) {}

        Point<T, n> operator+(const Math::Vector<T, n> &other) const;

        Point<T, n> operator-(const Math::Vector<T, n> &other) const;

        T operator[](int i) const;

    private:
        Math::BaseMatrix<T, n, 1> baseMatrix;
    };

    template<typename T, int n>
    class VectorSpace {
    public:
        explicit VectorSpace(std::array<Math::Vector<T, n>, n> basis) : basis(basis) {}

        T scalarProduct(const Math::Vector<T, n> &vector1, const Math::Vector<T, n> &vector2) const;

        Math::Vector<T, n> castPointToVector(const Point<T, n> &point) const;

    private:
        std::array<Math::Vector<T, n>, n> basis;
    };

    template<typename T, int n>
    class CoordinateSystem {
    public:
        CoordinateSystem(VectorSpace<T, n> vectorSpace, Point<T, n> startPoint) :
                vectorSpace(vectorSpace),
                startPoint(startPoint) {}

        Point<T, n> getStartPoint() const;

    private:
        VectorSpace<T, n> vectorSpace;
        Point<T, n> startPoint;
    };
}
#endif //INC_3D_ENGINE_VECTORSPACE_H
