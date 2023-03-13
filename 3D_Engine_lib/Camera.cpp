//
// Created by ultragreed on 3/12/23.
//

#include "Camera.h"
#include <cmath>

Camera::Camera(VectorSpace::Point3 position, VectorSpace::Vector3 lookDirection, BaseAngleType fieldOfViewDegrees,
               BaseMetricType drawDistance) :
        position(position),
        lookDirection(lookDirection),
        fieldOfViewRadians(fieldOfViewDegrees * float(M_PI) / 180),
        drawDistance(drawDistance) {}

void Camera::SendRays(int n) {
    //TODO: Ray casting in N screen cells
}



