//
// Created by ultragreed on 4/13/23.
//

#include <array>

#ifndef INC_3D_ENGINE_MATRIX_H
#define INC_3D_ENGINE_MATRIX_H

namespace Math {
    template<typename T, int n, int m>
    class BaseMatrix;

    template<typename T, int n, int m>
    class Matrix;

    template<typename T, int n>
    class Vector;

    template<typename T, int n>
    class Point;


    template<typename T, int n, int m>
    class BaseMatrix {
        friend Matrix<T, n, m>;

        friend Vector<T, m>;

        auto getMatrixArray() const {
            return matrixArray;
        }

    private:
        BaseMatrix() : matrixArray(std::array<std::array<T, m>, n>()) {}

        explicit BaseMatrix(std::array<std::array<T, m>, n> matrixArray) : matrixArray(matrixArray) {}

        explicit BaseMatrix(std::array<T, m> vectorArray) : matrixArray(std::array<T, n>{vectorArray}) {
            static_assert(n == 1);
        }


        T operator[](int i, int j) const;


        BaseMatrix<T, n, m> operator+(const BaseMatrix<T, n, m> &other) const;

        BaseMatrix<T, n, m> operator-(const BaseMatrix<T, n, m> &other) const;

        T operator*(T scalar) const;

        T operator/(T scalar) const;


        BaseMatrix<T, n, m> operator-() const;


        BaseMatrix<T, n, m> &operator=(const BaseMatrix<T, n, m> &other);

        BaseMatrix<T, n, m> &operator=(BaseMatrix<T, n, m> &&other) noexcept;


        BaseMatrix<T, n, m> &operator+=(const BaseMatrix<T, n, m> &other);

        BaseMatrix<T, n, m> &operator-=(const BaseMatrix<T, n, m> &other);

        BaseMatrix<T, n, m> &operator*=(T scalar);

        BaseMatrix<T, n, m> &operator/=(T scalar);


        bool operator==(const BaseMatrix<T, n, m> &other) const;


        std::array<std::array<T, m>, n> matrixArray;
    };


    template<typename T, int n, int m>
    class Matrix {
    public:
        Matrix() : baseMatrix() {}

        explicit Matrix(std::array<std::array<T, m>, n> matrixArray) : baseMatrix(matrixArray) {}


        static Matrix<T, n, m> identity();

        static Matrix<T, n, m> zero();

        static Matrix<T, n, m> gram(std::array<Vector<T, m>, n> vectors);


        T operator[](int i, int j);


        Matrix<T, n, m> operator+(const Matrix<T, n, m> &other) const;

        Matrix<T, n, m> operator-(const Matrix<T, n, m> &other) const;

        Matrix<T, n, m> operator*(T scalar) const;

        Matrix<T, n, m> operator/(T scalar) const;


        template<int k>
        Matrix<T, n, k> operator*(const Matrix<T, m, k> &other) const;


        Matrix<T, n, m> operator-() const;

        Matrix<T, n, m> operator~() const;


        Matrix<T, n, m> &operator=(const Matrix<T, n, m> &other);

        Matrix<T, n, m> &operator=(Matrix<T, n, m> &&other) noexcept;


        Matrix<T, n, m> &operator+=(const Matrix<T, n, m> &other);

        Matrix<T, n, m> &operator-=(const Matrix<T, n, m> &other);

        Matrix<T, n, m> &operator*=(T scalar);

        Matrix<T, n, m> &operator/=(T scalar);

        Matrix<T, n, m> &operator*=(const Matrix<T, n, m> &other);


        bool operator==(const Matrix<T, n, m> &other) const;


        auto castToVector() const;

        T determinant() const;

        Matrix<T, n, m> cofactor() const;

        Matrix<T, n, m> inverse() const;

        Matrix<T, m, n> transpose() const;

        BaseMatrix<T, n, m> getBaseMatrix() const;

    private:
        BaseMatrix<T, n, m> baseMatrix;
    };


    template<typename T, int n, int m>
    T operator*(T scalar, Matrix<T, n, m>);


    template<typename T, int n>
    class Vector {
    public:
        Vector() : baseMatrix() {}

        explicit Vector(std::array<T, n> vectorArray) : baseMatrix(vectorArray) {}

        Matrix<T, n, 1> castToMatrix() const;

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


        Vector<T, n> &operator=(const Vector<T, n> &other);

        Vector<T, n> &operator=(Vector<T, n> &&other) noexcept;


        Vector<T, n> &operator+=(const Vector<T, n> &other);

        Vector<T, n> &operator-=(const Vector<T, n> &other);

        Vector<T, n> &operator*=(T scalar);

        Vector<T, n> &operator/=(T scalar);

        Vector<T, n> &operator&=(const Vector<T, n> &other);


        bool operator==(const Vector<T, n> &other) const;


        T scalarProduct(const Vector<T, n> &other) const;

        Vector<T, n> vectorProduct(const Vector<T, n> &other) const;

        T length() const;

        T norm(int p) const;

        BaseMatrix<T, n, 1> getBaseMatrix() const;

    private:
        BaseMatrix<T, n, 1> baseMatrix;
    };

    template<typename T, int n>
    T operator*(T scalar, Vector<T, n>);


    template<typename T, int n, int m>
    T bilinearForm(Matrix<T, n, m> matrix, Vector<T, n> vector1, Vector<T, m> vector2);


} // Math

#endif //INC_3D_ENGINE_MATRIX_H
