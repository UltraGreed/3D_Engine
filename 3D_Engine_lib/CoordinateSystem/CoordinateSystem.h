//
// Created by ultragreed on 4/15/23.
//

#pragma once

#include "Matrix.h"
#include "Point.h"
#include "VectorSpace.h"

#include <array>

namespace CoordinateSystem {
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

#include "CoordinateSystem.tpp"