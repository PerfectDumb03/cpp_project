//
// Created by lucan on 02.07.2025.
//

#include <algorithm>
#include <cmath>
#include "../include/ShapeCircle.h"
#include "../include/ShapeSquare.h"



ShapeCircle::ShapeCircle(int x, int y, int radius, int thickness, std::array<int,3> color)
    :Shape(x, y, thickness, color), m_radius(radius){}

bool ShapeCircle::checkCollision(ShapeSquare &FaceRect) {
    // Find the closest point on the rectangle to the circle's center
    int closestX = std::max(FaceRect.getX(),
                   std::min(m_x, FaceRect.getX() + FaceRect.getWidth()));
    int closestY = std::max(FaceRect.getY(),
                   std::min(m_y, FaceRect.getY() + FaceRect.getHeight()));

    // Calculate the distance between the circle's center and the closest point
    int deltaX = m_x - closestX;
    int deltaY = m_y - closestY;

    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    return distance <= m_radius;
}

int ShapeCircle::getRadius() {
    return m_radius;
}
cv::Point ShapeCircle::getCenter() {
        return {m_x, m_y};
    }


