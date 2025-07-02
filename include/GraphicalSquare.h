//
// Created by Luca on 01.07.2025.
//

#ifndef GRAPHICALSQUARE_H
#define GRAPHICALSQUARE_H
#include "ShapeSquare.h"
#include <array>
#include <random>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>




class GraphicalSquare : public ShapeSquare {
protected:
    int m_thickness = -1;
    std::array<int,3> m_color; // Pointer to RGB color values
public:
    GraphicalSquare(int x, int y, int height, int width, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalSquare(ShapeSquare& square, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalSquare(const cv::Rect& rect);
    ~GraphicalSquare() override = default;

    void draw(cv::Mat& frame);

    void randomizeColor();
    void setThickness(int newValue);

    cv::Rect getRect();
    cv::Scalar getColor();
    int getThickness();

};



#endif //GRAPHICALSQUARE_H
