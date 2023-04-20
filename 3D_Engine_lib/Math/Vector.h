//
// Created by ultragreed on 4/19/23.
//

#pragma once

#include <array>

#include "BaseMatrix.h"
#include "Matrix.h"

namespace Math {
    template<typename T, int n, int m>
    class BaseMatrix;

    template<typename T, int n, int m>
    class Matrix;

    template<typename T, int n>
    class Vector {
    public:
        Vector() : baseMatrix() {}

        Vector(std::array<T, n> vectorArray) : baseMatrix(vectorArray) {}

        explicit Vector(BaseMatrix<T, n, 1> baseMatrix) : baseMatrix(baseMatrix) {}

        Matrix<T, n, 1> castToMatrix() const;

        T &operator[](int i);

        T operator[](int i) const;

        Vector<T, n> operator+(const Vector<T, n> &other) const;

        Vector<T, n> operator-(const Vector<T, n> &other) const;

        Vector<T, n> operator*(T scalar) const;

        Vector<T, n> operator/(T scalar) const;


        // scalar product
        T operator*(const Vector<T, n> &other) const;

        // vector product
        Vector<T, n> operator&(const Vector<T, n> &other) const;


        Vector<T, n> operator-() const;


//        Vector<T, n> &operator=(const Vector<T, n> &other);
//
//        Vector<T, n> &operator=(Vector<T, n> &&other) noexcept;


        Vector<T, n> &operator+=(const Vector<T, n> &other);

        Vector<T, n> &operator-=(const Vector<T, n> &other);

        Vector<T, n> &operator*=(T scalar);

        Vector<T, n> &operator/=(T scalar);

        Vector<T, n> &operator&=(const Vector<T, n> &other);


        bool operator==(const Vector<T, n> &other) const;


        explicit operator T() const;


        T scalarProduct(const Vector<T, n> &other) const;

        Vector<T, n> vectorProduct(const Vector<T, n> &other) const;

        [[nodiscard]] double length() const;

        [[nodiscard]] double norm(int p) const;

        Vector<T, n> normalize() const;

        BaseMatrix<T, n, 1> getBaseMatrix() const;

    private:
        BaseMatrix<T, n, 1> baseMatrix;
    };


    template<typename T, int n>
    T operator*(T scalar, Vector<T, n>);


    template<typename T, int n, int m>
    T bilinearForm(Matrix<T, n, m> matrix, Vector<T, n> vector1, Vector<T, m> vector2);
}

#include "Vector.tpp"
