//
// Created by lucan on 02.07.2025.
//

#include "../include/GraphicalCircle.h"
#include <opencv2/imgproc.hpp>


GraphicalCircle::GraphicalCircle(int x, int y, int radius, int thickness, std::array<int, 3> color)
    : ShapeCircle(x, y, radius), m_thickness(thickness), m_color(color){
}
GraphicalCircle::GraphicalCircle(ShapeCircle& circle, int thickness, std::array<int, 3> color)
    :ShapeCircle(circle.getX(), circle.getY(), circle.getRadius()), m_thickness(thickness), m_color(color){}

int GraphicalCircle::getThickness() {
    return m_thickness;
}
int GraphicalCircle::getY() {
    return m_y;
}
int GraphicalCircle::getRadius(){
    return m_radius;
}
cv::Scalar GraphicalCircle::getColor() { //BGR order
    return {static_cast<double>(m_color[2]),
        static_cast<double>(m_color[1]),
        static_cast<double>(m_color[0])};
}
cv::Point GraphicalCircle::getCenter() {
    return {m_x, m_y};
}

void GraphicalCircle::draw(cv::Mat &frame) {
    cv::circle(frame, getCenter(), getRadius(), getColor(), getThickness());
}

