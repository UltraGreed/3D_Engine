#include "VectorSpace.h"
#include <stdexcept>
#include <cmath>

VectorSpace::Point3::Point3(VectorSpace &VS, BaseMetricType c1, BaseMetricType c2, BaseMetricType c3)
        : vectorSpace(VS),
          coordinate1(c1),
          coordinate2(c2),
          coordinate3(c3) {}

VectorSpace::Point3 VectorSpace::Point3::operator+(VectorSpace::Point3 &other) {
    return {
            this->vectorSpace,
            this->coordinate1 + other.coordinate1,
            this->coordinate2 + other.coordinate2,
            this->coordinate3 + other.coordinate3
    };
}

VectorSpace::Point3 VectorSpace::Point3::operator-(VectorSpace::Point3 &other) {
    return {
            this->vectorSpace,
            this->coordinate1 - other.coordinate1,
            this->coordinate2 - other.coordinate2,
            this->coordinate3 - other.coordinate3
    };
}

VectorSpace::Point3 VectorSpace::Point3::operator*(BaseMetricType scalar) {
    return {
            this->vectorSpace,
            this->coordinate1 * scalar,
            this->coordinate2 * scalar,
            this->coordinate3 * scalar
    };
}

VectorSpace::Point3 VectorSpace::Point3::operator/(BaseMetricType scalar) {
    return {
            this->vectorSpace,
            this->coordinate1 / scalar,
            this->coordinate2 / scalar,
            this->coordinate3 / scalar
    };
}

bool VectorSpace::Point3::operator==(VectorSpace::Point3 &other) const {
    return (this->coordinate1 == other.coordinate1 && this->coordinate2 == other.coordinate2 &&
            this->coordinate3 == other.coordinate3);
}

VectorSpace::Vector3::Vector3(VectorSpace &VS, BaseMetricType c1, BaseMetricType c2, BaseMetricType c3)
        : vectorSpace(VS),
          coordinate1(c1),
          coordinate2(c2),
          coordinate3(c3) {}

VectorSpace::Vector3::Vector3(VectorSpace &VS, VectorSpace::Point3 &coordinatePoint)
        : vectorSpace(VS),
          coordinate1(coordinatePoint.coordinate1),
          coordinate2(coordinatePoint.coordinate2),
          coordinate3(coordinatePoint.coordinate3) {}

VectorSpace::Vector3 VectorSpace::Vector3::operator+(const VectorSpace::Vector3 &other) const {
    return {
            this->vectorSpace,
            this->coordinate1 + other.coordinate1,
            this->coordinate2 + other.coordinate2,
            this->coordinate3 + other.coordinate3
    };
}

VectorSpace::Vector3 VectorSpace::Vector3::operator-(const VectorSpace::Vector3 &other) const {
    return {
            this->vectorSpace,
            this->coordinate1 - other.coordinate1,
            this->coordinate2 - other.coordinate2,
            this->coordinate3 - other.coordinate3
    };
}

VectorSpace::Vector3 VectorSpace::Vector3::operator*(BaseMetricType scalar) const {
    return {
            this->vectorSpace,
            this->coordinate1 * scalar,
            this->coordinate2 * scalar,
            this->coordinate3 * scalar
    };
}

VectorSpace::Vector3 VectorSpace::Vector3::operator/(BaseMetricType scalar) const {
    return {
            this->vectorSpace,
            this->coordinate1 / scalar,
            this->coordinate2 / scalar,
            this->coordinate3 / scalar
    };
}

BaseMetricType VectorSpace::Vector3::operator*(const Vector3 &other) const {
    return this->coordinate1 * other.coordinate1 + this->coordinate2 * other.coordinate2 +
           this->coordinate3 * other.coordinate3;
}

VectorSpace::Vector3 VectorSpace::Vector3::operator^(const Vector3 &other) const {
    return {
            this->vectorSpace,
            this->coordinate2 * other.coordinate3 - this->coordinate3 * other.coordinate2,
            this->coordinate3 * other.coordinate1 - this->coordinate1 * other.coordinate3,
            this->coordinate1 * other.coordinate2 - this->coordinate2 * other.coordinate1
    };
}

