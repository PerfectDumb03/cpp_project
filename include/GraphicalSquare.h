#ifndef GRAPHICALSQUARE_H
#define GRAPHICALSQUARE_H

#include "ShapeSquare.h"
#include <opencv2/imgproc.hpp>

class GraphicalSquare : public ShapeSquare {

public:
    GraphicalSquare(int x, std::array<int,3> color={-1,-1,-1});
    GraphicalSquare(int x, int y, int height=-1, int width=-1, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalSquare(ShapeSquare& square, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalSquare(const cv::Rect& rect, int thickness=2, std::array<int,3> color={0,255,0});
    //~GraphicalSquare() override = default;

    void draw(cv::Mat& frame);

    cv::Rect getRect();

};



#endif //GRAPHICALSQUARE_H
