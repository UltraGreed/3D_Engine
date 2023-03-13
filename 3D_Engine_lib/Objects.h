//
// Created by ultragreed on 3/13/23.
//

#include "VectorSpace.h"
#include "config.h"

#ifndef INC_3D_ENGINE_OBJECTS_H
#define INC_3D_ENGINE_OBJECTS_H


class Object {
public:
    Object(VectorSpace &vectorSpace, VectorSpace::Point3 position, VectorSpace::Vector3 direction);

    virtual bool Contains(VectorSpace::Point3 point) = 0;

protected:
    VectorSpace::Point3 position;
    VectorSpace::Vector3 direction;
    VectorSpace &vectorSpace;
};

class Sphere : protected Object {
public:
    Sphere(VectorSpace &vectorSpace, VectorSpace::Point3 center, BaseMetricType radius);

    bool Contains(VectorSpace::Point3 point) override;

private:
    BaseMetricType radius;
};

#endif //INC_3D_ENGINE_OBJECTS_H