bool VectorSpace::Vector3::operator==(const VectorSpace::Vector3 &other) const {
    return (this->coordinate1 == other.coordinate1 && this->coordinate2 == other.coordinate2 &&
            this->coordinate3 == other.coordinate3);
}

// Explicit copying operation.
// DOES NOT CHANGE VECTOR SPACE REFERENCE.
VectorSpace::Vector3 &VectorSpace::Vector3::operator=(const VectorSpace::Vector3 &other) {
    if (*this == other)
        return *this;

    this->coordinate1 = other.coordinate1;
    this->coordinate2 = other.coordinate2;
    this->coordinate3 = other.coordinate3;

    return *this;
}

VectorSpace::Vector3 &VectorSpace::Vector3::operator+=(const VectorSpace::Vector3 &other) {
    *this = *this + other;
    return *this;
}

VectorSpace::Vector3 &VectorSpace::Vector3::operator-=(const VectorSpace::Vector3 &other) {
    *this = *this - other;
    return *this;
}

VectorSpace::Vector3 &VectorSpace::Vector3::operator*=(BaseMetricType scalar) {
    *this = *this * scalar;
    return *this;
}

VectorSpace::Vector3 &VectorSpace::Vector3::operator/=(BaseMetricType scalar) {
    *this = *this / scalar;
    return *this;
}

VectorSpace::Vector3 &VectorSpace::Vector3::operator^=(const VectorSpace::Vector3 &other) {
    *this = *this ^ other;
    return *this;
}

VectorSpace::Point3 VectorSpace::Vector3::GetCoordinatePoint() {
    return {
            this->vectorSpace,
            this->coordinate1,
            this->coordinate2,
            this->coordinate3
    };
}

BaseMetricType VectorSpace::Vector3::Length() {
    return vectorSpace.PointDistance(vectorSpace.GetInitialPoint(), this->GetCoordinatePoint());
}

BaseMetricType VectorSpace::PointDistance(const Point3 &first, const Point3 &second) {
    if (this->metric == Metric::Euclidean)
        return std::sqrt(std::pow(second.coordinate1 - first.coordinate1, BaseMetricType(2)) +
                         std::pow(second.coordinate2 - first.coordinate2, BaseMetricType(2)) +
                         std::pow(second.coordinate3 - first.coordinate3, BaseMetricType(2)));
    else if (this->metric == Metric::Manhattan)
        return std::abs(second.coordinate1 - first.coordinate1) +
               std::abs(second.coordinate2 - first.coordinate2) +
               std::abs(second.coordinate3 - first.coordinate3);
    else
        throw std::runtime_error(
                std::string("Following metric point distance not implemented: ") + typeid(metric).name());

}

VectorSpace::VectorSpace()
        : initialPoint(*this, 0, 0, 0),
          direction1(*this, 1, 0, 0),
          direction2(*this, 0, 1, 0),
          direction3(*this, 0, 0, 1),
          metric(Metric::Euclidean) {}

VectorSpace::VectorSpace(Vector3 dir1, Vector3 dir2, Vector3 dir3, Metric metric = Metric::Euclidean)
        : initialPoint(*this, 0, 0, 0),
          direction1(dir1 / dir1.Length()),
          direction2(dir2 / dir2.Length()),
          direction3(dir3 / dir3.Length()),
          metric(metric) {}

VectorSpace::VectorSpace(const Point3 point3, Vector3 dir1, Vector3 dir2, Vector3 dir3,
                         Metric metric = Metric::Euclidean)
        : initialPoint(point3),
          direction1(dir1 / dir1.Length()),
          direction2(dir2 / dir2.Length()),
          direction3(dir3 / dir3.Length()),
          metric(metric) {}


VectorSpace::Point3
VectorSpace::CreatePoint(BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3) {
    return {*this, coordinate1, coordinate2, coordinate3};
}

VectorSpace::Vector3
VectorSpace::CreateVector(BaseMetricType coordinate1, BaseMetricType coordinate2, BaseMetricType coordinate3) {
    return {*this, coordinate1, coordinate2, coordinate3};
}

VectorSpace::Vector3 VectorSpace::CreateVector(VectorSpace::Point3 point3) {
    return {*this, point3};
}

VectorSpace::Point3 &VectorSpace::GetInitialPoint() {
    return this->initialPoint;
}
