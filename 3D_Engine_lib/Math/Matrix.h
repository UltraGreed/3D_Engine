//
// Created by ultragreed on 4/13/23.
//

#pragma once

#include <array>

#include "BaseMatrix.h"
#include "Vector.h"

namespace Math {
    enum class RotationAxis {
        X, Y, Z
    };

    template<typename T, int n, int m>
    class BaseMatrix;

    template<typename T, int n>
    class Vector;

    template<typename T, int n, int m>
    class Matrix {
    public:
        Matrix() : baseMatrix() {}

        Matrix(std::array<std::array<T, m>, n> matrixArray) : baseMatrix(matrixArray) {}

        explicit Matrix(BaseMatrix<T, n, m> baseMatrix) : baseMatrix(baseMatrix) {}


        static Matrix<T, n, m> identity();

        static Matrix<T, n, m> zero();

        static Matrix<T, n, m> gram(std::array<Vector<T, m>, n> vectors);

        static Matrix<T, 2, 2> rotation(T angle);

        static Matrix<T, 3, 3> rotation(T angle, RotationAxis axis);

        static Matrix<T, 3, 3> TeitBrayan(std::array<T, 3> angles);

        T &operator[](int i, int j);

        T operator[](int i, int j) const;


        Matrix<T, n, m> operator+(const Matrix<T, n, m> &other) const;

        Matrix<T, n, m> operator-(const Matrix<T, n, m> &other) const;

        Matrix<T, n, m> operator*(T scalar) const;

        Matrix<T, n, m> operator/(T scalar) const;


        template<int k>
        Matrix<T, n, k> operator*(const Matrix<T, m, k> &other) const;


        Matrix<T, n, m> operator-() const;

        Matrix<T, n, m> operator~() const;


//        Matrix<T, n, m> &operator=(const Matrix<T, n, m> &other);
//
//        Matrix<T, n, m> &operator=(Matrix<T, n, m> &&other) noexcept;


        Matrix<T, n, m> &operator+=(const Matrix<T, n, m> &other);

        Matrix<T, n, m> &operator-=(const Matrix<T, n, m> &other);

        Matrix<T, n, m> &operator*=(T scalar);

        Matrix<T, n, m> &operator/=(T scalar);

        Matrix<T, n, m> &operator*=(const Matrix<T, n, m> &other);


        bool operator==(const Matrix<T, n, m> &other) const;


        explicit operator T() const;

        // Calculate determinant of minor starting from startIndex with minorSize size
        T determinant() const;

        Matrix<T, n, m> cofactor() const;

        Matrix<T, n, m> inverse() const;

        Matrix<T, m, n> transpose() const;

        BaseMatrix<T, n, m> getBaseMatrix() const;

    private:

        BaseMatrix<T, n, m> baseMatrix;
    };

    template<typename T>
    static T determinant(Matrix<T, 1, 1> minor);

    template<typename T>
    static T determinant(Matrix<T, 2, 2> minor);

    template<typename T, int n, int m>
    static T determinant(Matrix<T, n, m> minor);

    template<typename T, int n, int m>
    T operator*(T scalar, Matrix<T, n, m>);


    template<typename T, int n>
    Vector<T, n> castMatrixToVector(Matrix<T, n, 1> matrix);

    template<typename T, int n>
    Vector<T, n> castMatrixToVector(Matrix<T, 1, n> matrix);


} // Math

#include "Matrix.tpp"