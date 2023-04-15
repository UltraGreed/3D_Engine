//
// Created by ultragreed on 4/15/23.
//
#include "CoordinateSystem.h"


namespace CoordinateSystem {
    template<typename T, int n>
    Point<T, n> CoordinateSystem<T, n>::getStartPoint() const {
        return startPoint;
    }
}
