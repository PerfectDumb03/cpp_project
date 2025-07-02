//
// Created by Luca on 01.07.2025.
//

#include "../include/GraphicalSquare.h"

GraphicalSquare::GraphicalSquare(int x, int y, int height, int width, int thickness, std::array<int, 3> color)
    :ShapeSquare(x, y, height, width), m_thickness(thickness), m_color(color){
    if (m_color[0] == -1) {
        randomizeColor();
    }
}

GraphicalSquare::GraphicalSquare(ShapeSquare &square, int thickness, std::array<int, 3> color)
    :ShapeSquare(square.getX(), square.getY(), square.getHeight(), square.getWidth()), m_thickness(thickness), m_color(color){

}

void GraphicalSquare::draw(cv::Mat& frame) {
    cv::rectangle(frame, getRect(), getColor(), getThickness());
}

void GraphicalSquare::randomizeColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < 3; i++) {
        m_color[i] = dis(gen);
    }
}
void GraphicalSquare::setThickness(int newValue) {
    m_thickness = newValue;
}
cv::Rect GraphicalSquare::getRect() {
    return cv::Rect(m_x, m_y, m_width, m_height);
}
cv::Scalar GraphicalSquare::getColor() { //BGR order
    return {static_cast<double>(m_color[2]),
        static_cast<double>(m_color[1]),
        static_cast<double>(m_color[0])};
}
int GraphicalSquare::getThickness() {
    return m_thickness;
}

