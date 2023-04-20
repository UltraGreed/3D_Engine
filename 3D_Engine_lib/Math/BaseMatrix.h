//
// Created by ultragreed on 4/19/23.
//

#pragma once


namespace CoordinateSystem {
    template<typename T, int n>
    class Point;
}

namespace Math {
    template<typename T, int n, int m>
    class Matrix;

    template<typename T, int n>
    class Vector;


    template<typename T, int n, int m>
    class BaseMatrix {
        static_assert(n > 0 && m > 0, "Matrix dimensions must be positive");

        friend Matrix<T, n, m>;

        friend Vector<T, n>;

        friend CoordinateSystem::Point<T, n>;

    private:
        BaseMatrix() : matrixArray(std::array<std::array<T, m>, n>()) {}

        explicit BaseMatrix(std::array<std::array<T, m>, n> matrixArray) : matrixArray(matrixArray) {}

        explicit BaseMatrix(std::array<T, n> vectorArray) {
            for (int i = 0; i < n; i++)
                matrixArray[i][0] = vectorArray[i];
        }


        T &operator[](int i, int j);

        T operator[](int i, int j) const;


        BaseMatrix<T, n, m> operator+(const BaseMatrix<T, n, m> &other) const;

        BaseMatrix<T, n, m> operator-(const BaseMatrix<T, n, m> &other) const;

        BaseMatrix<T, n, m> operator*(T scalar) const;

        BaseMatrix<T, n, m> operator/(T scalar) const;


        BaseMatrix<T, n, m> operator-() const;


//        BaseMatrix<T, n, m> &operator=(const BaseMatrix<T, n, m> &other);
//
//        BaseMatrix<T, n, m> &operator=(BaseMatrix<T, n, m> &&other) noexcept;


        BaseMatrix<T, n, m> &operator+=(const BaseMatrix<T, n, m> &other);

        BaseMatrix<T, n, m> &operator-=(const BaseMatrix<T, n, m> &other);

        BaseMatrix<T, n, m> &operator*=(T scalar);

        BaseMatrix<T, n, m> &operator/=(T scalar);


        bool operator==(const BaseMatrix<T, n, m> &other) const;


        explicit operator T() const;


        std::array<std::array<T, m>, n> matrixArray;
    };
}

#include "BaseMatrix.tpp"