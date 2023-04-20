//
// Created by ultragreed on 4/15/23.
//

#pragma once

#include <cmath>


namespace Math {
    // Vector class methods implementation
    template<typename T, int n>
    Matrix<T, n, 1> Vector<T, n>::castToMatrix() const {
        return Matrix<T, n, 1>(this->baseMatrix);
    }

    template<typename T, int n>
    T &Vector<T, n>::operator[](int i) {
        return this->baseMatrix[i, 0];
    }

    template<typename T, int n>
    T Vector<T, n>::operator[](int i) const {
        return this->baseMatrix[i, 0];
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator+(const Vector<T, n> &other) const {
        return Vector<T, n>(this->baseMatrix + other.getBaseMatrix());
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator-(const Vector<T, n> &other) const {
        return Vector<T, n>(this->baseMatrix - other.getBaseMatrix());
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator*(const T scalar) const {
        return Vector<T, n>(this->baseMatrix * scalar);
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator/(const T scalar) const {
        return Vector<T, n>(this->baseMatrix / scalar);
    }

// scalar product
    template<typename T, int n>
    T Vector<T, n>::operator*(const Vector<T, n> &other) const {
        return scalarProduct(other);
    }

// vector product
    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator&(const Vector<T, n> &other) const {
        return vectorProduct(other);
    }


    template<typename T, int n>
    Vector<T, n> Vector<T, n>::operator-() const {
        return Vector<T, n>(-this->baseMatrix);
    }


//    template<typename T, int n>
//    Vector<T, n> &Vector<T, n>::operator=(const Vector<T, n> &other) {
//        this->baseMatrix = other.getBaseMatrix();
//        return *this;
//    }
//
//    template<typename T, int n>
//    Vector<T, n> &Vector<T, n>::operator=(Vector<T, n> &&other) noexcept {
//        this->baseMatrix = std::move(other.getBaseMatrix());
//        return *this;
//    }


    template<typename T, int n>
    Vector<T, n> &Vector<T, n>::operator+=(const Vector<T, n> &other) {
        this->baseMatrix += other.getBaseMatrix();
        return *this;
    }

    template<typename T, int n>
    Vector<T, n> &Vector<T, n>::operator-=(const Vector<T, n> &other) {
        this->baseMatrix -= other.getBaseMatrix();
        return *this;
    }

    template<typename T, int n>
    Vector<T, n> &Vector<T, n>::operator*=(const T scalar) {
        this->baseMatrix *= scalar;
        return *this;
    }

    template<typename T, int n>
    Vector<T, n> &Vector<T, n>::operator/=(const T scalar) {
        this->baseMatrix /= scalar;
        return *this;
    }

    template<typename T, int n>
    Vector<T, n> &Vector<T, n>::operator&=(const Vector<T, n> &other) {
        *this = *this & other;
        return *this;
    }


    template<typename T, int n>
    bool Vector<T, n>::operator==(const Vector<T, n> &other) const {
        return this->baseMatrix == other.getBaseMatrix();
    }


    template<typename T, int n>
    Vector<T,n>::operator T() const {
        static_assert(n == 1, "Vector can be casted to scalar only if it has 1 element");

        return T(this->baseMatrix);
    }


    template<typename T, int n>
    T Vector<T, n>::scalarProduct(const Vector<T, n> &other) const {
        T sum = 0;
        for (int i = 0; i < n; i++)
            sum += (*this)[i] * other[i];
        return sum;
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::vectorProduct(const Vector<T, n> &other) const {
        static_assert(n == 3, "Vector product is only defined for 3D vectors");

        T det1 = Matrix<T, 2, 2>(
                {{
                         {(*this)[1], (*this)[2]},
                         {other[1], other[2]}
                 }}
        ).determinant();

        T det2 = Matrix<T, 2, 2>(
                {
                        {{(*this)[0], (*this)[2]},
                         {other[0], other[2]}}
                }
        ).determinant();

        T det3 = Matrix<T, 2, 2>(
                {
                        {{(*this)[0], (*this)[1]},
                         {other[0], other[1]}}
                }
        ).determinant();

        Vector<T, 3> basis1({1, 0, 0});
        Vector<T, 3> basis2({0, 1, 0});
        Vector<T, 3> basis3({0, 0, 1});

        return basis1 * det1 - basis2 * det2 + basis3 * det3;
    }

    template<typename T, int n>
    double Vector<T, n>::length() const {
        return norm(2);
    }

    template<typename T, int n>
    double Vector<T, n>::norm(int p) const {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += std::pow((*this)[i], p);
        return std::pow(sum, 1.0 / p);
    }

    template<typename T, int n>
    Vector<T, n> Vector<T, n>::normalize() const {
        if (length() == 0)
            throw std::invalid_argument("Cannot normalize a zero vector");
        return *this / length();
    }

    template<typename T, int n>
    BaseMatrix<T, n, 1> Vector<T, n>::getBaseMatrix() const {
        return this->baseMatrix;
    }


    template<typename T, int n, int m>
    T bilinearForm(const Matrix<T, n, m> matrix, const Vector<T, n> vector1, const Vector<T, m> vector2) {
        return T(vector1.castToMatrix().transpose() * matrix * vector2.castToMatrix());
    }
}