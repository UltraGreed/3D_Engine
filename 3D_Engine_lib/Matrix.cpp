//
// Created by ultragreed on 4/13/23.
//

#include "MatrixBased.h"

namespace Math {
    // Matrix class methods implementation
    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::identity() {
        Matrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            resultMatrix[i, i] = 1;

        return resultMatrix;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> Matrix<T, n, m>::zero() {
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
    T Matrix<T, n, m>::operator[](int i, int j) {
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

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator=(const Matrix<T, n, m> &other) {
        this->baseMatrix = other.getBaseMatrix();
        return *this;
    }

    template<typename T, int n, int m>
    Matrix<T, n, m> &Matrix<T, n, m>::operator=(Matrix<T, n, m> &&other) noexcept {
        this->baseMatrix = other.getBaseMatrix();
        return *this;
    }

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
    auto Matrix<T, n, m>::castToVector() const {
        static_assert(n == 1 || m == 1, "Matrix must be a vector");

        if (n == 1) {
            Vector<T, n> result;
            for (int i = 0; i < n; i++)
                result[i] = (*this)[i, 0];
            return result;
        } else if (m == 1) {
            Vector<T, m> result;
            for (int i = 0; i < m; i++)
                result[i] = (*this)[0, i];
            return result;
        }
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

        if (n == 1)
            return (*this)[0, 0];
        else if (n == 2)
            return (*this)[0, 0] * (*this)[1, 1] - (*this)[0, 1] * (*this)[1, 0];
        else {
            T result = 0;
            for (int i = 0; i < n; i++) {
                Matrix<T, n - 1, n - 1> minor;
                for (int j = 1; j < n; j++)
                    for (int k = 0; k < n; k++)
                        if (k < i)
                            minor[j - 1, k] = (*this)[j, k];
                        else if (k > i)
                            minor[j - 1, k - 1] = (*this)[j, k];

                result += (*this)[0, i] * minor.determinant() * (i % 2 == 0 ? 1 : -1);
            }
            return result;
        }
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
}// Math