//
// Created by lucan on 02.07.2025.
//

#ifndef GRAPHICALCIRCLE_H
#define GRAPHICALCIRCLE_H
#include <array>
#include <opencv2/core/mat.hpp>

#include "ShapeCircle.h"


class GraphicalCircle: public ShapeCircle {
private:
    int m_thickness = -1;
    std::array<int,3> m_color;
public:
    GraphicalCircle(int x, int y, int radius, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalCircle(ShapeCircle& circle, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    ~GraphicalCircle() = default;

    void draw(cv::Mat& frame);

    cv::Scalar getColor();
    cv::Point  getCenter();
    int getThickness();
    int getRadius();
    int getX();
    int getY();
};



#endif //GRAPHICALCIRCLE_H
