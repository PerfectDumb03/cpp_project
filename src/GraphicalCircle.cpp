//
// Created by lucan on 02.07.2025.
//

#include "../include/GraphicalCircle.h"
#include <opencv2/imgproc.hpp>


GraphicalCircle::GraphicalCircle(int x, int y, int radius, int thickness, std::array<int, 3> color)
    : ShapeCircle(x, y, radius, thickness, color){
}
GraphicalCircle::GraphicalCircle(ShapeCircle& circle, int thickness, std::array<int, 3> color)
    :ShapeCircle(circle.getX(), circle.getY(), circle.getRadius(), thickness, color){}


void GraphicalCircle::draw(cv::Mat &frame) {
    cv::circle(frame, getCenter(), getRadius(), getColor(), getThickness());
}

