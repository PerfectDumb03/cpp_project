//
// Created by Luca on 01.07.2025.
//

#include "../include/GraphicalSquare.h"


GraphicalSquare::GraphicalSquare(int x, int y, int height, int width, int thickness, std::array<int, 3> color)
    :ShapeSquare(x, y, height, width, thickness, color){
}
GraphicalSquare::GraphicalSquare(ShapeSquare &square, int thickness, std::array<int, 3> color)
    :ShapeSquare(square.getX(), square.getY(), square.getHeight(), square.getWidth(), thickness, color){
}
GraphicalSquare::GraphicalSquare(const cv::Rect &rect, int thickness, std::array<int, 3> color)
:ShapeSquare(rect.x, rect.y, rect.height, rect.width, thickness, color){}

GraphicalSquare::GraphicalSquare(int x, std::array<int, 3> color)
    :ShapeSquare(x, 0, -1, -1, -1, color){}


void GraphicalSquare::draw(cv::Mat& frame) {
    cv::rectangle(frame, getRect(), getColor(), getThickness());
}

cv::Rect GraphicalSquare::getRect() {
    return {m_x, m_y, m_width, m_height};
}
