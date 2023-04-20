//
// Created by ultragreed on 4/13/23.
//

#pragma once

#include <cmath>

namespace Math {
    // Matrix class methods implementation
    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::identity() {
        static_assert(n == m, "Identity matrix must be square");

        Matrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            resultMatrix[i, i] = 1;

        return resultMatrix;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::zero() {
        static_assert(n == m, "Zero matrix must be square");

        return Matrix<T, n, m>();
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::gram(std::array<Vector<T, m>, n> vectors) {
        Matrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                resultMatrix[i, j] = vectors[i] * vectors[j];

        return resultMatrix;
    }

    template<typename T, int n, int m>
    Matrix<T, 2, 2> Matrix<T, n, m>::rotation(T angle) {
        static_assert(n == m, "Rotation matrix must be squared");
        static_assert(n == 2 || n == 3, "Rotation matrix must be 2x2 or 3x3");
        static_assert(n == 2, "Rotation matrix without axis specification must be 2x2");

        T radAngle = angle * M_PI / 180;

        return Matrix<T, 2, 2>(
                {{{std::cos(radAngle), -std::sin(radAngle)},
                  {std::sin(radAngle), std::cos(radAngle)}}}
        );
    }

    template<typename T, int n, int m>
    Matrix<T, 3, 3> Matrix<T, n, m>::rotation(T angle, RotationAxis axis) {
        static_assert(n == m, "Rotation matrix must be squared");
        static_assert(n == 2 || n == 3, "Rotation matrix must be 2x2 or 3x3");
        static_assert(n == 3, "Rotation matrix with axis specification must be 3x3");

        T radAngle = angle * M_PI / 180;

        if (axis == RotationAxis::X)
            return Matrix<T, 3, 3>(
                    {{{1, 0, 0},
                      {0, std::cos(radAngle), -std::sin(radAngle)},
                      {0, std::sin(radAngle), std::cos(radAngle)}}}
            );
        else if (axis == RotationAxis::Y)
            return Matrix<T, 3, 3>(
                    {{{std::cos(radAngle), 0, std::sin(radAngle)},
                      {0, 1, 0},
                      {-std::sin(radAngle), 0, std::cos(radAngle)}}}
            );
        else if (axis == RotationAxis::Z)
            return Matrix<T, 3, 3>(
                    {{{std::cos(radAngle), -std::sin(radAngle), 0},
                      {std::sin(radAngle), std::cos(radAngle), 0},
                      {0, 0, 1}}}
            );

    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::TeitBrayan(std::array<T, 3> angles) {
        static_assert(n == m, "Teit-Brayan matrix must be squared");
        static_assert(n == 3, "Teit-Brayan matrix must be 3x3");

        return Matrix<T, 3, 3>::rotation(angles[0], RotationAxis::X) *
               Matrix<T, 3, 3>::rotation(angles[1], RotationAxis::Y) *
               Matrix<T, 3, 3>::rotation(angles[2], RotationAxis::Z);
    }


    template<typename T, int n, int m>
    T &Matrix<T, n, m>::operator[](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            throw std::out_of_range("Matrix index out of range");

        return baseMatrix[i, j];
    }

    template<typename T, int n, int m>
    T Matrix<T, n, m>::operator[](int i, int j) const {
        if (i < 0 || i >= n || j < 0 || j >= m)
            throw std::out_of_range("Matrix index out of range");

        return baseMatrix[i, j];
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator+(const Matrix<T, n, m> &other) const {
        return Matrix<T, n, m>(baseMatrix + other.getBaseMatrix());
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator-(const Matrix<T, n, m> &other) const {
        return Matrix<T, n, m>(baseMatrix - other.getBaseMatrix());
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator*(T scalar) const {
        return Matrix<T, n, m>(baseMatrix * scalar);
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator/(T scalar) const {
        return Matrix<T, n, m>(baseMatrix / scalar);
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator-() const {
        return Matrix<T, n, m>(-baseMatrix);
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::operator~() const {
        return this->inverse();
    }

    template<typename T, int n, int m>
    template<int k>
    Matrix<T, n, k> Matrix<T, n, m>::operator*(const Matrix<T, m, k> &other) const {
        Matrix<T, n, k> result;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                for (int l = 0; l < m; l++)
                    result[i, j] += (*this)[i, l] * other[l, j];

        return result;
    }

//    template<typename T, int n, int m>
//    Matrix<T, n, m> &Matrix<T, n, m>::operator=(const Matrix<T, n, m> &other) {
//        this->baseMatrix = other.getBaseMatrix();
//        return *this;
//    }
//
//    template<typename T, int n, int m>
//    Matrix<T, n, m> &Matrix<T, n, m>::operator=(Matrix<T, n, m> &&other) noexcept {
//        this->baseMatrix = other.getBaseMatrix();
//        return *this;
//    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator+=(const Matrix<T, n, m> &other) {
        this->baseMatrix += other.getBaseMatrix();
        return *this;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator-=(const Matrix<T, n, m> &other) {
        this->baseMatrix -= other.getBaseMatrix();
        return *this;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator*=(T scalar) {
        this->baseMatrix *= scalar;
        return *this;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator/=(T scalar) {
        this->baseMatrix /= scalar;
        return *this;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator*=(const Matrix<T, n, m> &other) {
        static_assert(n == m, "Matrix must be square");

        *this = *this * other;
        return *this;
    }

    template<typename T, int n, int m>
    bool Matrix<T, n, m>::operator==(const Matrix<T, n, m> &other) const {
        return this->baseMatrix == other.getBaseMatrix();
    }

    template<typename T, int n, int m>
    Matrix<T, n, m>::operator T() const {
        static_assert(n == 1 && m == 1, "Matrix can be casted to scalar only if it is 1x1");

        return (*this)[0, 0];
    }


    template<typename T, int n, int m>
    Matrix<T, m, n> Matrix<T, n, m>::transpose() const {
        Matrix<T, m, n> result;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result[j, i] = (*this)[i, j];

        return result;
    }

    template<typename T, int n, int m>
    T Matrix<T, n, m>::determinant() const {
        static_assert(n == m, "Matrix must be square");

        return Math::determinant(*this);
    }


    template<typename T>
    T determinant(const Matrix<T, 1, 1> minor) {
        return minor[0, 0];
    }

    template<typename T>
    T determinant(const Matrix<T, 2, 2> minor) {
        return minor[0, 0] * minor[1, 1] - minor[0, 1] * minor[1, 0];
    }

    template<typename T, int n, int m>
    T determinant(const Matrix<T, n, m> minor) {
        static_assert(n == m, "Matrix must be square");

        T result = 0;
        for (int i = 0; i < n; i++) {
            Matrix<T, n - 1, n - 1> newMinor;
            for (int j = 0; j < n - 1; j++)
                for (int k = 0; k < n; k++)
                    if (k < i)
                        newMinor[j, k] = minor[j + 1, k];
                    else if (k > i)
                        newMinor[j, k - 1] = minor[j + 1, k];

            result += minor[0, i] * Math::determinant(newMinor) * (i % 2 == 0 ? 1 : -1);
        }
        return result;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::cofactor() const {
        static_assert(n == m, "Matrix must be square");

        Matrix<T, n, m> result;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                Matrix<T, n - 1, m - 1> minor;
                for (int k = 0; k < n; k++)
                    for (int l = 0; l < m; l++)
                        if (k < i && l < j)
                            minor[k, l] = (*this)[k, l];
                        else if (k < i && l > j)
                            minor[k, l - 1] = (*this)[k, l];
                        else if (k > i && l < j)
                            minor[k - 1, l] = (*this)[k, l];
                        else if (k > i && l > j)
                            minor[k - 1, l - 1] = (*this)[k, l];

                result[i, j] = minor.determinant() * ((i + j) % 2 == 0 ? 1 : -1);
            }

        return result;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::inverse() const {
        return cofactor().transpose() / determinant();
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> Matrix<T, n, m>::getBaseMatrix() const {
        return this->baseMatrix;
    }

    template<typename T, int n>
    Vector<T, n> castMatrixToVector(Matrix<T, n, 1> matrix) {
        return Vector<T, n>(matrix.getBaseMatrix());
    }

    template<typename T, int n>
    Vector<T, n> castMatrixToVector(Matrix<T, 1, n> matrix) {
        return Vector<T, n>(matrix.transpose().getBaseMatrix());
    }

}// Math