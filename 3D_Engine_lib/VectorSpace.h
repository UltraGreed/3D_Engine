//
// Created by ultragreed on 3/10/23.
//

#include "config.h"

#ifndef INC_3D_ENGINE_VECTORSPACE_H
#define INC_3D_ENGINE_VECTORSPACE_H


class VectorSpace {
public:
    class Point3 {
    public:
        BaseMetricType coordinate1, coordinate2, coordinate3;

        Point3 operator+(Point3 &other);

        Point3 operator-(Point3 &other);

        Point3 operator*(BaseMetricType scalar);

        Point3 operator/(BaseMetricType scalar);

        bool operator==(Point3 &other) const;

        friend class VectorSpace;

    private:
        VectorSpace &vectorSpace;

        Point3(VectorSpace &VS, BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3);
    };

    class Vector3 {
    public:
        BaseMetricType coordinate1, coordinate2, coordinate3;

        Vector3 operator+(const Vector3 &other) const;

        Vector3 operator-(const Vector3 &other) const;

        Vector3 operator*(BaseMetricType scalar) const;

        Vector3 operator/(BaseMetricType scalar) const;

        // Scalar multiplication
        BaseMetricType operator*(const Vector3 &other) const;

        // Vector multiplication
        Vector3 operator^(const Vector3 &other) const;

        bool operator==(const Vector3 &other) const;

        Vector3 &operator=(const Vector3 &other);

        Vector3 &operator+=(const Vector3 &other);

        Vector3 &operator-=(const Vector3 &other);

        Vector3 &operator*=(const BaseMetricType scalar);

        Vector3 &operator/=(const BaseMetricType scalar);

        Vector3 &operator^=(const Vector3 &other);

        Point3 GetCoordinatePoint();

        BaseMetricType Length();

        friend class VectorSpace;

    private:
        VectorSpace &vectorSpace;

        Vector3(VectorSpace &VS, BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3);

        Vector3(VectorSpace &VS, Point3 &coordinatePoint);
    };

    enum class Metric {
        Euclidean, Manhattan
    };

    Vector3 direction1, direction2, direction3;

    VectorSpace();

    VectorSpace(Vector3 direction1, Vector3 direction2, Vector3 direction3, Metric metric);

    VectorSpace(Point3 initialPoint, Vector3 direction1, Vector3 direction2, Vector3 direction3, Metric metric);

    BaseMetricType PointDistance(const Point3 &point1, const Point3 &point2);

    Point3 CreatePoint(BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3);

    Vector3 CreateVector(BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3);

    Vector3 CreateVector(Point3 coordinatePoint);

    Point3 &GetInitialPoint();

private:
    Point3 initialPoint;
    Metric metric;
};

#endif //INC_3D_ENGINE_VECTORSPACE_H
