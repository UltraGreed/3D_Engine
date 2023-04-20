//
// Created by ultragreed on 4/15/23.
//

#pragma once


namespace Math {
    // BaseMatrix class methods implementation
    template<typename T, int n, int m>
    T &BaseMatrix<T, n, m>::operator[](int i, int j) {
        return matrixArray[i][j];
    }

    template<typename T, int n, int m>
    T BaseMatrix<T, n, m>::operator[](int i, int j) const {
        return matrixArray[i][j];
    }


    template<typename T, int n, int m>
    BaseMatrix<T, n, m> BaseMatrix<T, n, m>::operator+(const BaseMatrix<T, n, m> &other) const {
        BaseMatrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                resultMatrix[i, j] = (*this)[i, j] + other[i, j];

        return resultMatrix;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> BaseMatrix<T, n, m>::operator-(const BaseMatrix<T, n, m> &other) const {
        BaseMatrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                resultMatrix[i, j] = (*this)[i, j] - other[i, j];

        return resultMatrix;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> BaseMatrix<T, n, m>::operator*(T scalar) const {
        BaseMatrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                resultMatrix[i, j] = (*this)[i, j] * scalar;

        return resultMatrix;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> operator*(T scalar, const BaseMatrix<T, n, m> &matrix) {
        return matrix * scalar;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> BaseMatrix<T, n, m>::operator/(T scalar) const {
        BaseMatrix<T, n, m> resultMatrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                resultMatrix[i, j] = (*this)[i, j] / scalar;

        return resultMatrix;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> BaseMatrix<T, n, m>::operator-() const {
        return *this * -1;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> &BaseMatrix<T, n, m>::operator+=(const BaseMatrix<T, n, m> &other) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i, j] += other[i, j];

        return *this;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> &BaseMatrix<T, n, m>::operator-=(const BaseMatrix<T, n, m> &other) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i, j] -= other[i, j];

        return *this;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m> &BaseMatrix<T, n, m>::operator*=(T scalar) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i, j] *= scalar;

        return *this;
    }


    template<typename T, int n, int m>
    BaseMatrix<T, n, m> &BaseMatrix<T, n, m>::operator/=(T scalar) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                (*this)[i, j] /= scalar;

        return *this;
    }


    template<typename T, int n, int m>
    bool BaseMatrix<T, n, m>::operator==(const BaseMatrix<T, n, m> &other) const {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((*this)[i, j] != other[i, j])
                    return false;

        return true;
    }

    template<typename T, int n, int m>
    BaseMatrix<T, n, m>::operator T() const {
        return (*this)[0, 0];
    }
} // Math