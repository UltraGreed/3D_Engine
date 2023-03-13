//
// Created by ultragreed on 3/12/23.
//

#include "VectorSpace.h"
#include "config.h"

#ifndef INC_3D_ENGINE_CAMERA_H
#define INC_3D_ENGINE_CAMERA_H

class Camera {
public:
    Camera(VectorSpace::Point3 position, VectorSpace::Vector3 lookDir, BaseAngleType fieldOfViewDegrees, BaseMetricType drawDistance);

private:
    VectorSpace::Point3 position;
    VectorSpace::Vector3 lookDirection;
    BaseAngleType fieldOfViewRadians;
    BaseMetricType drawDistance;

    void SendRays(int n);
};

#endif //INC_3D_ENGINE_CAMERA_H
