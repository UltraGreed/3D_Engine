//
// Created by ultragreed on 3/12/23.
//

#include "CoordinateSystem.h"
#include "Matrix.h"
#include <cmath>


#ifndef INC_3D_ENGINE_CAMERA_H
#define INC_3D_ENGINE_CAMERA_H

template<typename MetricType, typename AngleType, int dimension>
class Camera {
public:
    Camera(CoordinateSystem::Point<MetricType, dimension> position,
           Math::Vector<MetricType, dimension> lookDir,
           AngleType fieldOfViewDegrees,
           MetricType drawDistance) :
            position(position),
            lookDirection(lookDirection),
            fieldOfViewRadians(fieldOfViewDegrees * float(M_PI) / 180),
            drawDistance(drawDistance) {}

private:
    CoordinateSystem::Point<MetricType, dimension> position;
    Math::Vector<MetricType, dimension> lookDirection;
    AngleType fieldOfViewRadians;
    MetricType drawDistance;

    void SendRays(int n);
};

#endif //INC_3D_ENGINE_CAMERA_H
