//
// Created by ultragreed on 3/13/23.
//

#include "Objects.h"

Object::Object(VectorSpace &vectorSpace, VectorSpace::Point3 position, VectorSpace::Vector3 direction)
        : vectorSpace(vectorSpace),
          position(position),
          direction(direction) {}


Sphere::Sphere(VectorSpace &vectorSpace, VectorSpace::Point3 center, BaseMetricType radius)
        : Object(vectorSpace, center, vectorSpace.CreateVector(0, 0, 0)),
          radius(radius) {}

bool Sphere::Contains(VectorSpace::Point3 point) {
    return this->vectorSpace.PointDistance(point, this->position) <= this->radius;
}
